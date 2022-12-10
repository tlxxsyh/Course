<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>a.jsp</title>
    <script>
        function click_submit() {
            let name = document.getElementById("name");
            let password = document.getElementById("password");
            if(name.value == ""||password.value == ""){
                alert("用户名或密码为空！");
            }
            else{
                document.getElementById("my_form").submit();
            }
        }
    </script>
</head>
<body>
<form action="b.jsp" method="post" id="myform">
    用户名：<input type="text" name="name" id="name"><br>
    密码：<input type="password" name="password" id="password"><br>
    <button onclick="click_submit()">提交</button>
</form>
</body>
</html>
<%
    String msg=request.getParameter("msg");
    if(msg==null){
        msg="0";
    }
    if(msg.equals("mistake")){
        out.print("密码错误！");
    }
%>
