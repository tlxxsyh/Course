<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>test</title>
</head>
<body>
<form action="" method="post">
    <p>请输入几个数字，以,分割：</p>
    <input type="text" name="num" id="num"><br>
    <input type="submit" name="submit" id="submit" value="确定">
</form>
</body>
</html>
<%
    String s = request.getParameter(",");
    if (s != null) {//避免NullPointerException
        String ss[] = s.split(",");
        int sum = 0;
        out.print("你输入的数字是：");
        for (int i = 0; i < ss.length; i++) {
            out.print(ss[i] + " ");
            sum += Integer.parseInt(ss[i]);
        }
        out.print("<br>" + "数字的和是" + sum);
    }
%>
