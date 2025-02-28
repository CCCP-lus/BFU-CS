package org.ccc.dao;

import org.ccc.pojo.Review;

import java.util.List;

public interface ReviewDao
{
    //根据book_id查询审核review
    public List<Review> selectReviewByBookId(int book_id);

    //添加一个审核
    public int addReview(Review review);

    //获取所有review
    public List<Review> selectAllReview();

    //通过review_id获取review
    public Review selectReviewByReviewId(int reviewid);

    //通过review_id删除review
    public void deleteReviewByReviewId(int reviewid);

    //通过review_id更新review
    public void updateReview(Review review);
}
