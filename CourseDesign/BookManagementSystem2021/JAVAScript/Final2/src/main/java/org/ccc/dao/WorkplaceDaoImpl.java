package org.ccc.dao;

import java.util.List;

import org.apache.ibatis.session.SqlSession;

import org.ccc.pojo.Workplace;

public class WorkplaceDaoImpl implements WorkplaceDao
{
    public SqlSession sqlSession;

    public WorkplaceDaoImpl(SqlSession sqlSession)
    {
        this.sqlSession = sqlSession;
    }

    //添加一个单位
    @Override
    public int addWorkplace(Workplace workplace)
    {
        return this.sqlSession.insert("org.ccc.mappers.mymapper.addWorkplace", workplace);
    }

    //模糊检索
    @Override
    public List<Workplace> fuzzyQueryByWorkplaceName(String workplace_name)
    {
        workplace_name = "%" + workplace_name + "%";
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.fuzzyQueryByWorkplaceName",workplace_name);
    }

    //查询所有单位
    @Override
    public List<Workplace> selectAllWorkplace()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllWorkplace");
    }

    //查询一个单位的详细信息
    @Override
    public Workplace selectWorkplaceByWorkplaceId(int workplace_id)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectWorkplaceByWorkplaceId", workplace_id);
    }

    //删除一个单位
    @Override
    public void deleteWorkplaceByWorkplaceId(int workplace_id)
    {
        this.sqlSession.delete("org.ccc.mappers.mymapper.deleteWorkplaceByWorkplaceId", workplace_id);
    }

    //更新一个单位
    @Override
    public void updateWorkplace(Workplace workplace)
    {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateWorkplace", workplace);
    }
}
