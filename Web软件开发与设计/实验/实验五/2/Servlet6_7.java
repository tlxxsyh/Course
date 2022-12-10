package com.syh;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

public class Servlet_6_7 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String msg = request.getParameter("num");
        int num = Integer.parseInt(msg);
        RequestDispatcher dispatcher;
        if(num<0){
            response.sendRedirect("operation/five/example6_7_show.jsp");
        }
        else if(num>0){
            dispatcher = request.getRequestDispatcher("operation/five/example6_7_show.jsp");
            dispatcher.forward(request,response);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
