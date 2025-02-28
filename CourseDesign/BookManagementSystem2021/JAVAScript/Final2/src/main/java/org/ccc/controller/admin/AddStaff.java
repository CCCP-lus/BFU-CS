package org.ccc.controller.admin;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.*;
import org.ccc.pojo.User;
import org.ccc.pojo.User_Role;
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
import java.util.Date;
import java.util.List;

@WebServlet("/AddStaff")
public class AddStaff extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        String work_no = request.getParameter("worknumber");
        String real_name = request.getParameter("realname");
        String sex = request.getParameter("sex");
        String phone = request.getParameter("phonenumber");
        String e_mail = request.getParameter("email");
        String address = request.getParameter("address");
        String workplace_name = request.getParameter("workplacename");
        String photo = request.getParameter("hportrait");

        // 信息有空
        if(work_no.isEmpty() || real_name.isEmpty() || sex.isEmpty() || phone.isEmpty() || e_mail.isEmpty() || address.isEmpty() || workplace_name.isEmpty() || photo.isEmpty())
        {
            response.getWriter().write("<script language=javascript>alert('提示，信息不全请填写完善');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }
        //设定工号大于4位
        else if(work_no.length()<=4)
        {
            response.getWriter().write("<script language=javascript>alert('提示，要求工号大于4位');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }
        //电话号码必须11位，且全为数字
        if(phone.length()!=11||!phone.matches("[0-9]+"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，电话号码格式不正确');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }
        //email必须包含@和.com
        if(!e_mail.contains("@")||!e_mail.contains(".com"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }
        //email只能有一个@
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

        UserDao userDao=new UserDaoImpl(sqlSession);
        List<String> worknumbers=userDao.selectAllWorkNumber();
        int sameWorknumber=0;	//0表示无重复工号，1表示有重复
        for(String myworknumber:worknumbers) {
            if(myworknumber==null)continue;
            if(myworknumber.equals(work_no)) {
                sameWorknumber=1;
                break;
            }
        }
        //工号重复
        if(sameWorknumber==1) {
            response.getWriter().write("<script language=javascript>alert('提示，工号重复！');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }

        WorkplaceDao workplaceDao=new WorkplaceDaoImpl(sqlSession);
        List<Workplace> workplaces=workplaceDao.selectAllWorkplace();
        int hasWorkplace=0; //0表示不存在该单位，1表示有该单位
        for(Workplace myworkplace:workplaces) {
            if(myworkplace.getWorkplace_name().equals(workplace_name)) {
                hasWorkplace=1;
                break;
            }
        }
        //单位不存在
        if(hasWorkplace==0) {
            response.getWriter().write("<script language=javascript>alert('提示，不存在指派的单位！');window.location='/Final2_war_exploded/admin/UserManagement.jsp'</script>");
            return;
        }

        String username=work_no;
        String password=work_no.substring(work_no.length()-4);
        photo = "/Final2_war_exploded/headportrait/" + photo;

        User u=new User();
        u.setUsername(username);
        u.setPassword(password);
        u.setReal_name(real_name);
        u.setPhone(phone);
        u.setE_mail(e_mail);
        u.setAddress(address);
        u.setWork_no(work_no);
        u.setIs_register("y");
        Date now=new Date();
        u.setCreate_time(now);
        u.setSex(sex);
        u.setPhoto(photo);
        u.setSituation("离线");
        u.setLast_time(now);
        u.setWorkplace_name(workplace_name);
        userDao.addUser(u);

        User u2=userDao.selectUserByUserName(username);

        User_Role user_role=new User_Role();
        user_role.setUser_id(u2.getUser_id());
        user_role.setRole_id(2);
        UserRoleDao userroleDao=new UserRoleDaoImpl(sqlSession);
        userroleDao.addOneUserRole(user_role);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/UserManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
