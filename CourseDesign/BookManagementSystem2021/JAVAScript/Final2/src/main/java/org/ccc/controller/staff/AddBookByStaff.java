package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.BookDao;
import org.ccc.dao.BookDaoImpl;
import org.ccc.pojo.Book;
import org.ccc.pojo.User;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.InputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

@WebServlet("/AddBookByStaff")
public class AddBookByStaff extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        String book_name = request.getParameter("book_name");
        String author = request.getParameter("author");
        String publisher = request.getParameter("publisher");
        String publish_time = request.getParameter("publish_time");
        String category = request.getParameter("category");
        String page_number = request.getParameter("page_number");
        String price = request.getParameter("price");
        String picturepath = request.getParameter("picturepath");
        String privilege = request.getParameter("privilege");

        if(book_name.isEmpty() || author.isEmpty() || publisher.isEmpty() || publish_time.isEmpty() || category.isEmpty() || page_number.isEmpty() || price.isEmpty() || picturepath.isEmpty() || privilege.isEmpty())
        {
            response.getWriter().write("<script language=javascript>alert('提示，信息不全请填写完善');window.location='/staff/BookManagement.jsp'</script>");
            return;
        }
        if(!FormatValidity(publish_time))
        {
            response.getWriter().write("<script language=javascript>alert('提示，时间格式不合法(yyyy-MM-dd)');window.location='/staff/BookManagement.jsp'</script>");
            return;
        }
        if(!NotExceedCurrentTime(publish_time))
        {
            response.getWriter().write("<script language=javascript>alert('提示，日期不能超过今天');window.location='/staff/BookManagement.jsp'</script>");
            return;
        }

        HttpSession session=request.getSession();
        User u=(User)session.getAttribute("userbean");
        String enteredby=u.getUsername();
        String workplacename=u.getWorkplace_name();
        Date enteringtime=new Date();

        Date dateunearthedtime=null;
        try {
            dateunearthedtime= new Date(new SimpleDateFormat("yyyy-MM-dd").parse(publish_time).getTime());
        } catch (ParseException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        picturepath = "Final2_war_exploded/book_picture/" + picturepath;

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        BookDao bookDao=new BookDaoImpl(sqlSession);

        Book book = new Book();
        book.setBook_name(book_name);
        book.setAuthor(author);
        book.setPublisher(publisher);
        book.setPublish_time(dateunearthedtime);
        book.setCategory(category);
        book.setPage_number(Integer.parseInt(page_number));
        book.setPrice(Double.parseDouble(price));
        book.setPicture(picturepath);
        book.setPrivilege(privilege);

        int hasSame=0;	//数据库有除了id之外完全相同的信息
        List<Book> books = bookDao.selectAllBook();
        for(Book mybook:books)
        {
            if(allEquals(mybook,book))
            {
                hasSame=1;
                break;
            }
        }

        if(hasSame==1) {
            response.getWriter().write("<script language=javascript>alert('提示，已存在相同图书，添加失败');window.location='/staff/BookManagement.jsp'</script>");
            return;
        }

        book.setEnter_by(u.getUsername());
        bookDao.addBook(book);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookManagement.jsp";
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

    // 除了ID全部相同视为同一本书
    public boolean allEquals(Book book1, Book book2)
    {
        if (book1.getBook_name().equals(book2.getBook_name()))
        {
            if (book1.getAuthor().equals(book2.getAuthor()))
            {
                if (book1.getPublisher().equals(book2.getPublisher()))
                {
                    if (book1.getPublish_time().equals(book2.getPublish_time()))
                    {
                        if (book1.getCategory().equals(book2.getCategory())) {
                            if (book1.getPage_number() == book2.getPage_number())
                            {
                                if (book1.getPrice() == book2.getPrice())
                                {
                                    if (book1.getPicture().equals(book2.getPicture()))
                                    {
                                        return book1.getPrivilege().equals(book2.getPrivilege());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
}
