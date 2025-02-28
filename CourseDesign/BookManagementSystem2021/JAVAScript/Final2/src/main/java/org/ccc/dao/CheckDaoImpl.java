package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.Check;

import java.util.List;

public class CheckDaoImpl implements CheckDao
{
    public SqlSession sqlSession;

    public CheckDaoImpl(SqlSession sqlSession)
    {
        this.sqlSession = sqlSession;
    }

    //根据book_id查询审核check
    @Override
    public List<Check> selectCheckByBookId(int book_id)
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectCheckByBookId",book_id);
    }

    //添加一个审核
    @Override
    public int addCheck(Check check)
    {
        return this.sqlSession.insert("org.ccc.mappers.mymapper.addCheck", check);
    }

    //获取所有check
    @Override
    public List<Check> selectAllCheck()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllCheck");
    }

    //通过check_id获取check
    @Override
    public Check selectCheckByCheckId(int check_id)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectCheckByCheckId",check_id);
    }

    //通过check_id删除check
    @Override
    public void deleteCheckByCheckId(int check_id)
    {
        this.sqlSession.delete("org.ccc.mappers.mymapper.deleteCheckByCheckId",check_id);
    }

    //通过check_id更新check
    @Override
    public void updateCheck(Check check)
    {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateCheck",check);
    }
}
