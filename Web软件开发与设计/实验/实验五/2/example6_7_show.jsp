<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String msg = request.getParameter("num");
    int num;
    if (msg!=null){
        num = Integer.parseInt(msg);
        out.print(num);
    }
%>
