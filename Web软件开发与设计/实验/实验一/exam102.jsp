<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/21
  Time: 15:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=gb2312" language="java" errorPage="exam103.jsp" %>
<%
    int dividend = 0;
    int divisor = 0;
    int result = 0;
    try {
        result = dividend / divisor;
    }
    catch (ArithmeticException zz){
        throw new ArithmeticException("除数不能为零！");
    }
%>
