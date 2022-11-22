<%@ page contentType="text/html" %>
<%@ page pageEncoding="utf-8" %>
<style>
    #tom {
        font-family: 宋体;
        font-size: 26px;
        color: blue
    }</style>
<html>
<body id="tom" bgcolor=#ffccff>
<form action="example4_5_receive.jsp" method=post id="tom">
    <br>音乐:
    <input type="radio" name="R" value="on"/>打开
    <input type="radio" name="R" value="off" checked="default">关闭
    <br>哪些是奥运会项目:<br>
    <input type="checkbox" name="item" value="A" algin="top"/>足球
    <input type="checkbox" name="item" value="B" algin="top"/>围棋
    <input type="checkbox" name="item" value="C" algin="top"/>乒乓球
    <input type="checkbox" name="item" value="D" algin="top"/>篮球
    <input type="hidden" value="我是球迷，但我不会踢球" name="secret"/>
    <br><input type="submit" id="tom" name="submit" value="提交"/>
    <input type="reset" id="tom" value="重置"/>
</form>
</body>
</html>
