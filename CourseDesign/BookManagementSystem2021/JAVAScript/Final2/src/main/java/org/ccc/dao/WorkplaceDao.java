package org.ccc.dao;

import org.ccc.pojo.Workplace;

import java.util.List;

public interface WorkplaceDao
{
    // 添加一个单位
    public int addWorkplace(Workplace workplace);

    //模糊检索
    public List<Workplace> fuzzyQueryByWorkplaceName(String workplaceName);

    //查询所有单位
    public List<Workplace> selectAllWorkplace();

    //查询一个单位的详细信息
    public Workplace selectWorkplaceByWorkplaceId(int workplaceId);

    //删除一个单位
    public void deleteWorkplaceByWorkplaceId(int workplaceId);

    //更新一个单位
    public void updateWorkplace(Workplace workplace);
}
