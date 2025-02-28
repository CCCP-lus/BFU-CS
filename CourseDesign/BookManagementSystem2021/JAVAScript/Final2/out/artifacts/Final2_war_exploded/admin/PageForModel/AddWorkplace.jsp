<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:49
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<!--模态框 ，新增-->
<div class="modal fade" id="addModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel3">添加</h4>
            </div>
            <div class="modal-body">
                <form method="post" action="${pageContext.request.contextPath}/AddWorkplace" accept-charset="UTF-8">
                    <label for="intro">单位名称为必填项</label> <br><br>
                    <label for="workplace_name">单位名称</label>
                    <input id="workplace_name" name="workplace_name" type="text" class="form-control"/><br>
                    <label for="linkman">联系人</label>
                    <input id="linkman" name="linkman" type="text" class="form-control"/><br>
                    <label for="telephone">联系电话</label>
                    <input id="telephone" name="telephone" type="text" class="form-control"/><br>
                    <label for="e_mail">邮箱</label>
                    <input id="e_mail" name="e_mail" type="text" class="form-control"/><br>
                    <label for="address">地址</label>
                    <input id="address" name="address" type="text" class="form-control"/><br>
                    <label for="character">单位性质</label>
                    <input id="character" name="character" type="text" class="form-control"/>
                    <br>

                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                    <input type="submit" class="btn btn-default" value="添加" />
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
