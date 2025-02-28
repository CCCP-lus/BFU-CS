<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/27
  Time: 21:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<div class="modal fade" id="editModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel">修改个人信息</h4>
            </div>
            <div class="modal-body">
                <form method="post" action="${pageContext.request.contextPath}/ModifyInfo">
                    <%--@declare id="intro"--%><label for="intro">保持字段为空表示不修改</label> <br><br>

                    <%-- 设置disabled防止篡改关键内容 --%>
                    <label>用户ID
                        <input name="user_id" type="text" class="form-control" disabled />
                    </label>
                    <label>工作ID
                        <input name="work_no" type="text" class="form-control" disabled />
                    </label>
                    <label>用户名
                        <input name="username" type="text" class="form-control" disabled />
                    </label>
                    <label>所属单位
                        <input name="workplace_name" type="text" class="form-control" disabled />
                    </label>
                    <label>真实姓名
                        <input name="real_name" type="text" class="form-control" />
                    </label>
                    <label>性别
                        <input name="sex" type="text" class="form-control" />
                    </label>
                    <label>联系电话
                        <input name="phone" type="text" class="form-control" />
                    </label>
                    <label>电子邮箱
                        <input name="e_mail" type="text" class="form-control" />
                    </label>
                    <label>地址
                        <input name="address" type="text" class="form-control" />
                    </label>
                    <label>头像
                        <input name="photo" type="file" id="fileField" onchange="document.getElementById('textfield').value=document.getElementById('fileField').value" class="form-control" />
                    </label>
                    <label>创建时间
                        <input name="create_time" type="text" class="form-control" disabled />
                    </label>
                    <label>上次登录时间
                        <input name="last_time" type="text" class="form-control" disabled />
                    </label>
                    <br>
                    <button type="button" class="btn btn-default" data-dismiss="modal">退出且不保存</button>
                    <input type="submit" class="btn btn-default" value="修改" />
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
