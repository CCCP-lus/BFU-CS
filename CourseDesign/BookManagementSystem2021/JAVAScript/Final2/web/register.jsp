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
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>读者注册</title>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-theme.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-admin-theme.css">
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/jquery-3.0.0.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js" type=""></script>

    <link rel="stylesheet" href="css/register.css">
</head>

<body class="bootstrap-admin-without-padding bglogin" style="text-align: center">
    <div class="row">
        <div  class="col-lg-12">
            <form class="bootstrap-admin-login-form" id="form1" method="post" action="${pageContext.request.contextPath}/AddReaderUser" accept-charset="UTF-8">
                <h3><%--@declare id="intro"--%><label for="intro">读者注册</label></h3>
                <label for="username">用户名
                    <input name="username" id="username"  type="text" class="form-control"/>
                </label>
                <label for="password">密码
                    <input name="password" id="password" type="password" class="form-control"/>
                </label>
                <label for="password2">再次确认密码
                    <input name="password2" id="password2" type="password" class="form-control"/>
                </label>
                <label for="real_name">真实姓名
                <input name="real_name" id="real_name" type="text" class="form-control"/>
                </label>
                <label for="sex">性别
                    <input name="sex" id="sex" type="text" class="form-control"/>
                </label>
                <label for="phone">联系电话
                    <input name="phone" id="phone" type="text" class="form-control"/>
                </label>
                <label for="e_mail">邮箱
                    <input name="e_mail" id="e_mail" type="text" class="form-control"/>
                </label>
                <label for="address">地址
                    <input name="address" id="address" type="text" class="form-control"/>
                </label>
                <label for="photo">头像
                    <input name="photo" id="photo" type="file" onchange="document.getElementById('textfield').value=document.getElementById('hPortrait').value" class="form-control"/>
                </label>
                <br>
                <input type="submit" class="btn btn-success" value="注册" />
            </form>
        </div>
    </div>
</body>
</html>
