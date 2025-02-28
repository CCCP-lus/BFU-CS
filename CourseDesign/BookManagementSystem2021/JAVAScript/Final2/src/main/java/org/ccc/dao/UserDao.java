package org.ccc.dao;

import org.ccc.pojo.User;

import java.util.List;

public interface UserDao
{
    //根据username查询一个用户
    public User selectUserByUserName(String username);

    //根据userid查询一个用户
    public User selectUserByUserId(int user_id);

    //查询所有用户
    public List<User> selectAllUser();

    //添加一个用户
    public int addUser(User user);

    //更新一个用户
    public void updateUser(User user);

    //更新一个用户信息
    public void updateUserByUserId(User user);

    //根据用户名删除用户
    public void deleteUser(int user_id);

    //获取所有工号
    public List<String> selectAllWorkNumber();

    //获取所有用户名
    public List<String> selectAllUsername();

    //单位名模糊查询，获取用户名
    public List<String> fuzzyQueryUsernameByWorkplaceName(String workplaceName);
}
