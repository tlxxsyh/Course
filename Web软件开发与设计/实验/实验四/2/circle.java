package com.syh;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class circle extends HttpServlet{
    HttpServletRequest request;
    HttpServletResponse response;
    public void init(ServletConfig config)throws ServletException{
        super.init(config);
    }
    public void service(HttpServletRequest request,HttpServletResponse response)throws IOException {
        this.request=request;
        this.response=response;
        request.setCharacterEncoding("utf-8");
        String mess=request.getParameter("mess");
        String radius=request.getParameter("radius");
        mess.equals("area");
        getArea(Double.parseDouble(radius));
    }

    private void getArea(double r)throws IOException {
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out=response.getWriter();
        double area=Math.PI*r*r;
        String result=String.format("%.2f",area);
        out.print("<h2>半径"+r+"圆的面积(保留两位小数):<br>");
        out.print(result);
        out.print("</h2></body></html>");
    }
}
