<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<!--模态框 ，修改密码-->
<div class="modal fade" id="changePwdModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="Modify">修改信息</h4>
            </div>
            <div class="modal-body">
                <form method="post" action="${pageContext.request.contextPath}/ChangePwd" accept-charset="UTF-8">
                    <%--@declare id="intro"--%><label for="intro">修改密码</label> <br><br>
                    <label for="oldpwd">原密码</label>
                    <input name="oldpwd" id="oldPwd" type="password" class="form-control"/><br>
                    <label for="newpwd">新密码</label>
                    <input name="newpwd" id="newPwd" type="password" class="form-control"/><br>
                    <label for="configpwd">再次确认密码</label>
                    <input name="configpwd" id="configPwd" type="password" class="form-control"/><br>
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                    <input type="submit" class="btn btn-default" value="修改" />
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
