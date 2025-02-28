<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/16
  Time: 14:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html class="bootstrap-admin-vertical-centered">
<head>
    <title>找到密码</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <%

        String path = request.getContextPath();
        String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
    %>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-theme.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-admin-theme.css">
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/jquery-3.0.0.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/get_pwd.css">
</head>
<body class="bglogin bootstrap-admin-without-padding">
<div class="row">
    <div  class="col-lg-12 form-inline" style="text-align: center">
        <div class="title" style="color: #0f0f0f">找到密码</div>
        <form class="bootstrap-admin-login-form" accept-charset="UTF-8">

            <%--@declare id="password"--%><%--@declare id="pwd"--%><label for="password">您的密码为：</label>
            <%
                String pwd=(String)session.getAttribute("pwd");
            %>
            <label for="pwd"><%=pwd%></label>
            <br><br>
            <button class="btn btn-default" type="button" onclick="myFunction()">返回</button><br>

            <script>
                function myFunction()
                {
                    window.location='/Final2_war_exploded/login.jsp';
                }
            </script>
        </form>
    </div>
</div>
</body>
</html>
