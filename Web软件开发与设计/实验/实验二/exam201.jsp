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
    <title>exam201.jsp</title>
</head>
<body>
</body>
</html>
<%
    request.setCharacterEncoding("utf-8");
    String name = request.getParameter("name");
    String sex = request.getParameter("sex");
    String pwd =request.getParameter("pwd");
    String bank =request.getParameter("bank");
    String hobby[] = request.getParameterValues("hobby");
    String leave_text = request.getParameter("text_leave");
    if (name == null || name.length() == 0)
        out.print("用户名为空<br>");
    else
        out.print("用户名：" + name + "<br>");
    if (pwd == null || pwd.length() == 0)
        out.print("密码为空<br>");
    else
        out.print("密码：" + pwd + "<br>");
    if (sex == null || sex.length() == 0)
        out.print("性别为空<br>");
    else
        out.print("性别：" + sex + "<br>");
    if (bank == null || bank.length() == 0)
        out.print("开户行为空<br>");
    else
        out.print("开户行：" + bank + "<br>");
    if (hobby == null || hobby.length == 0)
        out.print("爱好为空<br>");
    else{
        out.print("爱好：");
        for (int i=0 ;i< hobby.length;i++){
            out.print(" "+hobby[i]);
        }
        out.print("<br>");
    }
    if (leave_text == null || leave_text.length() == 0)
        out.print("留言为空<br>");
    else
        out.print("留言：" + leave_text + "<br>");
%>
