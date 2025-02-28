package org.ccc.controller.common;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.UserDao;
import org.ccc.dao.UserDaoImpl;
import org.ccc.dao.UserRoleDao;
import org.ccc.dao.UserRoleDaoImpl;
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
import java.util.Date;

@WebServlet("/GetLogin")
public class GetLogin extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        String username=request.getParameter("username");
        String password=request.getParameter("password");

        UserDao userDao;
        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        userDao = new UserDaoImpl(sqlSession);
        User u = userDao.selectUserByUserName(username);
        String forwardUrl=null;

        System.out.println(username + " " + password);

        if(u != null && u.getUsername().equals(username) && u.getPassword().equals(password))
        {

            System.out.println("读取的用户名：" + u.getUsername());
            System.out.println("读取的密码：" + u.getPassword());

            System.out.println("实际的用户名：" + username);
            System.out.println("实际的密码：" + password);

            u.setSituation("在线");
            userDao.updateUser(u);
            HttpSession session=request.getSession();
            Date now=new Date();
            session.setAttribute("lastlogin", now);	//存上次登录时间，在退出时更新数据库
            session.setAttribute("userbean", u);	//存当前用户
            UserRoleDao userroleDao=new UserRoleDaoImpl(sqlSession);
            int roleid=userroleDao.selectRoleIdByUserId(u.getUser_id());
            if(roleid==1)
            {
                forwardUrl="/admin/BookManagement.jsp";
            }
            else if(roleid==2)
            {
                forwardUrl="/staff/BookManagement.jsp";
            }
            else if(roleid==3)
            {
                forwardUrl="/reader/reader_index.jsp";
            }
        }
        else
        {
            response.getWriter().write("<script language=javascript>alert('提示，用户名或密码错误');window.location='/Final2_war_exploded/login.jsp'</script>");
            return;
        }

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        RequestDispatcher dispatcher= request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
