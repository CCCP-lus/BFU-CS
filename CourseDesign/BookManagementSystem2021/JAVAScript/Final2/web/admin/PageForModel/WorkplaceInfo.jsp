<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:48
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<!--模态框 ，详情-->
<div class="modal fade" id="detailModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel">详情</h4>
            </div>
            <div class="modal-body">
                <form id="form2">
                    <input type="hidden" id="updateworkplaceId" name="updatewid">
                    <label for="updateWorkplaceName">单位名称</label>
                    <input name="workplace_name" id="updateWorkplaceName" type="text" class="form-control" disabled/><br>
                    <label for="updateLinkman">联系人</label>
                    <input name="linkman" id="updateLinkman" type="text" class="form-control" disabled/><br>
                    <label for="updateTelephone">联系电话</label>
                    <input name="telephone" id="updateTelephone" type="text" class="form-control" disabled/><br>
                    <label for="updateE_mail">电子邮箱</label>
                    <input name="e_mail" id="updateE_mail" type="text" class="form-control" disabled/><br>
                    <label for="updateAddress">地址</label>
                    <input name="address" id="updateAddress" type="text" class="form-control" disabled/><br>
                    <label for="updateCharacter">单位性质</label>
                    <input name="character" id="updateCharacter" type="text" class="form-control" disabled/>
                    <br>

                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
