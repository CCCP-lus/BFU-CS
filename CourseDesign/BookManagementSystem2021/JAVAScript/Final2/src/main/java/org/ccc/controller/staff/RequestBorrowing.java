package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.ReviewDao;
import org.ccc.dao.ReviewDaoImpl;
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
import java.util.Date;

@WebServlet("/RequestBorrowing")
public class RequestBorrowing extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        
        //图书id，借阅人的用户id，图书所在的单位名，借阅状态
        int bookid=Integer.parseInt(request.getParameter("bookid"));
        int userid=Integer.parseInt(request.getParameter("userid"));
        String workplaceName = request.getParameter("workplacename");
        //status分请求，成功，请求归还，归还，拒绝，该处是请求
        String status=request.getParameter("status");
        String reason=request.getParameter("reason");
        String notes=request.getParameter("notes");

        Date now=new Date();

        Review review=new Review();
        review.setBook_id(bookid);
        review.setUser_id(userid);
        review.setWorkplace_name(workplaceName);
        review.setStatus(status);
        review.setReason(reason);
        review.setNotes(notes);
        review.setNow_time(now);

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        ReviewDao reviewDao=new ReviewDaoImpl(sqlSession);
        reviewDao.addReview(review);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookBorrowing.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
