package org.ccc.controller.common;

import org.ccc.pojo.User;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.ccc.dao.UserDao;
import org.ccc.dao.UserDaoImpl;

import java.io.UnsupportedEncodingException;
import javax.mail.*;
import javax.mail.internet.MimeMessage;
import javax.mail.internet.MimeUtility;
import javax.mail.internet.InternetAddress;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.InputStream;
//import java.net.PasswordAuthentication;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Properties;


@WebServlet("/SendEmail")
public class SendEmail extends HttpServlet
{
    private static final long serialVersionUID = 1L;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException
    {
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        // 获取到用户名和邮箱名
        String username=new String(request.getParameter("username")); // 将表单中的用户名参数转化为字符串
        String myemail=new String(request.getParameter("myemail")); // 将表单中的邮箱名参数转化为字符串

        System.out.println(username); // 打印用户名

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        UserDao userDao = new UserDaoImpl(sqlSession);
        List<User> users=userDao.selectAllUser(); // 查询所有用户
        int hasUsername=0;   // 默认找不到

        User myuser=null;
        for(User user:users)
        {
            if(user.getUsername().equals(username))
            {
                hasUsername=1;
                myuser=user;
                break;
            }
        }

        if(hasUsername==0) // 如果用户名不存在
        {
            response.getWriter().write("<script language=javascript>alert('提示，用户名不存在');window.location='/Final2_war_exploded/pwd_recovery.jsp'</script>"); // 返回错误提示信息并跳转到密码找回页面
            return;
        }

        if(!myuser.getE_mail().equals(myemail)) // 如果邮箱输入错误
        {
            response.getWriter().write("<script language=javascript>alert('提示，邮箱输入有误');window.location='/Final2_war_exploded/pwd_recovery.jsp'</script>"); // 返回错误提示信息并跳转到密码找回页面
            return;
        }

        // 提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        // 关闭SqlSession
        sqlSession.close();

        String code = generateVerificationCode(); // 生成验证码
        myEmail myEmail = new myEmail(myemail, code); // 构建邮件对象
        try
        {
            myEmail.Send(); // 发送邮件
        }
        catch (MessagingException e)
        {
            throw new RuntimeException(e);
        }

        HttpSession mysession=request.getSession(); // 获取HttpSession
        mysession.setAttribute("checkcode", code); // 设置会话属性为验证码
        mysession.setAttribute("pwd", myuser.getPassword()); // 设置会话属性为密码

        response.getWriter().write("<script language=javascript>window.location='/Final2_war_exploded/verify.jsp'</script>"); // 返回并跳转到验证页面
    }
    
    private String generateVerificationCode()
    {
        String[] beforeShuffle= new String[] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F",
                "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a",
                "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
                "w", "x", "y", "z" };
        // 将数组转换为集合
        List<String> list = Arrays.asList(beforeShuffle);
        // 打乱集合顺序
        Collections.shuffle(list);

        // 转化为字符串
        StringBuilder sb = new StringBuilder();
        for (String s : list)
        {
            sb.append(s);
        }

        return sb.substring(4, 8);
    }
}

class myEmail
{
    private final String emailHost = "smtp.qq.com";       // 发邮件的主机
    private final String transportType = "smtp";          // 邮件发送的协议
    private final String fromUser = "470135239";   // 发件人
    private final String fromEmail = "470135239@qq.com";  // 发件人邮箱
    private final String authCode = "jzrlloxxysmkbggh";   // 发件人邮箱授权码
    private final String subject = "天E阁图书管理系统注册";   // 主体信息
    private String toEmail;                               // 收件人邮箱
    private String verificationCode;                      // 验证码

    public myEmail()
    {
        super();
    }

    public myEmail(String toEmail, String verificationCode)
    {
        this.toEmail = toEmail;
        this.verificationCode = verificationCode;
    }

    public void Send() throws UnsupportedEncodingException, MessagingException
    {
        // 初始化默认参数
        Properties props = new Properties();
        props.setProperty("mail.transport.protocol", transportType);
        props.setProperty("mail.host", emailHost);
        props.setProperty("mail.user", fromUser);
        props.setProperty("mail.from", fromEmail);
        props.put("mail.smtp.port", "465");
        props.put("mail.smtp.ssl.enable", "true");

        // 获取session对象，开启调试信息
        Session session = Session.getInstance(props, new Authenticator()
        {
            @Override
            protected PasswordAuthentication getPasswordAuthentication()
            {
                return new PasswordAuthentication(fromUser, authCode);
            }
        });
        session.setDebug(true);

        System.out.println(session);

        // 通过MimeMessage来创建Message接口的子类
        MimeMessage message = new MimeMessage(session);

        // 发件人信息拼接显示
        String formName = MimeUtility.encodeWord("TianYiGe") + " <" + fromEmail + ">";
        InternetAddress from = new InternetAddress(formName);
        message.setFrom(from);

        // 设置收件人
        InternetAddress to = new InternetAddress(toEmail);
        message.setRecipient(Message.RecipientType.TO, to);

        //设置邮件主题
        message.setSubject(subject);

        //设置邮件内容,使用html格式
        message.setContent("<h1>天E阁</h1>" + "<h1>您的验证码是" + verificationCode + "</h1>", "text/html;charset=UTF-8");

        //保存上面设置的邮件内容
        message.saveChanges();

        //获取Transport对象
        Transport transport = session.getTransport();
        //smtp验证：用来发邮件的邮箱用户名密码
        transport.connect(null, null, authCode);
        //发送邮件
        transport.sendMessage(message, message.getAllRecipients()); // 发送
    }
}