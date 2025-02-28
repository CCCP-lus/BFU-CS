<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/16
  Time: 14:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="org.ccc.dao.UserRoleDao" %>
<%@ page import="org.ccc.dao.UserRoleDaoImpl" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>个人信息</title>
    <%

        String path = request.getContextPath();
        String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
    %>
    <base href="<%=basePath%>">

    <link type="text/css" rel="stylesheet" href="<%=basePath%>/css/layui.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.css">
    <script type="text/javascript" src="<%=basePath%>/js/layui.js"></script>
    <script type="text/javascript" src="<%=basePath%>/js/jquery-3.0.0.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="<%=basePath%>/css/info.css">
</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <!-- layui的头部区域（可配合layui已有的水平导航） -->
        <ul class="layui-nav layui-layout-right">
            <li class="layui-nav-item">
                <a  href="javascript:">
                    <%
                        User u=(User)session.getAttribute("userbean");
                        String headportrait_path=u.getPhoto();
                        String username=u.getUsername();
                    %>
                    <img id="adminImg" class="layui-nav-img" src="../<%=headportrait_path %>" alt="该用户未上传头像">
                    <span id="adminName"><%=username %></span>
                </a>
                <dl class="layui-nav-child">
                    <dd>
                        <a id="admin-info" href="javascript:">个人信息</a>
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

        <%-- 根据不同的用户身份加载不同的功能栏 --%>
        <%@include file="ToolBar.jsp"%>
    </div>

    <div class="layui-body" style="overflow:scroll">
        <!-- 内容主体区域 -->
        <div style="padding: 5px;" id="main_content">
            <table class="table table-striped table-bordered table-hover text-info">
                <caption style="text-align: center; font-size: larger; color: black">查看和修改个人信息</caption>
                <thead>
                <tr>
                    <th>标签</th>
                    <th>内容</th>
                </tr>
                </thead>
                <tbody>
                <tr>
                    <td>用户编号</td>
                    <td><%=u.getUser_id() %></td>
                </tr>
                <tr>
                    <td>工作编号</td>
                    <td><%=u.getWork_no() %></td>
                </tr>
                <tr>
                    <td>用户名</td>
                    <td><%=u.getUsername() %></td>
                </tr>
                <tr>
                    <td>所属单位</td>
                    <td><%=u.getWorkplace_name() %></td>
                </tr>
                <tr>
                    <td>真实姓名</td>
                    <td><%=u.getReal_name() %></td>
                </tr>
                <tr>
                    <td>性别</td>
                    <td><%=u.getSex() %></td>
                </tr>
                <tr>
                    <td>联系电话</td>
                    <td><%=u.getPhone() %></td>
                </tr>
                <tr>
                    <td>电子邮箱</td>
                    <td><%=u.getE_mail() %></td>
                </tr>
                <tr>
                    <td>地址</td>
                    <td><%=u.getAddress() %></td>
                </tr>
                <tr>
                    <td>头像</td>
                    <td><img src="../<%=u.getPhoto() %>" alt="未上传头像" height="100" width="100"></td>
                </tr>
                <tr>
                    <td>创建时间</td>
                    <td><%=u.getCreate_time() %></td>
                </tr>
                <tr>
                    <td>上次登录时间</td>
                    <td><%=u.getLast_time() %></td>
                </tr>

                <%@include file="ModifyModel.jsp"%>

                <tr>
                    <td>修改信息</td>
                    <td><button id="getLast_time" class="btn btn-warning" data-toggle="modal" data-target="#editModal">编辑</button></td>
                </tr>
                </tbody>
            </table>
        </div>
    </div>

    <div class="layui-footer">
        <!-- 底部固定区域 -->
    </div>
</div>
</body>
</html>
