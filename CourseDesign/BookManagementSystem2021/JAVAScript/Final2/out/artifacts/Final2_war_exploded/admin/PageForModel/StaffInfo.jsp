<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>详情</title>
</head>
<body>
<!--模态框 ，详情-->
<div class="modal fade" id="detailModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel3">详情</h4>
            </div>
            <div class="modal-body">
                <form id="form2">
                    <label for="userid2">用户号</label>
                    <input name="userid2" id="userid2" type="text" class="form-control" disabled /><br>
                    <label for="username2">用户名</label>
                    <input name="username2" id="username2" type="text" class="form-control" disabled/><br>
                    <label for="rolename2">角色</label>
                    <input name="rolename2" id="rolename2" type="text" class="form-control" disabled/>
                    <label for="realname2">真实姓名</label>
                    <input name="realname2" id="realname2" type="text" class="form-control" disabled/>
                    <label for="sex2">性别</label>
                    <input name="sex2" id="sex2" type="text" class="form-control" disabled/>
                    <label for="phonenumber2">联系电话</label>
                    <input name="phonenumber2" id="phonenumber2" type="text" class="form-control" disabled/>
                    <label for="email2">邮箱</label>
                    <input name="email2" id="email2" type="text" class="form-control" disabled/>
                    <label for="address2">地址</label>
                    <input name="address2" id="address2" type="text" class="form-control" disabled/>
                    <label for="workplacename2">所属单位</label>
                    <input name="workplacename2" id="workplacename2" type="text" class="form-control" disabled/>
                    <label for="worknumber2">工号</label>
                    <input name="worknumber2" id="worknumber2" type="text" class="form-control" disabled/>
                    <label for="createtime2">创建时间</label>
                    <input name="createtime2" id="createtime2" type="text" class="form-control" disabled/>
                    <label for="lastlogin2">上次登录时间</label>
                    <input name="lastlogin2" id="lastlogin2" type="text" class="form-control" disabled/>
                    <br>

                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
