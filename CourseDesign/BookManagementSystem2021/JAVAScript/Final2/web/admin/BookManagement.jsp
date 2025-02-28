<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="org.ccc.dao.BookDao" %>
<%@ page import="org.ccc.dao.BookDaoImpl" %>
<%@ page import="org.ccc.pojo.Book" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="java.util.List" %>
<%@ page import="org.ccc.dao.UserDao" %>
<%@ page import="org.ccc.dao.UserDaoImpl" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>图书管理</title>

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

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/BookManagement.css">
</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <!-- 头部区域（可配合layui已有的水平导航） -->
        <ul class="layui-nav layui-layout-left">
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/UserManagement.jsp">用户管理</a></li>
            <li class="layui-nav-item"><a href="javascript:;">图书管理</a></li>
            <li class="layui-nav-item"><a href="${pageContext.request.contextPath}/admin/WorkplaceManagement.jsp">单位管理</a></li>
        </ul>
        <ul class="layui-nav layui-layout-right">
            <li class="layui-nav-item"><a  href="javascript:;">
                <%
                    User u=(User)session.getAttribute("userbean");
                    String headportrait_path=u.getPhoto();
                    String username=u.getUsername();

                %>

                <img id="adminImg" class="layui-nav-img" src="../<%=headportrait_path %>" alt="该用户未上传头像">
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
                        <form method="post" action="GetLogout">
                            &nbsp;&nbsp;&nbsp;&nbsp;
                            <input type="submit" class="change" value="退出"/>
                        </form>
                    </dd>
                </dl>
            </li>
        </ul>
    </div>

    <%@include file="PageForModel/ChangePwd.jsp"%>

    <%@include file="PageForModel/AddBook.jsp"%>

    <%@include file="PageForModel/BookInfo.jsp"%>

    <%@include file="PageForModel/ModifyBook.jsp"%>

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

                List<Book> books = null;

                if(request.getAttribute("books") == null)
                {
                    books = bookDao.selectAllBook();
                }
                else
                {
                    books = (List<Book>)request.getAttribute("books");
                }

                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");

                for(Book book:books)
                {
                    String myusername=book.getEnter_by();
                    UserDao userDao=new UserDaoImpl(sqlSession);
                    User user=userDao.selectUserByUserName(myusername);

            %>
            <tbody>
            <tr>
                <td><%=book.getBook_id() %></td>
                <td><%=book.getBook_name() %></td>
                <td><%=book.getAuthor() %></td>
                <td><%=book.getPublisher() %></td>
                <td><%=book.getPublish_time() %></td>
                <td><%=book.getCategory() %></td>
                <td><%=book.getPage_number() %></td>
                <td><%=book.getPrice() %></td>
                <td>
                    <button type="button" class="btn btn-success" data-toggle="modal" data-target="#detailModal" id="btn_detail"
                            onclick="showInfo('<%=book.getBook_id() %>','<%=book.getBook_name() %>',
                                    '<%=book.getAuthor() %>','<%=book.getPublisher() %>','<%=book.getPublish_time() %>',
                                    '<%=book.getCategory() %>','<%=book.getPage_number() %>','<%=book.getPrice() %>',
                                    '<%=book.getPrivilege()%>','<%=book.getPicture() %>')">详情</button>
                    <button class="btn btn-warning" data-toggle="modal" data-target="#changeModal" id="btn_update"
                            onclick="updateInfo('<%=book.getBook_id() %>','<%=book.getBook_name() %>',
                                    '<%=book.getAuthor() %>','<%=book.getPublisher() %>','<%=book.getPublish_time() %>',
                                    '<%=book.getCategory() %>','<%=book.getPage_number() %>','<%=book.getPrice() %>',
                                    '<%=book.getPrivilege()%>','<%=book.getPicture() %>')">修改</button>
                    <button type="button" class="btn btn-danger" onclick="deleteBook(<%=book.getBook_id() %>)">删除</button>
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
        function updateInfo(updatebookId, updatebookname, updateunearthedsite, updateunearthedtime, updatematerialquality, updatedynasty, updateenteredby, updateenteringtime, updatedescription, updateprivilege){
            document.getElementById("book_id3").value = updatebookId;
            document.getElementById("book_name3").value = updatebookname;
            document.getElementById("author3").value = updateunearthedsite;
            document.getElementById("publisher3").value = updateunearthedtime;
            document.getElementById("publish_time3").value = updatematerialquality;
            document.getElementById("category3").value = updatedynasty;
            document.getElementById("page_number3").value = updateenteredby;
            document.getElementById("price3").value = updateenteringtime;
            document.getElementById("privilege3").value = updatedescription;
            document.getElementById("picture3").value = updateprivilege;
        }

        function showInfo(specimennid2, specimenname2, unearthedsite2, unearthedtime2, materialquality2, dynasty2, enteredby2, enteringtime2, workplacename2, image) {
            document.getElementById("specimennid2").value = specimennid2;
            document.getElementById("specimenname2").value = specimenname2;
            document.getElementById("unearthedsite2").value = unearthedsite2;
            document.getElementById("unearthedtime2").value = unearthedtime2;
            document.getElementById("materialquality2").value = materialquality2;
            document.getElementById("dynasty2").value = dynasty2;
            document.getElementById("enteredby2").value = enteredby2;
            document.getElementById("enteringtime2").value = enteringtime2;
            document.getElementById("workplacename2").value = workplacename2;
            document.getElementById("picture").src = "../" + image;
        }

        function deleteBook(book_id) {
            con = confirm("是否删除该图书?");
            if (con === true)
            {
                location.href = "${pageContext.request.contextPath}/DeleteBook?book_id=" + book_id;
            }
        }
    </script>
</div>
</body>
</html>
