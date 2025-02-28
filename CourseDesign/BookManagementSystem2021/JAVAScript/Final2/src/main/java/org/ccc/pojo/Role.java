package org.ccc.pojo;

import java.util.Date;

public class Role
{
    private int role_id;
    private String role_name;
    private Date create_time;
    private String situation;
    private String remarks;

    public void setRole_id(int role_id)
    {
        this.role_id = role_id;
    }

    public void setRole_name(String role_name)
    {
        this.role_name = role_name;
    }

    public void setCreate_time(Date create_time)
    {
        this.create_time = create_time;
    }

    public void setSituation(String situation)
    {
        this.situation = situation;
    }

    public void setRemarks(String remarks)
    {
        this.remarks = remarks;
    }

    public int getRole_id()
    {
        return role_id;
    }

    public String getRole_name()
    {
        return role_name;
    }

    public Date getCreate_time()
    {
        return create_time;
    }

    public String getSituation()
    {
        return situation;
    }

    public String getRemarks()
    {
        return remarks;
    }
}
