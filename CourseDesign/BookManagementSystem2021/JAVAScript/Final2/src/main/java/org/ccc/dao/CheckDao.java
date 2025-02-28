package org.ccc.dao;

import org.ccc.pojo.Check;

import java.util.List;

public interface CheckDao
{
    //根据book_id查询审核check
    public List<Check> selectCheckByBookId(int book_id);

    //添加一个审核
    public int addCheck(Check check);

    //获取所有check
    public List<Check> selectAllCheck();

    //通过check_id获取check
    public Check selectCheckByCheckId(int checkid);

    //通过check_id删除check
    public void deleteCheckByCheckId(int checkid);

    //通过check_id更新check
    public void updateCheck(Check check);

}
