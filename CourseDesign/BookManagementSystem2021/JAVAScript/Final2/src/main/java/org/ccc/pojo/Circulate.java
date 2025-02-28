package org.ccc.pojo;

import java.util.Date;

public class Circulate
{
    private int circulate_id;
    private int book_id;
    private int user_id;
    private String workplace_id;
    private String circulate_reason;
    private Date circulate_time;
    private Date return_time;
    private String applicant;
    private String applicant_phone;
    private String remarks;

    public void setUser_id(int user_id)
    {
        this.user_id = user_id;
    }

    public void setReturn_time(Date return_time)
    {
        this.return_time = return_time;
    }

    public void setBook_id(int book_id)
    {
        this.book_id = book_id;
    }

    public void setRemarks(String remarks)
    {
        this.remarks = remarks;
    }

    public void setWorkplace_id(String workplace_id)
    {
        this.workplace_id = workplace_id;
    }

    public void setApplicant(String applicant)
    {
        this.applicant = applicant;
    }

    public void setApplicant_phone(String applicant_phone)
    {
        this.applicant_phone = applicant_phone;
    }

    public void setCirculate_id(int circulate_id)
    {
        this.circulate_id = circulate_id;
    }

    public void setCirculate_reason(String circulate_reason)
    {
        this.circulate_reason = circulate_reason;
    }

    public void setCirculate_time(Date circulate_time)
    {
        this.circulate_time = circulate_time;
    }

    public int getUser_id()
    {
        return user_id;
    }

    public int getBook_id()
    {
        return book_id;
    }

    public String getRemarks()
    {
        return remarks;
    }

    public Date getReturn_time()
    {
        return return_time;
    }

    public Date getCirculate_time()
    {
        return circulate_time;
    }

    public int getCirculate_id()
    {
        return circulate_id;
    }

    public String getApplicant()
    {
        return applicant;
    }

    public String getApplicant_phone()
    {
        return applicant_phone;
    }

    public String getCirculate_reason()
    {
        return circulate_reason;
    }

    public String getWorkplace_id()
    {
        return workplace_id;
    }
}

