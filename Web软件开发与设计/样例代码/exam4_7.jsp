<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/18
  Time: 23:12
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    String name = request.getParameter("name");
    if((name==null) || (name.length()==0)){
        response.sendRedirect("exam4_6.jsp");
        String str = (String) session.getAttribute("name");//这个仍然会被执行
        session.setAttribute("name","李四"+str);//这个仍然会被执行
    }
%>
欢迎<%=name%>访问网页。
</body>
</html>
