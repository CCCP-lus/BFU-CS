package org.ccc.dao;

import org.ccc.pojo.Role;

public interface RoleDao
{
    // 根据role_id查询一个角色
    public Role selectRoleByRoleId(int role_id);
}
