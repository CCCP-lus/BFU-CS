package org.ccc.dao;

import org.ccc.pojo.User_Role;

public interface UserRoleDao
{
    //通过userid查找对应role_id
    public int selectRoleIdByUserId(int userid);

    //add一条记录
    public int addOneUserRole(User_Role user_role);
}
