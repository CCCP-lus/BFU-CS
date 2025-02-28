package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.*;
import org.ccc.pojo.Check;
import org.ccc.pojo.Circulate;
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
import java.util.Date;
import java.util.List;

@WebServlet("/AgreeUserLending")
public class AgreeUserLending extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        
        int checkid = Integer.parseInt(request.getParameter("checkid"));
        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        Date now=new Date();

        CheckDao checkDao=new CheckDaoImpl(sqlSession);
        //获取该记录
        Check check=checkDao.selectCheckByCheckId(checkid);
        //更新该记录
        check.setStatus("成功");
        checkDao.updateCheck(check);

        //该请求成功后，把其他单位借阅同一个标本的请求都变成拒绝
        List<Check> checks=checkDao.selectAllCheck();
        for(Check mycheck:checks) {
            if(mycheck.getBook_id()==check.getBook_id()&&mycheck.getStatus().equals("请求")) {
                mycheck.setStatus("拒绝");
                checkDao.updateCheck(mycheck);
            }
        }

        WorkplaceDao workplaceDao = new WorkplaceDaoImpl(sqlSession);
        List<Workplace> workplaces = workplaceDao.selectAllWorkplace();

        String target = check.getWorkplace_name();
        int index = 0;
        for(Workplace workplace : workplaces)
        {
            if(workplace.getWorkplace_name().equals(target))
                index = workplace.getWorkplace_id();
        }

        //获取对方单位的同意后，将借阅信息录入借阅表
        UserDao userDao=new UserDaoImpl(sqlSession);
        User user=userDao.selectUserByUserId(check.getUser_id());

        Circulate circulate = new Circulate();
        circulate.setBook_id(check.getBook_id());
        circulate.setWorkplace_id(String.valueOf(index));
        circulate.setUser_id(check.getUser_id());
        circulate.setCirculate_time(now);
        circulate.setReturn_time(null);
        circulate.setCirculate_reason(check.getReason());
        circulate.setUser_id(user.getUser_id());
        circulate.setApplicant_phone(user.getPhone());
        circulate.setRemarks(check.getNotes());

        CirculateDao circulateDao = new CirculateDaoImpl(sqlSession);
        circulateDao.addOneCirculate(circulate);

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookChecking.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);
    }
}
