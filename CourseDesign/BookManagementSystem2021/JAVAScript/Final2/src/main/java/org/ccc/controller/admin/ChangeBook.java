package org.ccc.controller.admin;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.BookDao;
import org.ccc.dao.BookDaoImpl;
import org.ccc.pojo.Book;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

@WebServlet("/ChangeBook")
public class ChangeBook extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int book_id = Integer.parseInt(request.getParameter("updatesid3"));
        String book_name = request.getParameter("book_name3");
        String author = request.getParameter("author3");
        String publisher = request.getParameter("publisher3");
        String publish_time = request.getParameter("publish_time3");
        String category = request.getParameter("category3");
        String page_number = request.getParameter("page_number3");
        String price = request.getParameter("price3");
        String picturepath = request.getParameter("picturepath3");
        String privilege = request.getParameter("privilege3");

        if(!FormatValidity(publish_time))
        {
            response.getWriter().write("<script language=javascript>alert('提示，时间格式不合法(yyyy-MM-dd)');window.location='/admin/BookManagement.jsp'</script>");
            return;
        }
        if(!NotExceedCurrentTime(publish_time))
        {
            response.getWriter().write("<script language=javascript>alert('提示，日期超过今天');window.location='/admin/BookManagement.jsp'</script>");
            return;
        }

        Date datepubishtime=null;
        try {
            datepubishtime= new Date(new SimpleDateFormat("yyyy-MM-dd").parse(publish_time).getTime());
        } catch (ParseException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        Book book = new Book();
        book.setBook_id(book_id);
        book.setBook_name(book_name);
        book.setAuthor(author);
        book.setPublisher(publisher);
        book.setPublish_time(datepubishtime);
        book.setCategory(category);
        book.setPage_number(Integer.parseInt(page_number));
        book.setPrice(Double.parseDouble(price));
        book.setPicture(picturepath);
        book.setPrivilege(privilege);

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        BookDao bookDao=new BookDaoImpl(sqlSession);

        bookDao.updateBookByBookId(book);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/BookManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }


    //时间格式YYYY-mm-dd合法
    public boolean FormatValidity(String time) {
        if(time.length()!=10) return false;
        else {
            if(!time.substring(0,4).matches("[0-9]+")||!time.substring(5,7).matches("[0-9]+")||!time.substring(8,10).matches("[0-9]+")) return false;
            else if(!time.substring(4,5).equals("-")||!time.substring(7,8).equals("-")) return false;
        }
        return true;
    }

    //时间不能超过当前时间
    public boolean NotExceedCurrentTime(String time) {
        Date date=new Date();
        SimpleDateFormat dateFormat= new SimpleDateFormat("yyyy-MM-dd");
        String nowdate=dateFormat.format(date);
        int nowyear=Integer.parseInt(nowdate.substring(0,4));
        int nowmonth=Integer.parseInt(nowdate.substring(5,7));
        int nowday=Integer.parseInt(nowdate.substring(8,10));
        int thatyear=Integer.parseInt(time.substring(0,4));
        int thatmonth=Integer.parseInt(time.substring(5,7));
        int thatday=Integer.parseInt(time.substring(8,10));

        if(nowyear<thatyear) return false;
        else if(nowyear==thatyear) {
            if(nowmonth<thatmonth) return false;
            else if(nowmonth==thatmonth) {
                if(nowday<thatday) return false;
            }
        }
        return true;
    }
}
