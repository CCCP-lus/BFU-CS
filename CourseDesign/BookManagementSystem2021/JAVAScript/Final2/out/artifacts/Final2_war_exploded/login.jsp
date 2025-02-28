<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/16
  Time: 12:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"
    %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="zh-CN" class="bootstrap-admin-vertical-centered">
<!-- <html lang="zh-CN"> -->
<head>
    <script type="text/javascript">
        history.pushState(null, null, location.href);
        window.onpopstate = function () {
            history.go(1);
        };
        function disablePageBack() {
            //消除后退的所有动作。包括 键盘、鼠标手势等产生的后退动作。，用户登录到系统中后，浏览器回退按钮失效，只能点击退出按钮退出系统！
            history.pushState(null, null, document.URL);
            window.addEventListener('popstate', function () {
                history.pushState(null, null, document.URL);
            });
        }
        disablePageBack();

        $(function() {
            if (window.history && window.history.pushState) {
                $(window).on('popstate', function () {
                    window.history.pushState('forward', null, '#');
                    window.history.forward(1);
                });
            }
            window.history.pushState('forward', null, '#'); //在IE中必须得有这两行
            window.history.forward(1);
        })
    </script>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>天E阁——您的随身图书管理平台</title>

	<link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.css">
	<link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-theme.css">
	<link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-admin-theme.css">
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js" type=""></script>
    <script src="${pageContext.request.contextPath}/js/jquery-3.0.0.min.js" type=""></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js" type=""></script>

    <link rel="stylesheet" href="css/login.css">
</head>

<body class="bootstrap-admin-without-padding">
<div class="bglogin">
    <div class="row">
        <div class="col-lg-12" style="text-align: center;">
            <!-- 登录标题 -->
            <h2 class="title">欢 迎 登 录 天 E 阁 图 书 管 理 系 统</h2>
            <form class="bootstrap-admin-login-form" method="post" action="${pageContext.request.contextPath}/GetLogin">
                <div class="form-group">
                    <!-- 显示用户名输入框 -->
                    <label for="username">用户名</label>
                    <input type="text" class="form-control" id="username" name="username"/>
                </div>
                <div class="form-group">
                    <!-- 显示密码输入框 -->
                    <label for="password">密 码</label>
                    <input type="password" class="form-control" id="password" name="password"/>
                </div>

                <!-- 显示注册和找回密码链接 -->
                <div>
                    <a href="${pageContext.request.contextPath}/register.jsp" style="color:blue;">读者注册</a>
                    <a href="${pageContext.request.contextPath}/pwd_recovery.jsp" style="color:blue;">找回密码</a>
                </div>

                <br>
                <!-- 显示登录按钮 -->
                <button type="submit" class="btn btn-primary">登录</button>
            </form>
        </div>
    </div>
</div>
</body>
</html>

