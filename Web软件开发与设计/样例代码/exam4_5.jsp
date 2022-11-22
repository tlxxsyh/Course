<%@ page import="java.time.LocalTime" %><%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/18
  Time: 22:38
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
现在的时间是：<br>
<%
    out.println(""+ LocalTime.now());
    response.setHeader("Refresh","5");
%>
</body>
</html>
