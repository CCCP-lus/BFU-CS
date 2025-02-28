package org.ccc.pojo;

import java.util.Date;

public class Book
{
    private int book_id;
    private String book_name;
    private Date publish_time;
    private String author;
    private String publisher;
    private String category;
    private int page_number;
    private double price;
    private String picture;
    private String privilege;
    private String enter_by;

    public void setBook_id(int book_id)
    {
        this.book_id = book_id;
    }

    public void setBook_name(String book_name)
    {
        this.book_name = book_name;
    }

    public void setPublish_time(Date publish_time)
    {
        this.publish_time = publish_time;
    }

    public void setAuthor(String author)
    {
        this.author = author;
    }

    public void setPublisher(String publisher)
    {
        this.publisher = publisher;
    }

    public void setCategory(String category)
    {
        this.category = category;
    }

    public void setPage_number(int page_number)
    {
        this.page_number = page_number;
    }

    public void setPrice(double price)
    {
        this.price = price;
    }

    public void setPicture(String picture)
    {
        this.picture = picture;
    }

    public void setPrivilege(String privilege)
    {
        this.privilege = privilege;
    }

    public void setEnter_by(String enter_by)
    {
        this.enter_by = enter_by;
    }

    public int getBook_id()
    {
        return book_id;
    }

    public String getBook_name()
    {
        return book_name;
    }

    public Date getPublish_time()
    {
        return publish_time;
    }

    public String getAuthor()
    {
        return author;
    }

    public String getPublisher()
    {
        return publisher;
    }

    public String getCategory()
    {
        return category;
    }

    public int getPage_number()
    {
        return page_number;
    }

    public double getPrice()
    {
        return price;
    }

    public String getPicture()
    {
        return picture;
    }

    public String getPrivilege()
    {
        return privilege;
    }

    public String getEnter_by()
    {
        return enter_by;
    }
}
