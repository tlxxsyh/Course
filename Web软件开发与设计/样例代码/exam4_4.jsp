<%@ page import="java.awt.image.BufferedImage" %>
<%@ page import="java.awt.*" %>
<%@ page import="java.awt.geom.Ellipse2D" %>
<%@ page import="java.io.OutputStream" %>
<%@ page import="javax.imageio.ImageIO" %><%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/18
  Time: 21:43
  To change this template use File | Settings | File Templates.
  注：我也不知道为啥这个页面不能画图，就很奇怪
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%!
    void drawCircle(double r, HttpServletResponse response) {
        int width = 320, height = 300;
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics g = image.getGraphics();
        g.fillRect(0, 0, width, height);
        Graphics2D g_2d = (Graphics2D) g;
        Ellipse2D ellipse = new Ellipse2D.Double(160 - r, 150 - r, 2 * r, 2 * r);
        g_2d.setColor(Color.blue);
        g_2d.draw(ellipse);
        try {
            OutputStream outClient = response.getOutputStream();
            boolean boo = ImageIO.write(image, "jpeg", outClient);
        } catch (Exception exp) {
        }
    }

    double getArea(double r) {
        return Math.PI * r * r;
    }
%>
<%
    request.setCharacterEncoding("utf-8");
    String submitValue = request.getParameter("submit");
    String radius = request.getParameter("radius");
    double r = Double.parseDouble(radius);
    if (submitValue.equals("提交看圆形")) {
        response.setContentType("image/jpeg");//response更改MIME类型
        drawCircle(r, response);//绘制圆
    }
%>
<html>
<head>
    <title>出现！</title>
</head>
<body>
<%
    double area = getArea(r);
    String result = String.format("%.2f",area);
%>
半径：<%= result%>
</body>
</html>
