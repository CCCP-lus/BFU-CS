package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.Circulate;

import java.util.List;

public class CirculateDaoImpl implements CirculateDao
{
    public SqlSession sqlSession;
    public CirculateDaoImpl(SqlSession sqlSession) {
        this.sqlSession=sqlSession;
    }

    //添加一个用户借阅信息
    @Override
    public int addOneCirculate(Circulate circulate) {
        return sqlSession.insert("org.ccc.mappers.mymapper.addOneCirculate",circulate);
    }

    //更新一个用户借阅信息
    @Override
    public void updateCirculate(Circulate circulate) {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateCirculate", circulate);
    }

    //选择所有用户借阅信息
    @Override
    public List<Circulate> selectAllCirculate(){
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllCirculate");
    }
}
