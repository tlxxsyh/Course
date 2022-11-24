<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/19
  Time: 12:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>首页</title>
</head>
<body>
Hello,World!<br>
<%
    String id = session.getId();
    out.print("session对象的ID是<br>" + id);
    String str = response.encodeRedirectURL("exam4_9.jsp");
%>
<form action=<%=str%> method="post">
    <input type="submit" value="去另一个页面">
</form>
</body>
</html>
