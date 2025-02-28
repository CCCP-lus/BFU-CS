<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.ccc.pojo.Review" %>
<%@ page import="java.util.List" %>
<%@ page import="org.ccc.dao.*" %>
<%@ page import="org.ccc.pojo.Book" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>流出管理</title>

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
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/BookLending.css">
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

    <div class="layui-body" style="overflow:scroll">
        <!-- 内容主体区域 -->
        <div style="padding: 5px;" id="main_content">
            <table class="table table-striped table-bordered table-hover text-info">
                <caption style="color: darkblue; font-size: larger">已完成</caption>
                <thead>
                <tr>
                    <th>图书编号</th>
                    <th>图书名称</th>
                    <th>借阅单位</th>
                    <th>状态</th>
                </tr>
                </thead>
                <tbody>
                <%
                    SqlSession ss;
                    String mc = "mybatis-config.xml";
                    InputStream istream = Resources.getResourceAsStream(mc);
                    SqlSessionFactory ssfactory = new SqlSessionFactoryBuilder().build(istream);
                    // 获取sqlSession
                    ss = ssfactory.openSession();

                    ReviewDao reviewdao=new ReviewDaoImpl(ss);
                    List<Review> myreviews=reviewdao.selectAllReview();
                    BookDao bookdao=new BookDaoImpl(ss);

                    for(Review myreview:myreviews)
                    {
                        //获取申请借阅该图书的人
                        UserDao userDao=new UserDaoImpl(ss);
                        User user=userDao.selectUserByUserId(myreview.getUser_id());
                        //本单位的图书
                        if(myreview.getWorkplace_name().equals(u.getWorkplace_name()))
                        {
                            Book book= bookdao.selectBookByBookId(myreview.getBook_id());
                %>
                <tr>
                    <td><%=book.getBook_id() %></td>
                    <td><%=book.getBook_name() %></td>
                    <td><%=user.getWorkplace_name() %></td>
                    <td><%=myreview.getStatus() %></td>
                </tr>
                <%
                        }}
                %>
                </tbody>
            </table>
        </div>


        <table class="table table-striped table-bordered table-hover text-info">
            <caption style="color: darkblue; font-size: larger">流出请求</caption>
            <thead>
            <tr>
                <th>图书号</th>
                <th>图书名称</th>
                <th>所属单位</th>
                <th>请求方用户</th>
                <th>请求方单位</th>
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
                //获取所有Review
                ReviewDao reviewDao=new ReviewDaoImpl(sqlSession);
                List<Review> reviews=reviewDao.selectAllReview();
                //打印出，review表中，属于本单位，并处于请求状态的图书
                for(Review review:reviews){
                    if(!(review.getWorkplace_name().equals(u.getWorkplace_name())&&review.getStatus().equals("请求")))continue;
                    // 输出被请求的本单位图书
                    BookDao bookDao=new BookDaoImpl(sqlSession);
                    Book book=bookDao.selectBookByBookId(review.getBook_id());
                    UserDao userDao=new UserDaoImpl(sqlSession);
                    User user=userDao.selectUserByUserId(review.getUser_id());
            %>
            <tbody>
            <tr>
                <td><%=book.getBook_id() %></td>
                <td><%=book.getBook_name() %></td>
                <td><%=u.getWorkplace_name() %></td>
                <td><%=user.getUsername() %></td>
                <td><%=user.getWorkplace_name() %></td>
                <td>
                    <button type="button" class="btn btn-success" id="btn_detail1"
                            onclick="agree('<%=review.getReview_id() %>','成功')">同意</button>
                    <button type="button" class="btn btn-danger" id="btn_detail0"
                            onclick="refuse('<%=review.getReview_id() %>','拒绝')">拒绝</button>
                </td>
            </tr>
            </tbody>
            <%
                }
            %>

        </table>

        <table class="table table-striped table-bordered table-hover text-info">
            <caption style="color: darkblue; font-size: larger">归还请求</caption>
            <thead>
            <tr>
                <th>图书号</th>
                <th>图书名称</th>
                <th>所属单位</th>
                <th>归还方用户</th>
                <th>归还方单位</th>
                <th>操作</th>
            </tr>
            </thead>
            <%
                //打印出，review表中，属于本单位，并处于请求归还状态的图书
                for(Review review:reviews)
                {
                    if(!(review.getWorkplace_name().equals(u.getWorkplace_name())&&review.getStatus().equals("请求归还")))continue;
                    //要输出的，是本单位图书，并且被请求归还
                    BookDao bookDao=new BookDaoImpl(sqlSession);
                    Book book=bookDao.selectBookByBookId(review.getBook_id());
                    UserDao userDao=new UserDaoImpl(sqlSession);
                    User user=userDao.selectUserByUserId(review.getUser_id());
            %>
            <tbody>
            <tr>
                <td><%=book.getBook_id() %></td>
                <td><%=book.getBook_name() %></td>
                <td><%=u.getWorkplace_name() %></td>
                <td><%=user.getUsername() %></td>
                <td><%=user.getWorkplace_name() %></td>
                <td>
                    <button type="button" class="btn btn-success" id="btn_detail11"
                            onclick="agreeReturn('<%=review.getReview_id() %>')">同意</button>
                    <button type="button" class="btn btn-danger" id="btn_detail22"
                            onclick="refuseReturn('<%=review.getReview_id() %>')">拒绝</button>
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
</div>

<div class="layui-footer">
    <!-- 底部固定区域 -->
</div>

<script type="text/javascript">
    function agree(reviewid) {
        location.href = "${pageContext.request.contextPath}/AgreeLending?reviewid=" + reviewid;
    }
    function refuse(reviewid) {
        location.href = "${pageContext.request.contextPath}/RefuseLending?reviewid=" + reviewid;
    }

    function agreeReturn(reviewid) {
        location.href = "${pageContext.request.contextPath}/AgreeReturn?reviewid=" + reviewid;
    }

    function refuseReturn(reviewid) {
        location.href = "${pageContext.request.contextPath}/RefuseReturn?reviewid=" + reviewid;
    }
</script>

</body>
</html>
