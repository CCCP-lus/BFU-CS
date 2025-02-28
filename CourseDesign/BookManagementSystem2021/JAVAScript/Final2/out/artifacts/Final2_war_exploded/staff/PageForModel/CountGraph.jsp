<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/24
  Time: 13:10
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    int[] borrowByYear=new int[5];
    int[] lendByYear=new int[5];
    int[] borrowByMonth=new int[12];
    int[] lendByMonth=new int[12];
    for(int i=0;i<5;i++) borrowByYear[i]=lendByYear[i]=0;
    for(int i=0;i<12;i++) borrowByMonth[i]=lendByMonth[i]=0;
    BorrowDao borrowDao=new BorrowDaoImpl(sqlSession);
    List<Borrow> borrows=borrowDao.selectAllBorrow();
    CirculateDao circulateDao=new CirculateDaoImpl(sqlSession);
    List<Circulate> circulates=circulateDao.selectAllCirculate();
    WorkplaceDao workplaceDao = new WorkplaceDaoImpl(sqlSession);
    List<Workplace> workplaces = workplaceDao.selectAllWorkplace();
    CheckDao checkDao=new CheckDaoImpl(sqlSession);
    List<Check> checks=checkDao.selectAllCheck();
    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    //当前年份
    Date now=new Date();
    String nowDate=sdf.format(now);
    int nowyear=Integer.parseInt(nowDate.substring(0,4));

    for(Borrow borrow:borrows)
    {
        //借阅的时间
        String time=sdf.format(borrow.getBorrow_time());

        //借阅者是本单位，（借入）
        int userid=borrow.getUser_id();
        UserDao userDao=new UserDaoImpl(sqlSession);
        User user=userDao.selectUserByUserId(userid);
        if(user.getWorkplace_name().equals(u.getWorkplace_name())){
            int year=Integer.parseInt(time.substring(0,4));
            int month=Integer.parseInt(time.substring(5,7));
            borrowByYear[year-nowyear+4]++;	//年份对应的数组中的值加1  2018年对应[0]
            if(year==nowyear){
                borrowByMonth[month-1]++;
            }
        }

        //借阅的图书是本单位的，（借出）
        if(borrow.getWorkplace_name().equals(u.getWorkplace_name())){
            int year=Integer.parseInt(time.substring(0,4));
            int month=Integer.parseInt(time.substring(5,7));
            lendByYear[year-nowyear+4]++;	//年份对应的数组中的值加1  2018年对应[0]
            if(year==nowyear){
                lendByMonth[month-1]++;
            }
        }

    }

    for(Circulate circulate: circulates)
    {
        //借阅的时间
        String time=sdf.format(circulate.getCirculate_time());

        int index = Integer.parseInt(circulate.getWorkplace_id());
        String target = "";
        for(Workplace workplace : workplaces)
        {
            if(workplace.getWorkplace_id() == index)
                target = workplace.getWorkplace_name();
        }

        //借阅的图书是本单位的，（借出）
        if(target.equals(u.getWorkplace_name())){
            int year=Integer.parseInt(time.substring(0,4));
            int month=Integer.parseInt(time.substring(5,7));
            lendByYear[year-nowyear+4]++;	//年份对应的数组中的值加1  2018年对应[0]
            if(year==nowyear){
                lendByMonth[month-1]++;
            }
        }

    }

    //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
    sqlSession.commit();
    //关闭SqlSession
    sqlSession.close();
%>
</body>
</html>
