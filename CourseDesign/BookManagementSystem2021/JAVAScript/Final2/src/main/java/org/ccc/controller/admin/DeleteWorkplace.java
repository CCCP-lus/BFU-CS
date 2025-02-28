package org.ccc.controller.admin;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.*;
import org.ccc.pojo.Book;
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

@WebServlet("/DeleteWorkplace")
public class DeleteWorkplace extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, IOException, ServletException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int workplaceid=Integer.parseInt(request.getParameter("workplaceid"));

        System.out.println(workplaceid);

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        WorkplaceDao workplaceDao=new WorkplaceDaoImpl(sqlSession);

        //仍有工作人员和图书的单位，不可删除，要先删除工作人员和图书
        int hasUserOrSpecimen=0;

        Workplace workplace=workplaceDao.selectWorkplaceByWorkplaceId(workplaceid);

        UserDao userDao=new UserDaoImpl(sqlSession);
        List<User> users=userDao.selectAllUser();
        for(User user:users) {
            UserRoleDao userRoleDao=new UserRoleDaoImpl(sqlSession);
            int roleid=userRoleDao.selectRoleIdByUserId(user.getUser_id());
            if(roleid==3||roleid==1)
            {
                continue;
            }
            if(user.getWorkplace_name().equals(workplace.getWorkplace_name()))
            {
                hasUserOrSpecimen++;
                break;
            }
        }

        BookDao bookDao=new BookDaoImpl(sqlSession);
        List<Book> books=bookDao.selectAllBook();
        for(Book book:books)
        {
            String publisher=book.getEnter_by();
            User user=userDao.selectUserByUserName(publisher);

            System.out.println(user.getWorkplace_name());
            System.out.println(workplace.getWorkplace_name());

            if(user.getWorkplace_name().equals(workplace.getWorkplace_name()))
            {
                hasUserOrSpecimen++;
                break;
            }
        }

        if(hasUserOrSpecimen>0) {
            response.getWriter().write("<script language=javascript>alert('提示，该单位仍有用户或图书，请先删除用户和图书后，再删除单位');window.location='/admin/WorkplaceManagement.jsp'</script>");
            return;
        }

        workplaceDao.deleteWorkplaceByWorkplaceId(workplaceid);
        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/admin/WorkplaceManagement.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }
}
