package org.ccc.pojo;

import java.util.Date;

public class Review
{
    private int review_id;
    private int book_id;
    private int user_id;
    private String workplace_name;
    private String status;
    private String reason;
    private String notes;
    private Date now_time;

    public int getBook_id()
    {
        return book_id;
    }

    public int getReview_id()
    {
        return review_id;
    }

    public int getUser_id()
    {
        return user_id;
    }

    public String getWorkplace_name()
    {
        return workplace_name;
    }

    public String getStatus()
    {
        return status;
    }

    public String getReason()
    {
        return reason;
    }

    public Date getNow_time()
    {
        return now_time;
    }

    public String getNotes()
    {
        return notes;
    }

    public void setBook_id(int book_id)
    {
        this.book_id = book_id;
    }

    public void setUser_id(int user_id)
    {
        this.user_id = user_id;
    }

    public void setReview_id(int review_id)
    {
        this.review_id = review_id;
    }

    public void setWorkplace_name(String workplace_name)
    {
        this.workplace_name = workplace_name;
    }

    public void setNow_time(Date now_time)
    {
        this.now_time = now_time;
    }

    public void setReason(String reason)
    {
        this.reason = reason;
    }

    public void setNotes(String notes)
    {
        this.notes = notes;
    }

    public void setStatus(String status)
    {
        this.status = status;
    }
}



