<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/21
  Time: 17:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>表单</title>
</head>
<body>
<form action="exam201.jsp" method="post">
    会员注册信息<br>
    用户名：<input type="text" name="name"><br>
    密码：<input type="password" name="pwd"><br>
    性别：<input type="radio" name="sex" value="男"/> 男
    <input type="radio" name="sex" value="女"/> 女 <br>
    爱好：<input type="checkbox" name="hobby" value="篮球"/> 篮球
    <input type="checkbox" name="hobby" value="排球"/> 排球
    <input type="checkbox" name="hobby" value="足球"/> 足球<br>
    开户行：<select name="bank">
    <option>工商银行</option>
    <option>农业银行</option>
    <option>交通银行</option>
    <option>招商银行</option>
</select><br>
    留言：<textarea name="text_leave" rows=3 cols=10></textarea><br>
    <input type="submit" value="提交"/>
</form>
</body>
</html>
