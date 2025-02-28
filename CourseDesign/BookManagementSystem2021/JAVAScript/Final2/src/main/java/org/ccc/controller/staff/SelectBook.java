package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.BookDao;
import org.ccc.dao.BookDaoImpl;
import org.ccc.dao.UserDao;
import org.ccc.dao.UserDaoImpl;
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
import java.util.ArrayList;
import java.util.List;

@WebServlet("/SelectBook")
public class SelectBook extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=UTF-8");
        request.setCharacterEncoding("utf-8");

        String selectby = request.getParameter("selectby");
        String searchBook = request.getParameter("searchBook");

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        BookDao bookDao=new BookDaoImpl(sqlSession);
        List<Book> books=null;

        if(selectby.equals("byname"))
        {
            books=bookDao.fuzzyQueryByBookName(searchBook);
        }
        else if(selectby.equals("byauthor"))
        {
            books=bookDao.fuzzyQueryByAuthor(searchBook);
        }
        else if(selectby.equals("byid"))
        {
            books=bookDao.fuzzyQueryById(searchBook);
        }
        else if (selectby.equals("bypublisher"))
        {
            books=bookDao.fuzzyQueryByPublisher(searchBook);
        }
//        else
//        {
//            books=new ArrayList<>();
//            UserDao userDao=new UserDaoImpl(sqlSession);
//            List<String> enteredbys=userDao.fuzzyQueryUsernameByWorkplacename(searchBook);	//模糊查询单位，对应的用户名
//            for(String myenteredby:enteredbys)
//            {		//根据对应的所有用户，查询book
//                List<Book> selectBooks=bookDao.selectBookByEnteredby(myenteredby);
//                for(Book mybook:selectBooks)
//                    books.add(mybook);
//            }
//        }
        request.setAttribute("books", books);
        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);
    }
}
