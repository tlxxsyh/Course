package com.syh;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "randomNumber", value = "/randomNumber")
public class randomNumber extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        HttpSession session = request.getSession(true);
        ArrayList list = new ArrayList();
        for(int i = 0;i<10;i++){
            double number = Math.random();
            String temp = String.valueOf(number);
            list.add(temp);
        }
        session.setAttribute("rnd",list);
        response.sendRedirect("operation/five/show.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }
}
