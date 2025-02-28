<%--
  Created by IntelliJ IDEA.
  User: 47013
  Date: 2023/11/23
  Time: 14:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>生成图表</title>
</head>
<body>
<script src="http://echarts.baidu.com/build/dist/echarts.js"></script>
<script type="text/javascript">
    // 路径配置
    require.config({
        paths: {
            echarts: 'http://echarts.baidu.com/build/dist'
        }
    });

    // 使用
    require(
        [
            'echarts',
            'echarts/chart/bar', // 使用柱状图
            'echarts/chart/line' // 使用折线图
        ],
        function (ec) {
            // 基于准备好的dom，初始化echarts图表
            var myChart = ec.init(document.getElementById('ec1'));
            var myChart2 = ec.init(document.getElementById('ec2'));

            var option = { //具体细节的描述
                title: {
                    text: '近年借阅情况统计（年）',
                    textStyle: {
                        fontSize: 14,
                        fontStyle: 'normal',
                        fontWeight: 'bold',
                    },
                },
                tooltip: {
                    trigger: 'axis'
                },
                legend: {
                    data: ['流/借入', '流/借出']
                },
                toolbox: { //可以选择具体数据，柱状图，折线图，还原，保存图片的的切换选择
                    show: true,
                    feature: {
                        magicType: {
                            show: true,
                            type: ['line', 'bar'] //可选折线图和柱状图
                        },
                        restore: {
                            show: true  //恢复默认
                        },
                    }
                },
                calculable: true,
                xAxis: [{
                    type: 'category',
                    data: [<%=nowyear-4%>, <%=nowyear-3%>, <%=nowyear-2%>,<%=nowyear-1%>,<%=nowyear%>],
                    name: '年份',
                    position: 'left'
                }],
                yAxis: [{
                    type: 'value',
                    name: '数量',
                    position: 'left'
                }],
                series: [{
                    name: '流/借入',
                    type: 'line',// bar
                    data: [<%=borrowByYear[0]%>,<%=borrowByYear[1]%>,<%=borrowByYear[2]%>,<%=borrowByYear[3]%>,<%=borrowByYear[4]%>],
                    color: '#CC0066'
                },
                    {
                        name: '流/借出',
                        type: 'line',//bar
                        data: [<%=lendByYear[0]%>,<%=lendByYear[1]%>,<%=lendByYear[2]%>,<%=lendByYear[3]%>,<%=lendByYear[4]%>],
                        color: '#009999'
                    }
                ]
            };

            var option2 = {
                title: {
                    text: '近年借阅情况统计（月）',
                    textStyle: {
                        fontSize: 14,
                        fontStyle: 'normal',
                        fontWeight: 'bold',
                    },
                },
                tooltip: {
                    trigger: 'axis'
                },
                legend: {
                    data: ['流/借入', '流/借出']
                },
                toolbox: {
                    show: true,
                    feature: {
                        magicType: {
                            show: true,
                            type: ['line', 'bar']
                        },
                        restore: {
                            show: true
                        }
                    }
                },
                calculable: true,
                xAxis: [{
                    type: 'category',
                    data: ['1', '2', '3', '4','5','6','7','8','9','10','11','12'],
                    name: '月份',
                    position: 'left'
                }],
                yAxis: [{
                    type: 'value',
                    name: '数量',
                    position: 'left'
                }],
                series: [{
                    name: '流/借入',
                    type: 'bar',
                    data: [<%=borrowByMonth[0]%>,<%=borrowByMonth[1]%>,<%=borrowByMonth[2]%>,
                        <%=borrowByMonth[3]%>,<%=borrowByMonth[4]%>,<%=borrowByMonth[5]%>,
                        <%=borrowByMonth[6]%>,<%=borrowByMonth[7]%>,<%=borrowByMonth[8]%>,
                        <%=borrowByMonth[9]%>,<%=borrowByMonth[10]%>,<%=borrowByMonth[11]%>,],
                    color: '#CC0066'
                },
                    {
                        name: '流/借出',
                        type: 'bar',
                        data: [<%=lendByMonth[0]%>,<%=lendByMonth[1]%>,<%=lendByMonth[2]%>,
                            <%=lendByMonth[3]%>,<%=lendByMonth[4]%>,<%=lendByMonth[5]%>,
                            <%=lendByMonth[6]%>,<%=lendByMonth[7]%>,<%=lendByMonth[8]%>,
                            <%=lendByMonth[9]%>,<%=lendByMonth[10]%>,<%=lendByMonth[11]%>,],
                        color: '#009999' // 设置颜色
                    }
                ]
            };


            // 为echarts对象加载数据
            myChart.setOption(option);
            myChart2.setOption(option2);
        }
    );
</script>
</body>
</html>
