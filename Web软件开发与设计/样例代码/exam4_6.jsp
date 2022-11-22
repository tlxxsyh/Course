<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/18
  Time: 23:10
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>表单</title>
</head>
<body>
填写姓名(<%=(String) session.getAttribute("name")%>):<br>
<form action="exam4_7.jsp" method="post" name="form">
    <input type="text" name="name">
    <input type="submit" value="确定"/>
</form>
</body>
</html>
