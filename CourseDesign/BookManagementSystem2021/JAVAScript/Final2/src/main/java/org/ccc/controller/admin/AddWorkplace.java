package org.ccc.controller.admin;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.WorkplaceDao;
import org.ccc.dao.WorkplaceDaoImpl;
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

@WebServlet("/AddWorkplace")
public class AddWorkplace extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        String workplace_name = request.getParameter("workplace_name");
        String linkman = request.getParameter("linkman");
        String telephone = request.getParameter("telephone");
        String e_mail = request.getParameter("e_mail");
        String address = request.getParameter("address");
        String character = request.getParameter("character");

        if(workplace_name.isEmpty() || "".equals(linkman) || telephone.isEmpty() || e_mail.isEmpty() || address.isEmpty() || character.isEmpty())
        {
            response.getWriter().write("<script language=javascript>alert('提示，信息填写不完整');window.location='/admin/WorkplaceManagement.jsp'</script>");
            return;
        }

        if(telephone.length() != 11 || !telephone.matches("[0-9]+"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，电话号码格式不正确');window.location='/admin/WorkplaceManagement.jsp'</script>");
            return;
        }

        if(!e_mail.contains("@")||!e_mail.contains(".com"))
        {
            response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/admin/WorkplaceManagement.jsp'</script>");
            return;
        }
        else
        {
            String str=e_mail.replace("@", "");
            if(e_mail.length()-str.length()>=2)		//@不能有多个
            {
                response.getWriter().write("<script language=javascript>alert('提示，邮箱格式不正确');window.location='/admin/WorkplaceManagement.jsp'</script>");
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
        int hasWorkplace=0;	//1表示已经有该单位了，0表示没有可以创建
        for(Workplace workplace:workplaces)
        {
            if(workplace.getWorkplace_name().equals(workplace_name))
            {
                hasWorkplace=1;
                break;
            }
        }
        if(hasWorkplace==1)
        {
            response.getWriter().write("<script language=javascript>alert('提示，单位已存在');window.location='/admin/WorkplaceManagement.jsp'</script>");
            return;
        }

        Workplace workplace=new Workplace();
        workplace.setWorkplace_name(workplace_name);
        workplace.setWorkplace_linkman(linkman);
        workplace.setWorkplace_telephone(telephone);
        workplace.setWorkplace_e_mail(e_mail);
        workplace.setWorkplace_address(address);
        workplace.setWorkplace_character(character);

        workplaceDao.addWorkplace(workplace);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/WorkplaceManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
