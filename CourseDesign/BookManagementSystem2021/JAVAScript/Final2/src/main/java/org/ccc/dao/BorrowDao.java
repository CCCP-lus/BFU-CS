package org.ccc.dao;

import org.ccc.pojo.Borrow;

import java.util.List;

public interface BorrowDao
{
    //添加一个借阅信息
    public int addOneBorrow(Borrow borrow);
    //更新一个借阅信息
    public void updateBorrow(Borrow borrow);
    //选择所有借阅信息
    public List<Borrow> selectAllBorrow();
}
