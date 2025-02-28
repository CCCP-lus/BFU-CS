<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>新增</title>
</head>
<body>
<!--模态框 ，新增-->
<div class="modal fade" id="addModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel2">添加</h4>
            </div>
            <div class="modal-body">
                <form id="form1" method="post" action="${pageContext.request.contextPath}/AddStaff" accept-charset="UTF-8">
                    <label for="intro">创建一名工作人员，信息必填</label> <br><br>
                    <label for="worknumber">工号</label>
                    <input name="worknumber" id="workNumber" type="text" class="form-control"/>
                    <label for="username">用户名</label>
                    <input name="username" id="userName" value="用户名为工号" type="text" class="form-control" disabled/><br>
                    <label for="password">密码</label>
                    <input name="password" id="password" value="初始密码为工号后4位" type="text" class="form-control" disabled/><br>
                    <label for="realname">真实姓名</label>
                    <input name="realname" id="realName" type="text" class="form-control"/>
                    <label for="sex">性别</label>
                    <input name="sex" id="sex" type="text" class="form-control"/>
                    <label for="phonenumber">联系电话</label>
                    <input name="phonenumber" id="phoneNumber" type="text" class="form-control"/>
                    <label for="email">邮箱</label>
                    <input name="email" id="email" type="text" class="form-control"/>
                    <label for="address">地址</label>
                    <input name="address" id="address" type="text" class="form-control"/>
                    <label for="workplacename">所属单位</label>
                    <input name="workplacename" id="workplaceName" type="text" class="form-control"/>
                    <label for="hportrait">头像</label>
                    <input name="hportrait" id="hPortrait" type="file" onchange="document.getElementById('textfield').value=document.getElementById('hPortrait').value" class="form-control"/>
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
