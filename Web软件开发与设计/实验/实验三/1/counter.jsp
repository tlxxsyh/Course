<%@ page pageEncoding="UTF-8"%>
<body>
<%
    int n = 0;
    String counter = (String) application.getAttribute("counter");
    if(counter!=null)
        n=Integer.parseInt(counter);
    if(session.isNew()){
        n=n+1;
    }
    out.print("您是第"+n+"位访客");
    counter=String.valueOf(n);
    application.setAttribute("counter",counter);
%>
</body>
