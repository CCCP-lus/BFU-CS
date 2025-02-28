package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.Borrow;

import java.util.List;

public class BorrowDaoImpl implements BorrowDao
{
    public SqlSession sqlSession;
    public BorrowDaoImpl(SqlSession sqlSession) {
        this.sqlSession=sqlSession;
    }

    //添加一个借阅信息
    @Override
    public int addOneBorrow(Borrow borrow) {
        return sqlSession.insert("org.ccc.mappers.mymapper.addOneBorrow",borrow);
    }

    //更新一个借阅信息
    @Override
    public void updateBorrow(Borrow borrow) {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateBorrow", borrow);
    }

    //选择所有借阅信息
    @Override
    public List<Borrow> selectAllBorrow(){
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllBorrow");
    }
}
