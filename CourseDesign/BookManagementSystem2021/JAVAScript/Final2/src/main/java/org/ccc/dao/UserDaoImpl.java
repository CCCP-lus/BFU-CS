package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;

import org.ccc.pojo.User;

import java.util.List;

public class UserDaoImpl implements UserDao
{
    public SqlSession sqlSession;

    public UserDaoImpl(SqlSession sqlSession)
    {
        this.sqlSession = sqlSession;
    }

    @Override
    public User selectUserByUserName(String username)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectUserByUserName", username);
    }

    @Override
    public User selectUserByUserId(int userid)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectUserByUserId", userid);
    }

    @Override
    public List<User> selectAllUser()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllUser");
    }


    @Override
    public int addUser(User user)
    {
        return this.sqlSession.insert("org.ccc.mappers.mymapper.addUser", user);
    }

    @Override
    public void updateUser(User user)
    {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateUser", user);
    }


    @Override
    public void updateUserByUserId(User user)
    {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateUserByUserId", user);
    }

    @Override
    public void deleteUser(int userid)
    {
        this.sqlSession.delete("org.ccc.mappers.mymapper.deleteUser", userid);
    }

    @Override
    public List<String> selectAllWorkNumber()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllWorkNumber");
    }

    @Override
    public List<String> selectAllUsername()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllUsername");
    }

    @Override
    public List<String> fuzzyQueryUsernameByWorkplaceName(String workplacename)
    {
        workplacename="%"+workplacename+"%";
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.fuzzyQueryUsernameByWorkplaceName",workplacename);
    }
}
