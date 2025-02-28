<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:18
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="org.ccc.pojo.Book" %>
<%@ page import="java.util.List" %>
<%@ page import="org.ccc.dao.*" %>
<%@ page import="org.ccc.pojo.Check" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>读者首页</title>

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
    <link rel="stylesheet" href="${pageContext.request.contextPath}css/bootstrap-admin-theme.css">

    <script type="text/javascript" src="<%=basePath%>/js/layui.js"></script>
    <script type="text/javascript" src="<%=basePath%>/js/jquery-3.0.0.min.js"></script>
    <script src="${pageContext.request.contextPath}/js/bootstrap.min.js"></script>

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/reader_index.css">

</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <ul class="layui-nav layui-layout-right">
            <li class="layui-nav-item"><a  href="javascript:">
                <%
                    User u=(User)session.getAttribute("userbean");
                    String headportrait_path=u.getPhoto();
                    String username=u.getUsername();

                %>

                <img id="adminImg" class="layui-nav-img" src="../<%=headportrait_path %>" alt="用户未上传头像">
                <span id="adminName"><%=username %>[读者]</span>
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

    <%@include file="PageForModel/CheckOutBook.jsp"%>

    <%@include file="PageForModel/BookInfo.jsp"%>

    <div class="layui-body" style="overflow:scroll">
        <!-- 内容主体区域 -->
        <div class="col-lg-12">
            <div class="panel panel-default bootstrap-admin-no-table-panel">
                <div class="bootstrap-admin-no-table-panel-content bootstrap-admin-panel-content collapse in">
                    <form class="form-horizontal" action="${pageContext.request.contextPath}/SelectBookByAdmin" method="post">
                        <div class="col-lg-7 form-group">
                            <div class="col-lg-3">
                                <select  name="selectby" class="searchTerm">
                                    <option value="byname"  selected >按图书名查询</option>
                                    <option value="byauthor" >按作者查询</option>
                                    <option value="byid" >按图书编号查询</option>
                                    <option value="bypublisher" >按所属出版社查询</option>
                                </select>
                            </div>
                            <div class="col-lg-6">
                                <input type="text" name="searchBook" class="searchTerm" placeholder="请输入查询的内容">
                            </div>
                            <div>
                                <button type="submit" class="btn btn-primary">
                                    <i class="fa fa-search"></i>查
                                </button>
                            </div>
                        </div>
                    </form>
                </div>
            </div>
        </div>
        <br>
        <div style="padding: 5px;" id="main_content">
            <p><b>欢迎！您目前可以借阅这些书</b></p>
            <table class="table table-striped table-bordered table-hover text-info">
                <thead>
                <tr>
                    <th>图书编号</th>
                    <th>图书名称</th>
                    <th>作者</th>
                    <th>出版社</th>
                    <th>出版时间</th>
                    <th>图书分类</th>
                    <th>图书页数</th>
                    <th>图书价格</th>
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
                    BookDao bookDao=new BookDaoImpl(sqlSession);
                    List<Book> books = bookDao.selectAllBook();
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");

                    for(Book book : books)
                    {
                        if(book.getPrivilege().equals("隐藏")) continue;
                        UserDao userDao = new UserDaoImpl(sqlSession);
                        User user = userDao.selectUserByUserName(book.getEnter_by());
                %>
                <tbody>
                <tr>
                    <td><%=book.getBook_id() %></td>
                    <td><%=book.getBook_name() %></td>
                    <td><%=book.getAuthor() %></td>
                    <td><%=book.getPublisher() %></td>
                    <td><%=book.getPublish_time()%></td>
                    <td><%=book.getCategory() %></td>
                    <td><%=book.getPage_number()%></td>
                    <td><%=book.getPrice()%></td>
                    <td>
                        <button type="button" class="btn btn-success" data-toggle="modal" data-target="#detailModal" id="btn_detail"
                                onclick="showInfo('<%=book.getBook_id() %>','<%=book.getBook_name() %>',
                                        '<%=book.getAuthor() %>','<%=book.getPublisher() %>','<%=book.getPublish_time() %>',
                                        '<%=book.getCategory() %>','<%=book.getPage_number() %>','<%=book.getPrice() %>',
                                        '<%=book.getPrivilege()%>','<%=book.getPicture() %>','<%=book.getPicture() %>','<%=book.getPicture() %>')">详情</button>

                        <button type="button" class="btn btn-warning" data-toggle="modal" data-target="#addModal" id="btn_checkout"
                                onclick="request('<%=book.getBook_id() %>','<%=user.getWorkplace_name() %>',
                                        '<%=u.getUser_id() %>','请求')">借阅</button>
                    </td>
                    <%-- '<%=user.getWorkplacename() %>','<%=book.getDescription() %>', --%>
                </tr>
                </tbody>
                <%
                    }
                %>
            </table>

            <p><b>您已借阅的图书如下：</b></p>
            <table class="table table-striped table-bordered table-hover text-info">
                <thead>
                <tr>
                    <th>图书号</th>
                    <th>图书名称</th>
                    <th>图书所属单位</th>
                    <th>作者</th>
                    <th>出版社</th>
                </tr>
                </thead>
                <%
                    // 获取所有的Check
                    CheckDao checkDao = new CheckDaoImpl(sqlSession);
                    List<Check> checks = checkDao.selectAllCheck();

                    for(Check check : checks)
                    {
                        //获取申请借阅该图书的人
                        UserDao userDao=new UserDaoImpl(sqlSession);
                        User user=userDao.selectUserByUserId(check.getUser_id());

                        if(!check.getStatus().equals("成功"))
                            continue;

                        Book book=bookDao.selectBookByBookId(check.getBook_id());
                        //图书的录入人，进而找到图书所在单位
                        User user2=userDao.selectUserByUserName(book.getEnter_by());

                %>
                <tbody>
                <tr>
                    <td><%=book.getBook_id() %></td>
                    <td><%=book.getBook_name() %></td>
                    <td><%=user2.getWorkplace_name() %></td>
                    <td><%=book.getAuthor() %></td>
                    <td><%=book.getPublisher() %></td>
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

    <script>
        function showInfo(booknid2, bookname2, unearthedsite2, unearthedtime2, materialquality2, dynasty2, enteredby2, enteringtime2, workplacename2, description2, privilege2, image) {
            document.getElementById("booknid2").value = booknid2;
            document.getElementById("bookname2").value = bookname2;
            document.getElementById("unearthedsite2").value = unearthedsite2;
            document.getElementById("unearthedtime2").value = unearthedtime2;
            document.getElementById("materialquality2").value = materialquality2;
            document.getElementById("dynasty2").value = dynasty2;
            document.getElementById("enteredby2").value = enteredby2;
            document.getElementById("enteringtime2").value = enteringtime2;
            document.getElementById("picture").src = "../"+image;
        }

        function request(specimenId,workplaceName,userId,status) {
            document.getElementById("specimenId").value = specimenId;
            document.getElementById("workplaceName").value = workplaceName;
            document.getElementById("userId").value = userId;
            document.getElementById("status").value = status;
        }
    </script>

</div>
</body>
</html>
