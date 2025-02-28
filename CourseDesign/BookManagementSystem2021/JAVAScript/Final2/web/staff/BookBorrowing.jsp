<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/17
  Time: 10:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.ccc.pojo.User" %>
<%@ page import="org.apache.ibatis.session.SqlSession" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactory" %>
<%@ page import="org.apache.ibatis.session.SqlSessionFactoryBuilder" %>
<%@ page import="java.io.InputStream" %>
<%@ page import="org.apache.ibatis.io.Resources" %>
<%@ page import="org.ccc.pojo.Review" %>
<%@ page import="java.util.List" %>
<%@ page import="org.ccc.dao.*" %>
<%@ page import="org.ccc.pojo.Book" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>图书流入页</title>

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

    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/BookBorrowing.css">
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

                <img id="adminImg" class="layui-nav-img" src="../<%=headportrait_path %>" alt="头像未上传">
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
                        <form method="post" action="${pageContext.request.contextPath}/GetLogout">
                            &nbsp;&nbsp;&nbsp;&nbsp;
                            <input type="submit" class="change" value="退出"/>
                        </form>
                    </dd>
                </dl></li>
        </ul>
    </div>

    <%@include file="PageForModel/ChangePwd.jsp"%>

    <%@include file="PageForModel/BorrowingRequest.jsp"%>

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
                        UserDao userDao=new UserDaoImpl(ss);
                        User user=userDao.selectUserByUserId(myreview.getUser_id());
                        //本单位借阅
                        if(user.getWorkplace_name().equals(u.getWorkplace_name()))
                        {
                            Book book = bookdao.selectBookByBookId(myreview.getBook_id());
                            //图书的录入人，进而找到图书所在单位
                            User user2=userDao.selectUserByUserName(book.getEnter_by());
                %>
                <tr>
                    <td><%=book.getBook_id() %></td>
                    <td><%=book.getBook_name() %></td>
                    <td><%=user2.getWorkplace_name() %></td>
                    <td><%=myreview.getStatus() %></td>
                </tr>
                <%
                    }}
                %>
                </tbody>
            </table>

            <table class="table table-striped table-bordered table-hover text-info">
                <caption style="color: darkblue; font-size: larger">可流入</caption>
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
                    List<Book> books;
                    books=bookDao.selectAllBook();
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");

                    for(Book book:books)
                    {
                        String datePublishtime = sdf.format(book.getPublish_time());
                        String myusername=book.getEnter_by();
                        UserDao userDao=new UserDaoImpl(sqlSession);
                        User user=userDao.selectUserByUserName(myusername);
                        
                        //排除外单位开放但已经被借走了的
                        if(!u.getWorkplace_name().equals(user.getWorkplace_name())&&book.getPrivilege().equals("开放"))
                        {
                            ReviewDao reviewDao=new ReviewDaoImpl(sqlSession);
                            List<Review> reviews=reviewDao.selectReviewByBookId(book.getBook_id());
                            int canBorrow=1;	//0表示不可借，原因1：已被借走，原因2：本单位已经借了等待审核不必重复借阅。
                            //如果status为成功或者请求归还，则说明已经被借走还未归还
                            for(Review review:reviews){
                                if(review.getStatus().equals("成功")||review.getStatus().equals("请求归还")){
                                    canBorrow=0;
                                    break;
                                }
                                //通过审核表的userid，找到是哪个单位发起的借阅
                                User user2=userDao.selectUserByUserId(review.getUser_id());

                                //自己单位已经借了，并且处于请求状态等待审核，不必重复借阅
                                if(user2.getWorkplace_name().equals(u.getWorkplace_name())&&review.getStatus().equals("请求"))
                                {
                                    canBorrow=0;
                                    break;
                                }
                            }
                            if(canBorrow==0) continue;
                        }

                        //排除本单位的和外单位隐藏的
                        if(u.getWorkplace_name().equals(user.getWorkplace_name()))continue;
                        if(!u.getWorkplace_name().equals(user.getWorkplace_name())&&book.getPrivilege().equals("隐藏"))continue;

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
                        <button class="btn btn-success" id="btn_detailed" data-toggle="modal" data-target="#addModal"
                                onclick="request('<%=book.getBook_id() %>','<%=user.getWorkplace_name() %>',
                                        '<%=u.getUser_id() %>','请求')">借阅</button>
                    </td>
                </tr>
                </tbody>
                <%
                    }
                %>

            </table>

            <table class="table table-striped table-bordered table-hover text-info">
                <caption style="color: darkblue; font-size: larger">已流入</caption>
                <thead>
                <tr>
                    <th>图书号</th>
                    <th>图书名称</th>
                    <th>图书所属单位</th>
                    <th>作者</th>
                    <th>出版社</th>
                    <th>操作</th>
                </tr>
                </thead>
                <%
                    //获取所有Review
                    ReviewDao reviewDao=new ReviewDaoImpl(sqlSession);
                    List<Review> reviews=reviewDao.selectAllReview();
                    //打印出，review表中，找到userid对应的单位是本单位，且status为成功。（找到被本单位借阅来的图书）
                    for(Review review:reviews){
                        //获取申请借阅该图书的人
                        UserDao userDao=new UserDaoImpl(sqlSession);
                        User user=userDao.selectUserByUserId(review.getUser_id());
                        //不满足以下条件的，continue;  1.申请人的单位和当前用户的单位相同，2.该图书状态为成功或请求归还
                        if(!(user.getWorkplace_name().equals(u.getWorkplace_name())&&(review.getStatus().equals("成功")||review.getStatus().equals("请求归还"))))continue;

                        Book book=bookDao.selectBookByBookId(review.getBook_id());
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
                    <%if(review.getStatus().equals("成功"))
                    {
                    %>

                    <td>
                        <button type="button" class="btn btn-success" id="btn_detail"
                                onclick="returnback('<%=review.getReview_id() %>')">归还</button>
                    </td>
                    <%
                    }
                    else if(review.getStatus().equals("请求归还")){
                    %>
                    <td>
                        已请求归还，等待对方审核
                    </td>
                    <%
                        }
                    %>
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
        function request(specimenId,workplaceName,userId,status)
        {
            document.getElementById("specimenId").value = specimenId;
            document.getElementById("workplaceName").value = workplaceName;
            document.getElementById("userId").value = userId;
            document.getElementById("status").value = status;
        }

        function returnback(reviewid)
        {
            location.href = "${pageContext.request.contextPath}/RequestReturn?reviewid=" + reviewid;
        }
    </script>

</div>

</body>
</html>
