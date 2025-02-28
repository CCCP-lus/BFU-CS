<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="org.ccc.pojo.Workplace" %>
<%@ page import="java.util.List" %>
<%@ page import="org.ccc.dao.WorkplaceDao" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>单位管理</title>

    <%
        // 权限验证
        if(session.getAttribute("userbean")==null)
        {
            response.sendRedirect("../login.jsp");
            return;
        }

        response.setContentType("text/html;charset=utf-8");
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
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/WorkplaceManagement.css">
</head>

<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <!-- 头部区域（可配合layui已有的水平导航） -->
        <ul class="layui-nav layui-layout-left">
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/UserManagement.jsp">用户管理</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/BookManagement.jsp">图书管理</a></li>
            <li class="layui-nav-item"><a href="javascript:;">单位管理</a></li>
        </ul>
        <ul class="layui-nav layui-layout-right">
            <li class="layui-nav-item"><a  href="javascript:;">
                <%
                    User u=(User)session.getAttribute("userbean");
                    String headportrait_path=u.getPhoto();
                    String username=u.getUsername();

                %>

                <img id="adminImg" class="layui-nav-img" src="../<%=headportrait_path %>" alt="用户未上传头像">
                <span id="adminName"><%=username %>[管理员]</span>
            </a>
                <dl class="layui-nav-child">
                    <dd>
                        <a id="admin-info" href="${pageContext.request.contextPath}/info.jsp">个人信息</a>
                    </dd>
                    <dd>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <button class="change" data-toggle="modal" data-target="#changePwdModal">修改密码</button>
                    </dd>
                    <dd>
                        <form method="post" action="${pageContext.request.contextPath}/GetLogout">
                            &nbsp;&nbsp;&nbsp;&nbsp;
                            <input type="submit" class="change" value="退出"/>
                        </form>
                    </dd>
                </dl></li>
        </ul>
    </div>

    <%@include file="PageForModel/ChangePwd.jsp"%>

    <%@include file="PageForModel/WorkplaceInfo.jsp"%>

    <%@include file="PageForModel/AddWorkplace.jsp"%>

    <%@include file="PageForModel/ModifyWorkplace.jsp"%>

    <div class="layui-body" style="overflow:scroll">
        <!-- 内容主体区域 -->
        <div style="padding: 5px;" id="main_content">

            <div class="row">
                <div class="col-lg-12">
                    <div class="panel panel-default bootstrap-admin-no-table-panel">
                        <div class="bootstrap-admin-no-table-panel-content bootstrap-admin-panel-content collapse in">
                            <form class="form-horizontal" action="${pageContext.request.contextPath}/SelectWorkplace" method="post">
                                <!--<input type="hidden" name="tip" value="1"> -->
                                <div class="col-lg-7 form-group">
                                    <div class="col-lg-3">
                                        <select  name="selectby" class="searchTerm" hidden="hidden">
                                        </select>
                                    </div>
                                    <div class="col-lg-6">
                                        <input type="text" name="searchWorkplace" class="searchTerm" placeholder="请输入查询的单位名称">
                                    </div>
                                    <div>
                                        <button type="submit" class="btn btn-primary">
                                            <i class="fa fa-search"></i>查
                                        </button>
                                    </div>
                                </div>
                            </form>
                            <button id="btn_add" type="button" class="btn btn-primary" data-toggle="modal" data-target="#addModal">
                                +新增
                            </button>
                        </div>
                    </div>
                </div>
            </div>

            <table class="table table-striped table-bordered table-hover text-info">
                <thead>
                <tr>
                    <th>单位编号</th>
                    <th>单位名称</th>
                    <th>联系人</th>
                    <th>联系电话</th>
                    <th>电子邮箱</th>
                    <th>地址</th>
                    <th>单位性质</th>
                    <th>操作</th>
                </tr>
                </thead>
                <%
                    SqlSession sqlSession;
                    String resource = "mybatis-config.xml";
                    // 读取配置文件
                    InputStream is = Resources.getResourceAsStream(resource);
                    // 构建SqlSessionFactory
                    SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
                    // 获取sqlSession
                    sqlSession = ssf.openSession();
                    WorkplaceDao workplaceDao=new org.ccc.dao.WorkplaceDaoImpl(sqlSession);
                    List<Workplace> workplaces;
                    workplaces=(List<Workplace>)request.getAttribute("workplaces");
                    if(workplaces==null) workplaces = workplaceDao.selectAllWorkplace();
                    //List<Workplace> workplaces = workplaceDao.selectAllWorkplace();
                    for (Workplace workplace : workplaces)
                    {
//                        System.out.println(workplace.getWorkplace_name());
                %>
                <tbody>
                <tr>
                    <td><%=workplace.getWorkplace_id() %></td>
                    <td><%=workplace.getWorkplace_name() %></td>
                    <td><%=workplace.getWorkplace_linkman() %></td>
                    <td><%=workplace.getWorkplace_telephone() %></td>
                    <td><%=workplace.getWorkplace_e_mail() %></td>
                    <td><%=workplace.getWorkplace_address() %></td>
                    <td><%=workplace.getWorkplace_character() %></td>
                    <td>
                        <button class="btn btn-success" data-toggle="modal" data-target="#detailModal" id="btn_showinfo"
                                onclick="showInfo('<%= workplace.getWorkplace_id() %>','<%= workplace.getWorkplace_name() %>',
                                        '<%= workplace.getWorkplace_linkman() %>','<%=workplace.getWorkplace_telephone() %>','<%=workplace.getWorkplace_e_mail() %>',
                                        '<%=workplace.getWorkplace_address() %>','<%= workplace.getWorkplace_character() %>')">详情</button>
                        <button class="btn btn-warning" data-toggle="modal" data-target="#changeModal" id="btn_update"
                                onclick="changeInfo('<%= workplace.getWorkplace_id() %>','<%= workplace.getWorkplace_name() %>',
                                        '<%= workplace.getWorkplace_linkman() %>','<%=workplace.getWorkplace_telephone() %>','<%=workplace.getWorkplace_e_mail() %>',
                                        '<%=workplace.getWorkplace_address() %>','<%= workplace.getWorkplace_character() %>')">修改</button>
                        <button type="button" class="btn btn-danger" onclick="deleteworkplace(<%=workplace.getWorkplace_id() %>)">删除</button>
                    </td>
                </tr>
                </tbody>
                <%} %>
            </table>

        </div>
    </div>

    <div class="layui-footer">
        <!-- 底部固定区域 -->
    </div>

    <script>
        function showInfo(workplaceid, workplacename, contacts, phonenumber, email, address, workplacenature)
        {
            document.getElementById("updateworkplaceId").value = workplaceid;
            document.getElementById("updateWorkplaceName").value = workplacename;
            document.getElementById("updateLinkman").value = contacts;
            document.getElementById("updateTelephone").value = phonenumber;
            document.getElementById("updateE_mail").value = email;
            document.getElementById("updateAddress").value = address;
            document.getElementById("updateCharacter").value = workplacenature;
        }

        function changeInfo(workplaceId2, workplacename, contacts, phonenumber, email, address, workplacenature)
        {
            document.getElementById("updateworkplaceId2").value = workplaceId2;
            document.getElementById("updateWorkplaceName2").value = workplacename;
            document.getElementById("updateWorkplaceName22").value = workplacename;
            document.getElementById("updateLinkman2").value = contacts;
            document.getElementById("updateTelephone2").value = phonenumber;
            document.getElementById("updateE_mail2").value = email;
            document.getElementById("updateAddress2").value = address;
            document.getElementById("updateCharacter2").value = workplacenature;
        }

        function deleteworkplace(workplaceid)
        {
            con = confirm("是否删除该工作单位?");
            if (con === true)
            {
                location.href = "${pageContext.request.contextPath}/DeleteWorkplace?workplaceid=" + workplaceid;
            }
        }
    </script>

</div>
</body>
</html>
