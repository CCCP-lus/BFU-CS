<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/16
  Time: 16:19
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>核验验证码</title>
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

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/verify.css">
</head>
<body class="bglogin bootstrap-admin-without-padding">
    <div class="row">
        <div  class="col-lg-12 form-inline" style="text-align: center">
            <div class="title">输入验证码</div>
            <form class="bootstrap-admin-login-form" id="form1" action="${pageContext.request.contextPath}/CheckCode" method="post" accept-charset="UTF-8">
                <label for="check">验证码<br>
                    <input name="check" id="check"  type="text" class="form-control"/>
                </label>
                <br><br>
                <input type="submit" class="btn btn-default" value="提交" />
            </form>
        </div>
    </div>
</body>
</html>
