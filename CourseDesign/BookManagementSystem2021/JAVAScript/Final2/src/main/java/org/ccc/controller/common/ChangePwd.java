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
import java.io.UnsupportedEncodingException;

@WebServlet("/ChangePwd")
public class ChangePwd extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, UnsupportedEncodingException
    {
        // TODO Auto-generated method stub
        HttpSession session=request.getSession();
        request.setCharacterEncoding("utf-8");

        User u=(User)session.getAttribute("userbean");
        response.setContentType("text/html;charset=utf-8");

        String oldpwd = request.getParameter("oldpwd");
        String newpwd = request.getParameter("newpwd");
        String configpwd = request.getParameter("configpwd");

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();
        UserRoleDao userroleDao=new UserRoleDaoImpl(sqlSession);
        int roleid = userroleDao.selectRoleIdByUserId(u.getUser_id());

        // 情况一：信息不全
        if(oldpwd.isEmpty() || newpwd.isEmpty() || configpwd.isEmpty())
        {
            if(roleid==1)
            {
                response.getWriter().write("<script language=javascript>alert('提示，密码不可为空');window.location='/Final2_war_exploded/admin/BookManagement.jsp'</script>");
            }
            else if(roleid==2)
            {
                response.getWriter().write("<script language=javascript>alert('提示，密码不可为空');window.location='/Final2_war_exploded/staff/BookManagement.jsp'</script>");
            }
            else if(roleid==3)
            {
                response.getWriter().write("<script language=javascript>alert('提示，密码不可为空');window.location='/Final2_war_exploded/reader/reader_index.jsp'</script>");
            }
            return;
        }

        // 情况二：原密码验证不通过
        if(!oldpwd.equals(u.getPassword()))
        {
            if(roleid==1)
            {
                response.getWriter().write("<script language=javascript>alert('提示，原密码错误');window.location='/Final2_war_exploded/admin/BookManagement.jsp'</script>");
            }
            else if(roleid==2)
            {
                response.getWriter().write("<script language=javascript>alert('提示，原密码错误');window.location='/Final2_war_exploded/staff/BookManagement.jsp'</script>");
            }
            else if(roleid==3)
            {
                response.getWriter().write("<script language=javascript>alert('提示，原密码错误');window.location='/Final2_war_exploded/reader/reader_index.jsp'</script>");
            }
            return;
        }

        // 情况三：两次密码不同
        if(!newpwd.equals(configpwd))
        {
            if(roleid==1)
            {
                response.getWriter().write("<script language=javascript>alert('提示，两次输入密码不同');window.location='/Final2_war_exploded/admin/BookManagement.jsp'</script>");
            }
            else if(roleid==2)
            {
                response.getWriter().write("<script language=javascript>alert('提示，两次输入密码不同');window.location='/Final2_war_exploded/staff/BookManagement.jsp'</script>");
            }
            else if(roleid==3)
            {
                response.getWriter().write("<script language=javascript>alert('提示，两次输入密码不同');window.location='/Final2_war_exploded/reader/reader_index.jsp'</script>");
            }
            return;
        }

        u.setPassword(newpwd);

        session.removeAttribute("userbean");
        session.setAttribute("userbean", u);

        UserDao userDao=new UserDaoImpl(sqlSession);
        userDao.updateUser(u);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl=null;
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

        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
