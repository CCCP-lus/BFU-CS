package org.ccc.dao;

import org.ccc.pojo.Circulate;

import java.util.List;

public interface CirculateDao
{
    //添加一个借阅信息
    public int addOneCirculate(Circulate circulate);
    //更新一个借阅信息
    public void updateCirculate(Circulate circulate);
    //选择所有借阅信息
    public List<Circulate> selectAllCirculate();
}
