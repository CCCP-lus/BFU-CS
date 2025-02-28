<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>新增图书</title>
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
                <form id="form1" method="post" action="${pageContext.request.contextPath}/AddBook" accept-charset="UTF-8">
                    <label for="intro">创建一个图书信息，信息必填</label> <br><br>
                    <label for="bookname">图书名</label>
                    <input name="bookname" id="bookName" type="text" class="form-control"/><br>
                    <label for="unearthedsite">作者</label>
                    <input name="unearthedsite" id="unearthedSite" type="text" class="form-control"/><br>
                    <label for="unearthedtime">出版社</label>
                    <input name="unearthedtime" id="unearthedTime" type="text" class="form-control"/>
                    <label for="materialquality">图书分类</label>
                    <input name="materialquality" id="materialQuality" type="text" class="form-control"/>
                    <label for="dynasty">图书页数</label>
                    <input name="dynasty" id="dynasty" type="text" class="form-control"/>
                    <label for="description">图书价格</label>
                    <input name="description" id="description" type="text" class="form-control"/>
                    <label for="picturepath">图片路径</label>
                    <input name="picturepath" id="picturePath" type="file" onchange="document.getElementById('textfield').value=document.getElementById('picturePath').value" class="form-control"/>
                    <label for="privilege">图书权限</label>
                    <select name="privilege" id="privilege" class="form-control">
                        <option value="开放" selected>开放</option>
                        <option value="隐藏">隐藏</option>
                    </select>
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
