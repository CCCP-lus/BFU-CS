<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/27
  Time: 22:08
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    SqlSession sqlSession;
    String resource = "mybatis-config.xml";
    // 读取配置文件
    InputStream is = Resources.getResourceAsStream(resource);
    // 构建SqlSessionFactory
    SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
    // 获取sqlSession
    sqlSession = ssf.openSession();
    UserRoleDao userroleDao = new UserRoleDaoImpl(sqlSession);
    int roleid = userroleDao.selectRoleIdByUserId(u.getUser_id());

    // 根据不同的身份，加载不同的功能栏
    if(roleid==1)
    {
%>
<ul class="layui-nav layui-layout-left">
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/UserManagement.jsp">用户管理</a></li>
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/BookManagement.jsp">图书管理</a></li>
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/WorkplaceManagement.jsp">单位管理</a></li>
</ul>
<%
}
else if(roleid==3)
{
%>
<ul class="layui-nav layui-layout-left"></ul>
<%
}
else if(roleid==2)
{
%>
<ul class="layui-nav layui-layout-left">
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookManagement.jsp">图书管理</a></li>
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookBorrowing.jsp">图书流入</a></li>
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookLending.jsp">图书流出</a></li>
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/BookChecking.jsp">图书借阅</a></li>
    <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/staff/GraphManagement.jsp">统计分析管理</a></li>
</ul>
<%
    }
%>
</body>
</html>
