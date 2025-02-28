package org.ccc.controller.staff;

import java.io.IOException;
import java.io.InputStream;
import java.util.Date;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.*;
import org.ccc.pojo.Borrow;
import org.ccc.pojo.Review;
import org.ccc.pojo.User;

@WebServlet("/AgreeReturn")
public class AgreeReturn extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int reviewid=Integer.parseInt(request.getParameter("reviewid"));

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        ReviewDao reviewDao=new ReviewDaoImpl(sqlSession);
        //获取该记录
        Review review=reviewDao.selectReviewByReviewId(reviewid);
        //更新该记录
        review.setStatus("归还");
        reviewDao.updateReview(review);
        Date nowtime=new Date();

        //更新borrow表中，该记录的归还时间
        BorrowDao borrowDao=new BorrowDaoImpl(sqlSession);
        List<Borrow> borrows=borrowDao.selectAllBorrow();
        for(Borrow borrow:borrows) {
            if(borrow.getBook_id()==review.getBook_id()&&borrow.getReturn_time()==null) {
                Date now=new Date();
                borrow.setReturn_time(now);
                borrowDao.updateBorrow(borrow);
                break;
            }
        }

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookLending.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);
    }
}
