package org.ccc.controller.common;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@WebServlet("/CheckCode")
public class CheckCode extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException
    {
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        // 判断验证码是否正确
        String check=new String(request.getParameter("check").getBytes(StandardCharsets.ISO_8859_1), StandardCharsets.UTF_8).trim();
        if(request.getSession().getAttribute("checkcode").equals(check))
        {
            response.getWriter().write("<script language=javascript>window.location='/Final2_war_exploded/get_pwd.jsp'</script>");
        }
        else
        {
            response.getWriter().write("<script language=javascript>alert('提示，验证码有误');window.location='/Final2_war_exploded/verify.jsp'</script>");
        }
    }
}
