
/**
 * 2019/8/20更新
 * 分页函数
 * pno--页数
 * psize--每页显示记录数
 * 分页部分是从真实数据行开始，因而存在加减某个常数，以确定真正的记录数
 * 纯js分页实质是数据行全部加载，通过是否显示属性完成分页功能
 **/
function goPage(pno,psize){
    var itable = document.getElementById("idData");
    var num = itable.rows.length;//表格所有行数(所有记录数)
    //console.log(num);
    var totalPage = 0;//总页数
    var pageSize = psize;//每页显示行数
    //总共分几页 
    if(num/pageSize > parseInt(num/pageSize)){   
            totalPage=parseInt(num/pageSize)+1;   
       }else{   
           totalPage=parseInt(num/pageSize);   
       }   
    var currentPage = pno;//当前页数
    var startRow = (currentPage - 1) * pageSize+1;//开始显示的行  31 
       var endRow = currentPage * pageSize;//结束显示的行   40
       endRow = (endRow > num)? num : endRow;    //40
      // console.log(endRow);
       //遍历显示数据实现分页
    for(var i=1;i<(num+1);i++){    
        var irow = itable.rows[i-1];
        if(i>=startRow && i<=endRow){
            irow.style.display = "table-row";    
			//irow.cells.style.width = "11%"; 
        }else{
            irow.style.display = "none";
			//irow.cells.style.width = "11%"; 
        }
    }
    //var pageEnd = document.getElementById("pageEnd");
    var tempStr = "共"+num+"条数据 分"+totalPage+"页 当前第"+currentPage+"页&nbsp;&nbsp;";
    if(currentPage>1){
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-primary\" onClick=\"goPage("+(1)+","+psize+")\">首页</a>&nbsp;&nbsp;";
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-primary\" onClick=\"goPage("+(currentPage-1)+","+psize+")\">上一页</a>&nbsp;&nbsp;"
    }else{
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-metal\" >首页</a>&nbsp;&nbsp;";
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-metal\" >上一页</a>&nbsp;&nbsp;";   
    }

    if(currentPage<totalPage){
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-primary\" onClick=\"goPage("+(currentPage+1)+","+psize+")\">下一页</a>&nbsp;&nbsp;";
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-primary\" onClick=\"goPage("+(totalPage)+","+psize+")\">尾页</a>&nbsp;&nbsp;";
    }else{
        tempStr += "<a href=\"#\" class=\"btn btn-sm btn-metal\" >下一页</a>&nbsp;&nbsp;";
       tempStr += "<a href=\"#\" class=\"btn btn-sm btn-metal\" >尾页</a>&nbsp;&nbsp;";   
    }
	
	tempStr +="跳转至";
	tempStr +="<select class='' style='width:60px' οnchange='goPage(this.value,"+psize+")'>"; 
	tempStr +="<option></option>"
	for(var j=1;j<=totalPage;j++){
		tempStr +="<option  value='"+j+"' >第"+ j +"页</option>";
	}
	tempStr +="</select>";
    document.getElementById("barcon").innerHTML = tempStr;
    
}
