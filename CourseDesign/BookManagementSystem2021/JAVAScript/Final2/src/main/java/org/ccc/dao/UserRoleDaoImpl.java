package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.User_Role;

public class UserRoleDaoImpl implements UserRoleDao
{
    public SqlSession sqlSession;

    public UserRoleDaoImpl(SqlSession sqlSession)
    {
        this.sqlSession = sqlSession;
    }

    //通过user_id查找对应role_id
    @Override
    public int selectRoleIdByUserId(int userid)
    {
        return sqlSession.selectOne("org.ccc.mappers.mymapper.selectRoleIdByUserId", userid);
    }

    // 新增一个用户身份记录
    @Override
    public int addOneUserRole(User_Role user_role)
    {
        return sqlSession.insert("org.ccc.mappers.mymapper.addOneUserRole",user_role);
    }
}
