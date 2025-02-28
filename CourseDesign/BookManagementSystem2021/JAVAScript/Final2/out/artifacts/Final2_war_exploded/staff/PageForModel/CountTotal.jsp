<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/24
  Time: 13:08
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Title</title>
</head>
<body>
<%
  int countTotalBook=0;	//总图书数
  int countNowBook=0;		//当前在库总图书数
  SqlSession sqlSession;
  String resource = "mybatis-config.xml";
  // 读取配置文件
  InputStream is = Resources.getResourceAsStream(resource);
  // 构建SqlSessionFactory
  SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
  // 获取sqlSession
  sqlSession = ssf.openSession();
  BookDao bookDao=new BookDaoImpl(sqlSession);
  List<Book> books=bookDao.selectAllBook();
  for(Book book:books)
  {
    //图书的录入人
    String myusername=book.getEnter_by();
    UserDao userDao=new UserDaoImpl(sqlSession);
    User user=userDao.selectUserByUserName(myusername);
    //通过录入人得知图书的所属单位，在本单位则总数加1
    if(user.getWorkplace_name().equals(u.getWorkplace_name()))
      countTotalBook++;
  }

  countNowBook=countTotalBook;
  ReviewDao reviewDao=new ReviewDaoImpl(sqlSession);
  List<Review> reviews= reviewDao.selectAllReview();
  for(Review review:reviews){
    //该图书被借走还未归还
    if(review.getStatus().equals("成功")&&review.getWorkplace_name().equals(u.getWorkplace_name()))
      countNowBook--;
  }

  //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
  sqlSession.commit();


%>
</body>
</html>
