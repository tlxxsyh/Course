<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/18
  Time: 10:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>处理汉字信息</title>
</head>
<body>
<%
    //表单内容
    String content = "早上好，Good morning，おはようございます ，안녕하세요，อรุณสวัสดิ์，Доброе утро.";
%>
<form action="" method="post">
    <textarea name="language" id="tom" rows="3" cols="50">
        <%= content%>
    </textarea>
    <input type="submit" id="submit" name="submit" value="提交"/>
</form>
<%
    request.setCharacterEncoding("utf-8");
    String variousLanguage = request.getParameter("language");
    out.print(variousLanguage);
%>
</body>

</html>
