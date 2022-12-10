<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>index.jsp</title>
</head>
<body>
<form action="exam610.jsp" method="post">
    请录入要增加的图书信息<br>
    请输入书号：<input type="text" name="recID"><br>
    请输入书名：<input type="text" name="book_name"><br>
    请输入书的类型：
    <select name="book_type">
        <option>幼儿读物</option>
        <option>侦探小说</option>
        <option>哈利波特系列</option>
    </select><br>
    请输入书的单价：<input type="text" name="book_price"><br>
    <input type="submit" value="提交">
</form>
</body>
</html>
