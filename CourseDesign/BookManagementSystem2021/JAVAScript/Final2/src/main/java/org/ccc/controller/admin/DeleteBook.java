package org.ccc.controller.admin;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.*;
import org.ccc.pojo.Check;
import org.ccc.pojo.Review;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.List;

@WebServlet("/DeleteBook")
public class DeleteBook extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int book_id = Integer.parseInt(request.getParameter("book_id"));

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        //判断图书是否被借阅，被借阅的图书要在归还后，才能被所属单位删除
        ReviewDao reviewDao = new ReviewDaoImpl(sqlSession);
        List<Review> reviews=reviewDao.selectReviewByBookId(book_id);
        CheckDao checkDao=new CheckDaoImpl(sqlSession);
        List<Check> checks=checkDao.selectCheckByBookId(book_id);
        int islending=0;	//1表示借走了未归还
        for(Review review:reviews) {
            if("成功".equals(review.getStatus())) {
                islending=1;
                break;
            }
        }
        for(Check check:checks) {
            if(check.getStatus().equals("成功"))
            {
                islending=1;
                break;
            }
        }


        if(islending==1) {
            response.getWriter().write("<script language=javascript>alert('提示，图书尚未被归还，暂不可删除');window.location='/Final2_war_exploded/admin/BookManagement.jsp'</script>");
            return;
        }


        BookDao bookDao=new BookDaoImpl(sqlSession);
        bookDao.deleteBook(book_id);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/BookManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
