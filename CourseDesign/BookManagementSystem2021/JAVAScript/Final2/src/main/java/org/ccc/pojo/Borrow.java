package org.ccc.pojo;

import java.util.Date;

public class Borrow
{
    private int borrow_id;
    private int book_id;
    private int user_id;
    private String workplace_name;
    private String borrow_reason;
    private String remarks;
    private Date borrow_time;
    private Date return_time;
    private String borrower_name;
    private String borrower_phone;

    public int getBorrow_id()
    {
        return borrow_id;
    }

    public int getUser_id()
    {
        return user_id;
    }

    public int getBook_id()
    {
        return book_id;
    }

    public Date getBorrow_time()
    {
        return borrow_time;
    }

    public Date getReturn_time()
    {
        return return_time;
    }

    public String getRemarks()
    {
        return remarks;
    }

    public String getWorkplace_name()
    {
        return workplace_name;
    }

    public String getBorrow_reason()
    {
        return borrow_reason;
    }

    public String getBorrower_name()
    {
        return borrower_name;
    }

    public String getBorrower_phone()
    {
        return borrower_phone;
    }

    public void setBorrow_id(int borrow_id)
    {
        this.borrow_id = borrow_id;
    }

    public void setUser_id(int user_id)
    {
        this.user_id = user_id;
    }

    public void setBook_id(int book_id)
    {
        this.book_id = book_id;
    }

    public void setWorkplace_name(String workplace_name)
    {
        this.workplace_name = workplace_name;
    }

    public void setRemarks(String remarks)
    {
        this.remarks = remarks;
    }

    public void setBorrow_reason(String borrow_reason)
    {
        this.borrow_reason = borrow_reason;
    }

    public void setBorrow_time(Date borrow_time)
    {
        this.borrow_time = borrow_time;
    }

    public void setBorrower_name(String borrower_name)
    {
        this.borrower_name = borrower_name;
    }

    public void setBorrower_phone(String borrower_phone)
    {
        this.borrower_phone = borrower_phone;
    }

    public void setReturn_time(Date return_time)
    {
        this.return_time = return_time;
    }
}
