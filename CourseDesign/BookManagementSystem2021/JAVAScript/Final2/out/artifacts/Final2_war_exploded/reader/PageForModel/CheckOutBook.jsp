<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/26
  Time: 11:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>借阅图书</title>
</head>
<body>
<!--模态框 ，借阅-->
<div class="modal fade" id="addModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="jieyue">借阅</h4>
            </div>
            <div class="modal-body">
                <form id="form1" method="post" action="${pageContext.request.contextPath}/RequestUserBorrowing" accept-charset="UTF-8">
                    <input type="hidden" id="specimenId" name="bookid">
                    <input type="hidden" id="workplaceName" name="workplacename">
                    <input type="hidden" id="userId" name="userid">
                    <input type="hidden" id="status" name="status">
                    <label for="reason">借阅原因</label>
                    <input name="reason" id="reason" type="text" class="form-control" /><br>
                    <label for="notes">备注</label>
                    <input name="notes" id="notes" type="text" class="form-control" /><br>
                    <br>
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                    <input type="submit" class="btn btn-default" value="借阅" />
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
