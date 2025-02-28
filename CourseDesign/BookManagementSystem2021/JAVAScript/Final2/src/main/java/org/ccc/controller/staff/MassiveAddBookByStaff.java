package org.ccc.controller.staff;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.ccc.dao.BookDao;
import org.ccc.dao.BookDaoImpl;
import org.ccc.pojo.Book;
import org.ccc.pojo.User;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Properties;
import jxl.read.biff.BiffException;

@WebServlet("/BulkAddBookByStaff")
public class MassiveAddBookByStaff extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // TODO Auto-generated method stub
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");

        // 拿到文件名
        String myexcel= request.getParameter("excelpath").trim();
        System.out.println(myexcel);

        // 配置文件的路径
        String path=Thread.currentThread().getContextClassLoader().getResource("ConfigJavaweb.properties").getPath().replace("%20", " ");
        System.out.println(path);

        path=path.substring(1);
        InputStream in =new BufferedInputStream(Files.newInputStream(Paths.get(path)));
        Properties properties = new Properties();
        properties.load(in);
        String excelpath = properties.getProperty("excelpath");

        System.out.println(excelpath);

//        excelpath=excelpath+myexcel;

        readExcel re=new readExcel();
        ArrayList<String[]> list = null;
        try
        {
            list=re.read(excelpath);
        }
        catch (BiffException e)
        {
            throw new RuntimeException(e);
        }

        SqlSession sqlSession;
        String resource = "mybatis-config.xml";
        // 读取配置文件
        InputStream is = Resources.getResourceAsStream(resource);
        // 构建SqlSessionFactory
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        // 获取sqlSession
        sqlSession = ssf.openSession();

        //遍历每一条，添加进数据库
        HttpSession session=request.getSession();
        User u=(User)session.getAttribute("userbean");
        String enteredby=u.getUsername();
        Date enteringtime=new Date();

        BookDao bookDao=new BookDaoImpl(sqlSession);

        int[] hasSame=new int[list.size()];//每一条记录是否与数据库中重复

        System.out.println("准备导入数目：" + list.size());

        for(int i=0;i<list.size();i++)
        {
            Book book=new Book();
            String[] str = (String[])list.get(i);
            book.setBook_name(str[0]);
            book.setAuthor(str[1]);
            Date datepublishtime=null;
            try {
                datepublishtime= new Date(new SimpleDateFormat("yyyy-MM-dd").parse(str[2]).getTime());
            } catch (ParseException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

            book.setPublish_time(datepublishtime);
            book.setCategory(str[3]);
            book.setPublisher(str[4]);
            book.setPrice(Integer.parseInt(str[5]));
            book.setPage_number(Integer.parseInt(str[6]));
            book.setPicture(str[7]);
            book.setPrivilege(str[8]);
            book.setEnter_by(enteredby);

            List<Book> books=bookDao.selectAllBook();
            for(Book mybook:books) {
                if(allEquals(book,mybook))
                {
                    hasSame[i]=1;		//第i+1条记录与数据库重复了
                    break;
                }
            }
        }

        String tip="第";
        int cnt=0;
        for(int i=0;i<hasSame.length;i++)
        {
            if(hasSame[i]==1)
            {
                if(cnt==0)
                {
                    cnt++;
                    tip=tip+ (i + 1);
                }
                else{
                    tip=tip+"、"+ (i + 1);
                }
            }
        }
        tip=tip+"条记录与数据库重复";
        if(!tip.equals("第条记录与数据库重复")) {
            tip=tip+"，记录均不导入，请修改后再导入";
            tip="'"+tip+"'";
            response.getWriter().write("<script language=javascript>alert("+tip+");"+"window.location='/staff/BookManagement.jsp'</script>");
            return;
        }

        //循环录入所有信息
        for(int i=0;i<list.size();i++) 
        {
            Book book=new Book();
            String[] str = (String[])list.get(i);
            book.setBook_name(str[0]);
            book.setAuthor(str[1]);
            Date datepublishtime=null;
            try {
                datepublishtime= new Date(new SimpleDateFormat("yyyy-MM-dd").parse(str[2]).getTime());
            } catch (ParseException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

            book.setPublish_time(datepublishtime);
            book.setCategory(str[3]);
            book.setPublisher(str[4]);
            book.setPrice(Integer.parseInt(str[5]));
            book.setPage_number(Integer.parseInt(str[6]));
            book.setPicture(str[7]);
            book.setPrivilege(str[8]);
            book.setEnter_by(enteredby);
            bookDao.addBook(book);	//添加
        }


        //提交事务，由于mybatis采用了事务管理，所以必须要进行提交
        sqlSession.commit();
        //关闭SqlSession
        sqlSession.close();

        String forwardUrl="/staff/BookManagement.jsp";
        RequestDispatcher dispatcher=
                request.getRequestDispatcher(forwardUrl);
        dispatcher.forward(request, response);

    }

    // 除了ID全部相同视为同一本书
    public boolean allEquals(Book book1, Book book2)
    {
        if (book1.getBook_name().equals(book2.getBook_name()))
        {
            if (book1.getAuthor().equals(book2.getAuthor()))
            {
                if (book1.getPublisher().equals(book2.getPublisher()))
                {
                    if (book1.getPublish_time().equals(book2.getPublish_time()))
                    {
                        if (book1.getCategory().equals(book2.getCategory())) {
                            if (book1.getPage_number() == book2.getPage_number())
                            {
                                if (book1.getPrice() == book2.getPrice())
                                {
                                    if (book1.getPicture().equals(book2.getPicture()))
                                    {
                                        return book1.getPrivilege().equals(book2.getPrivilege());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

}

class readExcel
{
    public ArrayList<String[]> read(String filepath) throws IOException, BiffException
    {
        ArrayList<String[]> list = new ArrayList<String[]>();	//ArrayList<String[]>存储所有内容，String[]存1行的所有单元格
        File file = new File(filepath);
        FileInputStream fis = new FileInputStream(file);
        Workbook wb = null;

        // 兼容模式与非兼容模式处理方式的判定
        if(filepath.endsWith(".xls"))
        {
            wb = new HSSFWorkbook(fis);
        }
        else if(filepath.endsWith(".xlsx"))
        {
            wb = new XSSFWorkbook(fis);
        }

        Sheet sheet = wb.getSheetAt(0);		//Sheet1页面
        Row row = null;
        Cell cell = null;


        System.out.println("表格行数：" + sheet.getLastRowNum());

        for(int i=0;i<=sheet.getLastRowNum();i++)
        {
            if(i==0)
            {
                continue;
            }
            row = sheet.getRow(i);
            String[] str=new String[9];
            for(int j=0;j<row.getLastCellNum();j++)
            {
                cell = row.getCell(j);
                cell.setCellType(CellType.STRING);
                str[j]=cell.getStringCellValue();
            }
            list.add(str);
        }
        fis.close();

        System.out.println("返回长度：" + list.size());

        return list;
    }
}