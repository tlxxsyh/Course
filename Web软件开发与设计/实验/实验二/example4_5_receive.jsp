<%@ page import="java.util.Arrays" %>
<%@ page contentType="text/html" %>
<%@ page pageEncoding="utf-8" %>
<%@ page import="java.util.Arrays" %>
<%! public boolean isSame(String[] a, String[] b) {
    Arrays.sort(a);
    Arrays.sort(a);
    return Arrays.equals(a, b);
}
%>
<HTML>
<body bgcolor=white>
<p style="font-family:宋体;font-size:36px;color:blue">
    <%
        String answer[] = {"A", "C", "D"};
        request.setCharacterEncoding("utf-8");
        String onOrOff = request.getParameter("R");
        String secretMess = request.getParameter("secret");
        String itemName[] = request.getParameterValues("item");
        out.println("<br>是否打开音乐:" + onOrOff);
        out.println("<br>您的答案");
        if (itemName == null) {
            out.print("没给答案");
        } else {
            for (int k = 0; k < itemName.length; k++) {
                out.print(" " + itemName[k]);
            }
            if(isSame(itemName,answer)){
                out.print("<br>回答正确.");
            }
        }
        out.println("<br>提交的隐藏信息:" + secretMess);
        if (onOrOff.equals("on")) {
    %> <br>
    <embed src="sound/back.mp3"/>
    <% }
    %>
</p>
</body>
</HTML>
