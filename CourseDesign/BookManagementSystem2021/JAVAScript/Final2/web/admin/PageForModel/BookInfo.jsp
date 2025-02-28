<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/22
  Time: 11:42
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
                <h4 class="modal-title" id="myModalLabel4">详情</h4>
            </div>
            <div class="modal-body">
                <form id="form2">
                    <%--@declare id="image2"--%><label for="specimennid2">图书编号</label>
                    <input name="specimennid2" id="specimennid2" type="text" class="form-control" disabled /><br>
                    <label for="specimenname2">图书名</label>
                    <input name="specimenname2" id="specimenname2" type="text" class="form-control" disabled/><br>
                    <label for="unearthedsite2">作者</label>
                    <input name="unearthedsite2" id="unearthedsite2" type="text" class="form-control" disabled/>
                    <label for="unearthedtime2">出版社</label>
                    <input name="unearthedtime2" id="unearthedtime2" type="text" class="form-control" disabled/>
                    <label for="materialquality2">出版时间</label>
                    <input name="materialquality2" id="materialquality2" type="text" class="form-control" disabled/>
                    <label for="dynasty2">图书分类</label>
                    <input name="dynasty2" id="dynasty2" type="text" class="form-control" disabled/>
                    <label for="enteredby2">图书页数</label>
                    <input name="enteredby2" id="enteredby2" type="text" class="form-control" disabled/>
                    <label for="enteringtime2">图书价格</label>
                    <input name="enteringtime2" id="enteringtime2" type="text" class="form-control" disabled/>
                    <label for="workplacename2">图书权限</label>
                    <input name="workplacename2" id="workplacename2" type="text" class="form-control" disabled/>
                    <label for="image2">图书图片</label><br>
                    <img style="width:170px; height:150px" id="picture" src=""/>
                    <br>

                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                </form>
            </div>
        </div>
    </div>
</div>
</body>
</html>
