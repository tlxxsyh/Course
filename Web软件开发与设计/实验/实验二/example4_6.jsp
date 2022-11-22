<%@ page language="java" contentType="text/html; charset=utf-8"
         pageEncoding="utf-8" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Insert title here</title>
</head>
<style>
    #tom {
        font-family: 宋体;
        font-size: 26;
        color: blue
    }
</style>
<% String music = request.getParameter("music");
    String pic = request.getParameter("pic");
    String onOrOff = request.getParameter("R");
    if (music == null) music = "";
    if(pic==null)pic="";
    if (onOrOff == null) onOrOff = "off";

%>
<body id=tom background="image/<%=pic %>">
<form action="" method=post>
    <b>选择音乐:<br>
        <select id=tom name="music">
            <option selected value="back1.mp3">绿岛小夜曲
            <option selected value="back2.mp3">我是一片云</option>
            <option selected value="back3.mp3">红河谷</option>
        </select>
        <input type="radio" name="R" value="on"/>打开
        <input type="radio" name="R" value="off"/>关闭
        <br></b>选择背景图像：<br>
    <select id=tom name="pic" size=2>
        <option selected value="back1.jpg">荷花图</option>
        <option selected value="back2.jpg">玫瑰图</option>
        <option selected value="back3.jpg">校园图</option>
    </select><br>
    <input type="submit" name="submit" value="提交"/>
</form>
<%
    if (onOrOff.equals("on")) {
%>    <br>
<embed src="sound/<%=music %>" height=50/>
<% }
%>
</body>
</html>
