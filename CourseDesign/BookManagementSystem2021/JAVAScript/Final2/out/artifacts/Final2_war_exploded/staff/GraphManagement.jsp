<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="org.ccc.dao.*" %>
<%@ page import="org.ccc.pojo.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Title</title>

    <%
        // 权限验证
        if(session.getAttribute("userbean")==null)
        {
            response.sendRedirect("../login.jsp");
            return;
        }

        String path = request.getContextPath();
        String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
    %>
    <base href="<%=basePath%>">
    <link type="text/css" rel="stylesheet" href="<%=basePath%>/css/layui.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-theme.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-admin-theme.css">

    <script type="text/javascript" src="<%=basePath%>/js/layui.js"></script>
    <script type="text/javascript" src="<%=basePath%>/js/jquery-3.0.0.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/GraphManagement.css">
</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <!-- 头部区域（可配合layui已有的水平导航） -->
        <ul class="layui-nav layui-layout-left">
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookManagement.jsp">图书管理</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookBorrowing.jsp">图书流入</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookLending.jsp">图书流出</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookChecking.jsp">图书借阅</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/GraphManagement.jsp">统计分析管理</a></li>
        </ul>
        <ul class="layui-nav layui-layout-right">
            <li class="layui-nav-item"><a  href="javascript:;">
                <%
                    User u=(User)session.getAttribute("userbean");
                    String headportrait_path=u.getPhoto();
                    String username=u.getUsername();

                %>

                <img id="adminImg" class="layui-nav-img" src="../<%=headportrait_path %>" alt="headportrait">
                <span id="adminName"><%=username %>[员工]</span>
            </a>
                <dl class="layui-nav-child">
                    <dd>
                        <a id="admin-info" href="${pageContext.request.contextPath}/info.jsp">个人信息</a>
                        <%--<a id="admin-info" href="${pageContext.request.contextPath}/specimen/admin/personalinfo.jsp">个人信息</a>--%>
                    </dd>
                    <dd>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <button class="change" data-toggle="modal" data-target="#changePwdModal">修改密码</button>
                    </dd>
                    <dd>
                        <form method="post" action="GetLogout">
                            &nbsp;&nbsp;&nbsp;&nbsp;
                            <input type="submit" class="change" value="退出"/>
                        </form>
                    </dd>
                </dl>
            </li>
        </ul>
    </div>

    <%@include file="PageForModel/ChangePwd.jsp"%>>

    <div class="layui-body" style="overflow:scroll">
        <!-- 内容主体区域 -->
        <div style="padding: 5px;" id="main_content">
            <div class="col-md-10">
                <div class="row">
                    <div class="col-md-10">
                        <div class="panel panel-default">
                            <div class="panel-heading">
                                <div class="text-muted bootstrap-admin-box-title"><b>图书信息统计</b></div>
                            </div>
                            <div class="bootstrap-admin-panel-content" style="text-align: center">
                                <%@include file="PageForModel/CountTotal.jsp"%>
                                <p>本单位总图书数为：<%=countTotalBook%>本&nbsp;&nbsp;&nbsp;&nbsp;当前在库总图书数为：<%=countNowBook%>本</p>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col-md-10">
                        <div class="panel panel-default">
                            <div class="panel-heading">
                                <div class="text-muted bootstrap-admin-box-title"><b>图书流通+借阅情况统计图</b></div>
                            </div>
                            <div class="bootstrap-admin-panel-content">
                                <%@include file="PageForModel/CountGraph.jsp"%>
                                <div id="ec1" style="width:90%;height:300px;margin: 0 auto"></div>
                                <div id="ec2" style="width:90%;height:300px;margin: 0 auto"></div>

                                <%@include file="PageForModel/eCharts.jsp"%>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <div class="layui-footer">
        <!-- 底部固定区域 -->
    </div>
</div>

</body>
</html>
