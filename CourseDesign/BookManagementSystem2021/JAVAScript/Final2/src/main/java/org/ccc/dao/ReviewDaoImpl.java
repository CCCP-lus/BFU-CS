package org.ccc.dao;

import org.apache.ibatis.session.SqlSession;
import org.ccc.pojo.Review;

import java.util.List;

public class ReviewDaoImpl implements ReviewDao
{
    public SqlSession sqlSession;

    public ReviewDaoImpl(SqlSession sqlSession) 
    {
        this.sqlSession = sqlSession;
    }

    //根据book_id查询审核review
    @Override
    public List<Review> selectReviewByBookId(int book_id)
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectReviewByBookId",book_id);
    }

    //添加一个审核
    @Override
    public int addReview(Review review)
    {
        return this.sqlSession.insert("org.ccc.mappers.mymapper.addReview", review);
    }

    //获取所有review
    @Override
    public List<Review> selectAllReview()
    {
        return this.sqlSession.selectList("org.ccc.mappers.mymapper.selectAllReview");
    }

    //通过review_id获取review
    @Override
    public Review selectReviewByReviewId(int review_id)
    {
        return this.sqlSession.selectOne("org.ccc.mappers.mymapper.selectReviewByReviewId",review_id);
    }

    //通过review_id删除review
    @Override
    public void deleteReviewByReviewId(int review_id)
    {
        this.sqlSession.delete("org.ccc.mappers.mymapper.deleteReviewByReviewId",review_id);
    }

    //通过review_id更新review
    @Override
    public void updateReview(Review review)
    {
        this.sqlSession.update("org.ccc.mappers.mymapper.updateReview",review);
    }
}
