<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/19
  Time: 12:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>另一个页面</title>
</head>
<body>
(*^▽^*)
<%
    String id = session.getId();
    out.print("session对象的ID是<br>" + id);
%>
</body>
</html>
