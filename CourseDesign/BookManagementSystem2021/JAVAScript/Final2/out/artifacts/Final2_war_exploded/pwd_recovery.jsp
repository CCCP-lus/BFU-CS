<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/16
  Time: 13:00
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>找回密码</title>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-theme.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-admin-theme.css">
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/jquery-3.0.0.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/pwd_recovery.css">
</head>
<body class="bglogin bootstrap-admin-without-padding">
<div class="row">
    <div  class="col-lg-12" style="text-align: center">
        <div class="title" style="color: #0f0f0f">密码找回</div>
        <form class="bootstrap-admin-login-form" id="form1" action="${pageContext.request.contextPath}/SendEmail" method="post" accept-charset="UTF-8">
            <label for="username">用户名<br>
                <input name="username" id="username"  type="text" class="form-control"/><br>
            </label>
            <label for="myemail">邮箱<br>
                <input name="myemail" id="myemail" type="text" class="form-control" />
            </label>

            <br><br>
            <input type="submit" class="btn btn-default" value="验证" />
        </form>
    </div>
</div>
</body>
</html>
