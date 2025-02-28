package org.ccc.controller.common;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.UserDao;
import org.ccc.dao.UserDaoImpl;
import org.ccc.pojo.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.InputStream;
import java.util.Date;

@WebServlet("/GetLogout")
public class GetLogout extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        // 禁止缓存
        response.setHeader("Cache-Control", "no-cache, no-store, must-revalidate"); // HTTP 1.1.
        response.setHeader("Pragma", "no-cache"); // HTTP 1.0.
        response.setDateHeader("Expires", 0); // Proxies.

        HttpSession session=request.getSession();
        Date lastlogin=(Date)session.getAttribute("lastlogin");
        User u=(User)session.getAttribute("userbean");
        u.setSituation("离线");
        u.setLast_time(lastlogin);

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();
        UserDao userDao=new UserDaoImpl(sqlSession);
        userDao.updateUser(u);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        // 退出时移除当前用户的session
        System.out.println(session.getAttribute("userbean"));
        session.removeAttribute("userbean");

        // 禁止使用浏览器回退按钮，重定向至登录页
        response.getWriter().write("<script language=javascript>window.history.forward(1);</script>");
        response.getWriter().write("<script language=javascript>window.location='/Final2_war_exploded/login.jsp'</script>");

    }
}
