<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 12:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<!--模态框 ，批量导入-->
<div class="modal fade" id="bulkAddModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title" id="myModalLabel23">批量导入</h4>
            </div>
            <div class="modal-body">
                <form id="form0" method="post" action="${pageContext.request.contextPath}/BulkAddBookByStaff">
                    <label for="excelpath">导入excel</label>
                    <input name="excelpath" id="excelPath" type="file" onchange="document.getElementById('textfield').value=document.getElementById('excelPath').value" class="form-control"/>
                    <br>
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                    <input type="submit" class="btn btn-default" value="导入" />
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
