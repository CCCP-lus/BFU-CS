package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.CirculateDao;
import org.ccc.dao.CirculateDaoImpl;
import org.ccc.dao.CheckDao;
import org.ccc.dao.CheckDaoImpl;
import org.ccc.pojo.Circulate;
import org.ccc.pojo.Check;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.util.Date;
import java.util.Hashtable;
import java.util.List;

@WebServlet("/AgreeUserReturn")
public class AgreeUserReturn extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        int checkid=Integer.parseInt(request.getParameter("checkid"));

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        CheckDao checkDao=new CheckDaoImpl(sqlSession);
        //获取该记录
        Check check=checkDao.selectCheckByCheckId(checkid);
        //更新该记录
        Date nowtime=new Date();
        //check.setNowtime(nowtime);
        check.setStatus("归还");
        checkDao.updateCheck(check);

        //更新circulate表中，该记录的归还时间
        CirculateDao circulateDao=new CirculateDaoImpl(sqlSession);
        List<Circulate> circulates=circulateDao.selectAllCirculate();
        for(Circulate circulate:circulates) {
            if(circulate.getBook_id()==check.getBook_id()&&circulate.getReturn_time()==null) {
                Date now=new Date();
                circulate.setReturn_time(now);
                circulateDao.updateCirculate(circulate);
                break;
            }
        }

        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookLending.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);
    }
}
