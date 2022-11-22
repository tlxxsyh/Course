<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/21
  Time: 16:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>学生成绩表格</title>
</head>
<body>
<table border="1" style="width: 400px;height: 30px;">
    <tr style="background-color: #CC66FF" align="center">
        <td>学号</td>
        <td>姓名</td>
        <td>成绩</td>
    </tr>
    <%
        for (int i = 0; i < 5; i++) {
            if ((i + 1) % 2 == 1) {
    %>
    <tr style="background: #33FF66;height: 30px;" align="center">
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <%
    } else {
    %>
    <tr style="background: #FFFF99;height: 30px;" align="center">
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <%
            }
        }
    %>
</table>
</body>
</html>
