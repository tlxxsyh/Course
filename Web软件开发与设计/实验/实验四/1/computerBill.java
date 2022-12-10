package com.syh;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class computerBill extends HttpServlet{
    public void init(ServletConfig config)throws ServletException{
        super.init(config);
    }
    public void service(HttpServletRequest request,HttpServletResponse response)throws IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out=response.getWriter();
        out.println("<html><body bgcolor=yellow>");
        String discountMess=request.getParameter("discount");
        double discount=Double.parseDouble(discountMess);
        String fish=request.getParameter("fish");
        String duck=request.getParameter("duck");
        String shrimp=request.getParameter("shrimp");
        if(fish==null||duck==null||shrimp==null){
            out.print("账单不完整");
            return;
        }
        Double fish1=Double.parseDouble(fish);
        Double duck1=Double.parseDouble(duck);
        Double shrimp1=Double.parseDouble(shrimp);
        double bill=fish1+duck1+shrimp1;
        double billDiscount=bill*(discount/10);
        out.print("消费："+bill+"元"+","+"优惠:"+discount+"折"+"<br>后的金额是："+billDiscount+"元");
        out.print("</body><html>");
    }
}
