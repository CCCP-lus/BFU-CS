package org.ccc.dao;

import java.util.List;
import org.ccc.pojo.*;

public interface BookDao
{
    //查询所有图书
    public List<Book> selectAllBook();
    //添加一个图书
    public int addBook(Book book);
    //删除一个图书
    public void deleteBook(int book_id);
    //更新一个图书
    public void updateBookByBookId(Book book);
    //图书名模糊查询
    public List<Book> fuzzyQueryByBookName(String book_name);
    //出版社模糊查询
    public List<Book> fuzzyQueryByPublisher(String publisher);
    //图书分类模糊查询
    public List<Book> fuzzyQueryById(String category);
    // 通过作者查询
    public List<Book> fuzzyQueryByAuthor(String author);
    //通过所属单位查询
    public List<Book> selectBookByWorkplace(String workplace);
    //通过book_id查询
    public Book selectBookByBookId(int book_id);
}
