package org.ccc.dao;

import java.util.List;
import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.*;

public class BookDaoImpl implements BookDao
{
    public SqlSession sqlSession;
    public BookDaoImpl (SqlSession sqlSession)
    {
        this.sqlSession = sqlSession;
    }
    
    //查询所有图书
    @Override
    public List<Book> selectAllBook()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllBook");
    }

    //添加一本图书
    @Override
    public int addBook(Book book)
    {
        return this.sqlSession.insert("org.ccc.mappers.mymapper.addBook", book);
    }

    //删除一本图书
    @Override
    public void deleteBook(int book_id) 
    {
        this.sqlSession.delete("org.ccc.mappers.mymapper.deleteBook", book_id);
    }

    //更新一个图书
    @Override
    public void updateBookByBookId(Book book) 
    {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateBookByBookId", book);
    }

    //图书名模糊查询
    @Override
    public List<Book> fuzzyQueryByBookName(String book_name)
    {
        book_name= "%" + book_name + "%";
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.fuzzyQueryByBookName",book_name);
    }

    //出版社模糊查询
    @Override
    public List<Book> fuzzyQueryByPublisher(String publisher)
    {
        publisher = "%" + publisher + "%";
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.fuzzyQueryByPublisher",publisher);
    }

    //图书分类模糊查询
    @Override
    public List<Book> fuzzyQueryById(String book_id)
    {
        book_id = "%" + book_id + "%";
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.fuzzyQueryById",book_id);
    }

    //图书作者模糊查询
    @Override
    public List<Book> fuzzyQueryByAuthor(String author)
    {
        author = "%" + author + "%";
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.fuzzyQueryByAuthor",author);
    }

    //通过所属单位查询
    @Override
    public List<Book> selectBookByWorkplace(String workplace)
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectBookByWorkplace",workplace);
    }

    //通过book_id查询
    @Override
    public Book selectBookByBookId(int book_id)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectBookByBookId",book_id);
    }
}
