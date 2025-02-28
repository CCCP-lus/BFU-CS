package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.Role;

public class RoleDaoImpl implements RoleDao
{
    public SqlSession sqlSession;
    public RoleDaoImpl(SqlSession sqlSession)
    {
        this.sqlSession = sqlSession;
    }

    @Override
    public Role selectRoleByRoleId(int role_id)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectRoleByRoleId", role_id);
    }
}
