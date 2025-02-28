package org.ccc.controller.admin;

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
import java.io.UnsupportedEncodingException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

@WebServlet("/AddBook")
public class AddBook extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException {
        // doPost方法用于处理HTTP POST请求，接收HttpServletRequest和HttpServletResponse类型参数，并返回void类型
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        // 设置响应内容类型为text/html，字符集为utf-8

        request.setCharacterEncoding("utf-8");
        // 设置请求字符集为utf-8

        String book_name = request.getParameter("book_name");
        // 获取book_name参数的值，并赋给book_name变量

        String author = request.getParameter("author");
        // 获取author参数的值，并赋给author变量

        String publisher = request.getParameter("publisher");
        // 获取publisher参数的值，并赋给publisher变量

        String publish_time = request.getParameter("publish_time");
        // 获取publish_time参数的值，并赋给publish_time变量

        String category = request.getParameter("category");
        // 获取category参数的值，并赋给category变量

        String page_number = request.getParameter("page_number");
        // 获取page_number参数的值，并赋给page_number变量

        String price = request.getParameter("price");
        // 获取price参数的值，并赋给price变量

        String picturepath = request.getParameter("picturepath");
        // 获取picturepath参数的值，并赋给picturepath变量

        String privilege = request.getParameter("privilege");
        // 获取privilege参数的值，并赋给privilege变量

        if(book_name.isEmpty() || author.isEmpty() || publisher.isEmpty() || publish_time.isEmpty() || category.isEmpty() || page_number.isEmpty() || price.isEmpty() || picturepath.isEmpty() || privilege.isEmpty())
        {
            // 如果book_name、author、publisher、publish_time、category、page_number、price、picturepath、privilege中任意一个参数为空，则执行以下操作
            response.getWriter().write("<script language=javascript>alert('提示，信息不全请填写完善');window.location='/admin/BookManagement.jsp'</script>");
            // 输出警告信息至响应内容，并跳转至/admin/BookManagement.jsp页面
            return;
            // 返回，结束方法执行
        }

        if(!FormatValidity(publish_time))
        {
            // 如果publish_time参数的格式不合法，则执行以下操作
            response.getWriter().write("<script language=javascript>alert('提示，时间格式不合法(yyyy-MM-dd)');window.location='/admin/BookManagement.jsp'</script>");
            // 输出警告信息至响应内容，并跳转至/admin/BookManagement.jsp页面
            return;
            // 返回，结束方法执行
        }

        if(!NotExceedCurrentTime(publish_time))
        {
            // 如果publish_time参数的日期超过当前日期，则执行以下操作
            response.getWriter().write("<script language=javascript>alert('提示，日期不能超过今天');window.location='/admin/BookManagement.jsp'</script>");
            // 输出警告信息至响应内容，并跳转至/admin/BookManagement.jsp页面
            return;
            // 返回，结束方法执行
        }

        HttpSession session=request.getSession();
        // 获取请求的session对象，并赋给session变量

        User u=(User)session.getAttribute("userbean");
        // 从session中获取userbean属性的值，并赋给u变量

        Date publish_timeD = null;
        try
        {
            // 尝试执行以下操作
            publish_timeD = new Date(new SimpleDateFormat("yyyy-MM-dd").parse(publish_time).getTime());
            // 将publish_time参数转换为yyyy-MM-dd格式的日期，并转换为毫秒值，然后创建一个与该日期相同的Date对象，并赋给publish_timeD变量
        }
        catch (ParseException e)
        {
            throw new RuntimeException(e);
            // 捕获ParseException异常，并抛出RuntimeException异常
        }

        picturepath = "Final2_war_exploded/headportrait/" + picturepath;
        // 将picturepath参数拼接至"Final2_war_exploded/headportrait/"字符串，并赋给picturepath变量

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 根据配置文件创建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession对象
        sqlSession = ssf.openSession();
        // 打开sqlSession

        BookDao bookDao=new BookDaoImpl(sqlSession);
        // 根据sqlSession创建BookDao对象，并赋给bookDao变量

        Book book = new Book();
        // 创建Book对象，并赋给book变量

        book.setBook_name(book_name);
        // 将book_name参数的值设置给book的book_name属性

        book.setAuthor(author);
        // 将author参数的值设置给book的author属性

        book.setPublisher(publisher);
        // 将publisher参数的值设置给book的publisher属性

        book.setPublish_time(publish_timeD);
        // 将publish_timeD参数的值设置给book的publish_time属性

        book.setCategory(category);
        // 将category参数的值设置给book的category属性

        book.setPage_number(Integer.parseInt(page_number));
        // 将page_number参数的值转换为整数类型，并设置给book的page_number属性

        book.setPrice(Double.parseDouble(price));
        // 将price参数的值转换为双精度浮点数类型，并设置给book的price属性

        book.setPicture(picturepath);
        // 将picturepath参数的值设置给book的picture属性

        book.setPrivilege(privilege);
        // 将privilege参数的值设置给book的privilege属性

        //数据库有除了id之外完全相同的信息
        int hasSame=0;
        List<Book> books = bookDao.selectAllBook();
        // 获取bookDao对象调用selectAllBook方法获取所有图书信息，并赋给books变量
        for(Book mybook:books)
        {
            // 遍历books列表中的每个Book对象
            if(allEquals(mybook,book))
            {
                // 如果mybook对象与book对象的所有属性都相等，则执行以下操作
                hasSame=1;
                break;
                // 将hasSame变量置为1并跳出循环
            }
        }

        if(hasSame==1)
        {
            // 如果hasSame变量的值为1，则执行以下操作
            response.getWriter().write("<script language=javascript>alert('提示，已存在相同图书，添加失败');window.location='/admin/BookManagement.jsp'</script>");
            // 输出警告信息至响应内容，并跳转至/admin/BookManagement.jsp页面
            return;
            // 返回，结束方法执行
        }

        bookDao.addBook(book);
        // 调用bookDao对象的addBook方法将book对象添加到数据库中

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        // 关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/BookManagement.jsp";
        // 设置forwardUrl变量的值
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        // 获取forwardUrl请求路径的RequestDispatcher对象
        dispatcher.forward(request, response);
        // 调用RequestDispatcher对象的forward方法将请求和响应对象传递给指定的URL
    }

    // 判断时间格式是否合法，格式为YYYY-mm-dd
    public boolean FormatValidity(String time)
    {
        // 判断时间长度是否为10位
        if(time.length()!=10) return false;
        else
        {
            // 判断年、月、日是否为数字
            if(!time.substring(0,4).matches("[0-9]+")||!time.substring(5,7).matches("[0-9]+")||!time.substring(8,10).matches("[0-9]+")) return false;
            // 判断年月日之间是否以"-"连接
            else if(!time.substring(4,5).equals("-")||!time.substring(7,8).equals("-")) return false;
        }
        // 时间格式合法
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

        //判断时间是否在当前年份之前
        if(nowyear<thatyear) return false;
            //如果时间年份和当前年份相同
        else if(nowyear==thatyear) {
            //判断时间是否在当前月份之前
            if(nowmonth<thatmonth) return false;
                //如果时间年份和月份都和当前相同
            else if(nowmonth==thatmonth) {
                //判断时间是否在当前日期之前
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
