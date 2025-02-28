package org.ccc.pojo;

import java.util.Date;

public class Check
{
    private int check_id;
    private int book_id;
    private int user_id;
    private String workplace_name;
    private String status;
    private String reason;
    private String notes;
    private Date now_time;

    public void setBook_id(int book_id)
    {
        this.book_id = book_id;
    }

    public void setUser_id(int user_id)
    {
        this.user_id = user_id;
    }

    public void setStatus(String status)
    {
        this.status = status;
    }

    public void setNotes(String notes)
    {
        this.notes = notes;
    }

    public void setReason(String reason)
    {
        this.reason = reason;
    }

    public void setNow_time(Date now_time)
    {
        this.now_time = now_time;
    }

    public void setWorkplace_name(String real_name)
    {
        this.workplace_name = real_name;
    }

    public void setCheck_id(int check_id)
    {
        this.check_id = check_id;
    }

    public int getBook_id()
    {
        return book_id;
    }

    public int getUser_id()
    {
        return user_id;
    }

    public String getNotes()
    {
        return notes;
    }

    public Date getNow_time()
    {
        return now_time;
    }

    public String getReason()
    {
        return reason;
    }

    public String getStatus()
    {
        return status;
    }

    public String getWorkplace_name()
    {
        return workplace_name;
    }

    public int getCheck_id()
    {
        return check_id;
    }

}
