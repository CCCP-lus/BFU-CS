<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>修改</title>
</head>
<body>
<!--模态框 ，修改-->
<div class="modal fade" id="changeModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel">修改</h4>
            </div>
            <div class="modal-body">
                <form method="post" action="${pageContext.request.contextPath}/ChangeBook" accept-charset="UTF-8">
                    <%--@declare id="updatespecimenId"--%><%--@declare id="enteredby"--%><%--@declare id="enteringtime"--%>
                    <input type="hidden" id="book_id3" name="updatesid3">
                    <label for="book_name3">图书名</label>
                    <input name="book_name3" id="book_name3" type="text" class="form-control" /><br>
                    <label for="author3">作者</label>
                    <input name="author3" id="author3" type="text" class="form-control" />
                    <label for="publisher3">出版社</label>
                    <input name="publisher3" id="publisher3" type="text" class="form-control" />
                    <label for="publish_time3">出版时间</label>
                    <input name="publish_time3" id="publish_time3" type="text" class="form-control" />
                    <label for="category3">图书分类</label>
                    <input name="category3" id="category3" type="text" class="form-control" />
                    <label for="page_number3">图书页数</label>
                    <input name="page_number3" id="page_number3" type="text" class="form-control" />
                    <label for="price3">图书价格</label>
                    <input name="price3" id="price3" type="text" class="form-control" />
                    <label for="privilege3">图书权限</label>
                    <input type="hidden" id="picture3" name="picture3"/>
                    <select name="privilege3" id="privilege3" class="form-control">
                        <option value="开放">开放</option>
                        <option value="隐藏">隐藏</option>
                    </select>
                    <br>
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                    <input type="submit" class="btn btn-default" value="修改" />
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
