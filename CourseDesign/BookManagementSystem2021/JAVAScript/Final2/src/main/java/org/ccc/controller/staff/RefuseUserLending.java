package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.CheckDao;
import org.ccc.dao.CheckDaoImpl;
import org.ccc.pojo.Check;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;

@WebServlet("/RefuseUserLending")
public class RefuseUserLending extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int checkid=Integer.parseInt(request.getParameter("checkid"));
        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        CheckDao checkDao = new CheckDaoImpl(sqlSession);
        Check check = checkDao.selectCheckByCheckId(checkid);

        // 更新记录
        check.setStatus("拒绝");
        checkDao.updateCheck(check);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookChecking.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);
    }
}
