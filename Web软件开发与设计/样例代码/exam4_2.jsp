<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/18
  Time: 11:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>request其他方法</title>
</head>
<body>
<%
    String jsp=request.getServletPath();
    String webDir=request.getServletPath();
    String clientIP=request.getRemoteAddr();
    int serverPort=request.getServerPort();
%>
用户请求的页面：<%= jsp%><br>
web服务目录的名字：<%= webDir%><br>
用户的IP地址：<%= clientIP%><br>
服务器的端口号：<%= serverPort%>
</body>
</html>
