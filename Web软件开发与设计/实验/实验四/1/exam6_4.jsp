<%@ page language="java" contentType="text/html; charset=utf-8"
         pageEncoding="utf-8" %>
<style>
    .textStyle {
        font-family: 宋体;
        font—size: 36;
        color: blue;
    }
</style>
<HTML>
<body bgcolor="#FFCCFF">
<form action="/computerBill?discount=6" class="textStyle" method=post>
    输入账单：<br>
    剁椒鱼头：<input type="text" name="fish" value=34>元<br>
    烤鸭：<input type="text" name="duck" value=78>元<br>
    红焖大虾：<input type="text" name="shrimp" value=120>元<br>
    <input type="submit" class="textStyle" value="提交">
</form>
</body>
</HTML>
