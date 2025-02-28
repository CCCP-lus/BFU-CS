package org.ccc.controller.admin;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.UserDao;
import org.ccc.dao.UserDaoImpl;
import org.ccc.dao.WorkplaceDao;
import org.ccc.dao.WorkplaceDaoImpl;
import org.ccc.pojo.User;
import org.ccc.pojo.Workplace;

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

@WebServlet("/ChangeUser")
public class ChangeUser extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int user_id = Integer.parseInt(request.getParameter("updateuid"));
//        String work_no = request.getParameter("worknumber");
        String real_name = request.getParameter("realname");
        String sex = request.getParameter("sex");
        String phone = request.getParameter("phonenumber");
        String e_mail = request.getParameter("email");
        String address = request.getParameter("address");
        String workplace_name = request.getParameter("workplacename");
//        String photo = request.getParameter("hportrait");

        if(real_name.isEmpty() || sex.isEmpty() || phone.isEmpty() || e_mail.isEmpty() || address.isEmpty() || workplace_name.isEmpty())
        {
            response.getWriter().write("<script language=javascript>alert('提示，信息不全请填写完善');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }

        if(phone.length()!=11||!phone.matches("[0-9]+"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，电话号码格式不正确');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }

        if(!e_mail.contains("@")||!e_mail.contains(".com"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }
        else {
            String str=e_mail.replace("@", "");
            if(e_mail.length()-str.length()>=2)		//@不能有多个
            {
                response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
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

        WorkplaceDao workplaceDao=new WorkplaceDaoImpl(sqlSession);
        List<Workplace> workplaces=workplaceDao.selectAllWorkplace();
        int hasWorkplacename=0;	//0表示workplace表中无该单位名，1表示有
        for(Workplace myworkplace:workplaces) {
            if(myworkplace.getWorkplace_name().equals(workplace_name)) {
                hasWorkplacename=1;
                break;
            }
        }
        if(hasWorkplacename==0) {
            response.getWriter().write("<script language=javascript>alert('提示，不存在指派的单位！');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }

        User u=new User();
        u.setUser_id(user_id);
        u.setReal_name(real_name);
        u.setSex(sex);
        u.setPhone(phone);
        u.setAddress(address);
        u.setE_mail(e_mail);
        u.setWorkplace_name(workplace_name);

        UserDao userDao=new UserDaoImpl(sqlSession);

        userDao.updateUserByUserId(u);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/UserManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);
    }
}
