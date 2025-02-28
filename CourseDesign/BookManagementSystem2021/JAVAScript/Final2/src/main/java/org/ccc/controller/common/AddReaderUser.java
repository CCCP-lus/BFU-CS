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
import org.ccc.pojo.User_Role;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Date;
import java.util.List;

@WebServlet("/AddReaderUser")
public class AddReaderUser extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException
    {
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String password2 = request.getParameter("password2");
        String real_name = request.getParameter("real_name");
        String sex = request.getParameter("sex");
        String phone = request.getParameter("phone");
        String e_mail = request.getParameter("e_mail");
        String address = request.getParameter("address");
        String photo = request.getParameter("photo");

        // 不合法输入的判定
        if(username.isEmpty() || password.isEmpty() || password2.isEmpty() || real_name.isEmpty() || sex.isEmpty() || phone.isEmpty() || e_mail.isEmpty() || address.isEmpty() || photo.isEmpty())
        {
            response.getWriter().write("<script language=javascript>alert('提示，信息不全请填写完善');window.location='/Final2_war_exploded/register.jsp'</script>");
            return;
        }
        else if(!password.equals(password2))
        {
            response.getWriter().write("<script language=javascript>alert('提示，两次密码输入不同');window.location='/Final2_war_exploded/register.jsp'</script>");
            return;
        }
        if(phone.length()!=11||!phone.matches("[0-9]+"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，电话号码包含非数字字符');window.location='/Final2_war_exploded/register.jsp'</script>");
            return;
        }
        if(!e_mail.contains("@")||!e_mail.contains(".com"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/Final2_war_exploded/register.jsp'</script>");
            return;
        }
        else
        {
            // 多个@的情况判定
            String str = e_mail.replace("@", "");
            if(e_mail.length() - str.length() >= 2)
            {
                response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/Final2_war_exploded/register.jsp'</script>");
                return;
            }
        }

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        UserDao userDao=new UserDaoImpl(sqlSession);

        List<String> usernames = userDao.selectAllUsername();
        int sameusername=0; //0表示数据库中没有该用户名，1表示有重复
        for(String myusername:usernames)
        {
            if(myusername.equals(username))
            {
                sameusername=1;
                break;
            }
        }
        if(sameusername==1)
        {
            response.getWriter().write("<script language=javascript>alert('提示，请更换用户名！');window.location='/Final2_war_exploded/register.jsp'</script>");
            return;
        }

        photo = "Final2_war_exploded/headportrait/" + photo;

        // 添加用户
        User u=new User();
        u.setUsername(username);
        u.setPassword(password);
        u.setReal_name(real_name);
        u.setPhone(phone);
        u.setE_mail(e_mail);
        u.setAddress(address);
        u.setWork_no(null);
        u.setIs_register("y");
        Date now=new Date();
        u.setCreate_time(now);
        u.setSex(sex);
        u.setPhoto(photo);
        u.setSituation("离线");
        u.setLast_time(now);
        u.setWorkplace_name(null);
        userDao.addUser(u);

        User u2=userDao.selectUserByUserName(username);

        User_Role user_role=new User_Role();
        user_role.setUser_id(u2.getUser_id());
        user_role.setRole_id(3);
        UserRoleDao userroleDao=new UserRoleDaoImpl(sqlSession);
        int flag = userroleDao.addOneUserRole(user_role);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        response.sendRedirect("/Final2_war_exploded/login.jsp");
    }
}
