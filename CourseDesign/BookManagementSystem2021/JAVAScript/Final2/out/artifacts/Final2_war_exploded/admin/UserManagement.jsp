<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page import="java.util.List" %>
<%@ page import="org.ccc.pojo.Role" %>
<%@ page import="org.ccc.dao.*" %>
<%@ page import="java.util.Collections" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>用户管理</title>

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
    <!-- <link rel="stylesheet" href="https://cdn.staticfile.org/font-awesome/4.7.0/css/font-awesome.css"> -->
    <link type="text/css" rel="stylesheet" href="<%=basePath%>/css/layui.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap.min.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-theme.css">
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/bootstrap-admin-theme.css">
    <script type="text/javascript" src="<%=basePath%>/js/layui.js"></script>
    <script type="text/javascript" src="<%=basePath%>/js/jquery-3.0.0.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/UserManagement.css">
</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <!-- 头部区域（可配合layui已有的水平导航） -->
        <ul class="layui-nav layui-layout-left">
            <li class="layui-nav-item"><a href="javascript:;">用户管理</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/BookManagement.jsp">图书管理</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/WorkplaceManagement.jsp">单位管理</a></li>
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

    <%@include file="PageForModel/AddStaff.jsp"%>

    <%@include file="PageForModel/StaffInfo.jsp"%>

    <%@include file="PageForModel/ModifyStaff.jsp"%>

    <div class="layui-body" style="overflow:scroll">
        <!-- 内容主体区域 -->
        <div class="row">
            <div class="col-lg-12">
                <div class="panel panel-default bootstrap-admin-no-table-panel">
                    <div class="bootstrap-admin-no-table-panel-content bootstrap-admin-panel-content collapse in">
                        <form class="form-horizontal" action="${pageContext.request.contextPath}/SelectUser" method="post">
                            <!--<input type="hidden" name="tip" value="1"> -->
                            <div class="col-lg-7 form-group">
                                <div class="col-lg-3">
                                    <select  name="selectby" class="searchTerm" hidden="hidden">
<%--                                        <option value="byname"  selected >按图书名查询</option>--%>
<%--                                        <option value="byauthor" >按作者查询</option>--%>
<%--                                        <option value="byid" >按图书编号查询</option>--%>
<%--                                        <option value="bypublisher" >按所属出版社查询</option>--%>
                                    </select>
                                </div>
                                <div class="col-lg-6">
                                    <input type="text" name="searchUser" class="searchTerm" placeholder="请输入查询的用户名">
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
        <br>
        <table class="table table-striped table-bordered table-hover text-info">
            <thead>
            <tr>
                <th>用户号</th>
                <th>用户名</th>
                <th>角色</th>
                <th>真实姓名</th>
                <th>性别</th>
                <th>联系电话</th>
                <th>电子邮箱</th>
                <th>地址</th>
                <th>所属单位</th>
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
                UserDao userDao=new UserDaoImpl(sqlSession);

                List<User> users = null;
                if(request.getAttribute("users") == null)
                {
                    users = userDao.selectAllUser();
                }
                else
                {
                    users = Collections.singletonList((User) request.getAttribute("users"));
                }

//                List<User> users=userDao.selectAllUser();
                for (User user : users) {
                    UserRoleDao userRoleDao=new UserRoleDaoImpl(sqlSession);
                    int roleid=userRoleDao.selectRoleIdByUserId(user.getUser_id());
                    RoleDao roleDao=new RoleDaoImpl(sqlSession);
                    Role role=roleDao.selectRoleByRoleId(roleid);
            %>
            <tbody>
            <tr>
                <td><%=user.getUser_id() %></td>
                <td><%=user.getUsername() %></td>
                <td><%=role.getRole_name() %></td>
                <td><%=user.getReal_name() %></td>
                <td><%=user.getSex() %></td>
                <td><%=user.getPhone() %></td>
                <td><%=user.getE_mail() %></td>
                <td><%=user.getAddress() %></td>
                <td><%=user.getWorkplace_name() %></td>
                <td>
                    <button type="button" class="btn btn-success" data-toggle="modal" data-target="#detailModal" id="btn_detail"
                            onclick="showInfo('<%= user.getUser_id() %>','<%= user.getUsername() %>','<%=role.getRole_name()%>','<%=user.getReal_name() %>',
                                    '<%=user.getSex() %>','<%=user.getPhone() %>','<%=user.getE_mail() %>','<%=user.getAddress() %>','<%=user.getWorkplace_name() %>',
                                    '<%=user.getWork_no()%>','<%=user.getCreate_time()%>','<%=user.getLast_time()%>')">详情</button>
                    <button class="btn btn-warning" data-toggle="modal" data-target="#changeModal" id="btn_update"
                            onclick="updateInfo('<%= user.getUser_id() %>','<%=user.getReal_name() %>',
                                    '<%=user.getSex() %>','<%=user.getPhone() %>','<%=user.getE_mail() %>',
                                    '<%=user.getAddress() %>','<%=user.getWorkplace_name() %>')">修改</button>
                    <button type="button" class="btn btn-danger" onclick="deleteUser(<%=user.getUser_id() %>)">删除</button>
                </td>
            </tr>
            </tbody>
            <%
                }
                //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
                sqlSession.commit();
                //关闭SqlSession
                sqlSession.close();
            %>
        </table>
    </div>

    <div class="layui-footer">
        <!-- 底部固定区域 -->
    </div>
<script>
    function showInfo(userid2, username2, rolename2, realname2, sex2, phonenumber2, email2, address2, workplacename2, worknumber2, createtime2, lastlogin2) {
        document.getElementById("userid2").value = userid2;
        document.getElementById("username2").value = username2;
        document.getElementById("rolename2").value = rolename2;
        document.getElementById("realname2").value = realname2;
        document.getElementById("sex2").value = sex2;
        document.getElementById("phonenumber2").value = phonenumber2;
        document.getElementById("email2").value = email2;
        document.getElementById("address2").value = address2;
        document.getElementById("workplacename2").value = workplacename2;
        document.getElementById("worknumber2").value = worknumber2;
        document.getElementById("createtime2").value = createtime2;
        document.getElementById("lastlogin2").value = lastlogin2;
    }

    function updateInfo(updateuserId, updaterealname, updatesex, updatephonenumber, updateemail, updateaddress, updateworkplacename){
        document.getElementById("updateuserId").value = updateuserId;
        document.getElementById("updaterealname").value = updaterealname;
        document.getElementById("updatesex").value = updatesex;
        document.getElementById("updatephonenumber").value = updatephonenumber;
        document.getElementById("updateemail").value = updateemail;
        document.getElementById("updateaddress").value = updateaddress;
        document.getElementById("updateworkplacename").value = updateworkplacename;
    }

    function deleteUser(userid)
    {
        con = confirm("是否删除该用户?");
        if (con === true)
        {
            location.href = "${pageContext.request.contextPath}/DeleteUser?userid=" + userid;
        }
    }
</script>
</div>
</body>
</html>
