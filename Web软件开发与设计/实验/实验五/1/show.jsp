<%@ page import="java.util.*" %>
<%
    ArrayList list =(ArrayList) session.getAttribute("rnd");
    Iterator it = list.iterator();
    while(it.hasNext()){
        String temp = (String) it.next();
        out.print(temp+"<br>");
    }
%>
