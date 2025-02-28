package org.ccc.controller.common;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.UserDao;
import org.ccc.dao.UserDaoImpl;
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

@WebServlet("/ModifyInfo")
public class ModifyInfo extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        String real_name = request.getParameter("real_name");
        String sex = request.getParameter("sex");
        String phone = request.getParameter("phone");
        String e_mail = request.getParameter("e_mail");
        String address = request.getParameter("address");
        String photo = request.getParameter("photo");
        HttpSession session = request.getSession();
        User u = (User)session.getAttribute("userbean");


        if(real_name.isEmpty())
        {
            real_name = u.getReal_name();
        }
        if(sex.isEmpty())
        {
            sex = u.getSex();
        }
        if(phone.isEmpty())
        {
            phone = u.getPhone();
        }
        if(e_mail.isEmpty())
        {
            e_mail = u.getE_mail();
        }
        if(address.isEmpty())
        {
            address = u.getAddress();
        }
        if(photo.isEmpty())
        {
            photo = u.getPhoto();
        }
        else
        {
            photo = "Final2_war_exploded/headportrait/" + photo;
        }

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


        u.setReal_name(real_name);
        u.setSex(sex);
        u.setPhone(phone);
        u.setE_mail(e_mail);
        u.setAddress(address);
        u.setPhoto(photo);
        session.removeAttribute("userbean");
        session.setAttribute("userbean", u);


        userDao.updateUser(u);

        String forwardUrl="/info.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();
    }
}
