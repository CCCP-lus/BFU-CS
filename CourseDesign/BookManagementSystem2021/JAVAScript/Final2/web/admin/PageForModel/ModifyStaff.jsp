<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:47
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
                <form method="post" action="${pageContext.request.contextPath}/ChangeUser" accept-charset="UTF-8">
                    <input type="hidden" id="updateuserId" name="updateuid" value="<%=u.getUser_id()%>">
                    <label for="realname">真实姓名</label>
                    <input name="realname" id="updaterealname" type="text" class="form-control"/><br>
                    <label for="sex">性别</label>
                    <input name="sex" id="updatesex" type="text" class="form-control"/>
                    <label for="phonenumber">联系电话</label>
                    <input name="phonenumber" id="updatephonenumber" type="text" class="form-control"/><br>
                    <label for="email">邮箱</label>
                    <input name="email" id="updateemail" type="text" class="form-control"/>
                    <label for="address">地址</label>
                    <input name="address" id="updateaddress" type="text" class="form-control"/>
                    <label for="workplacename">所属单位</label>
                    <input name="workplacename" id="updateworkplacename" type="text" class="form-control"/>
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
