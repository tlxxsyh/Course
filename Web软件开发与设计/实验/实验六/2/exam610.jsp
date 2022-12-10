<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    //重要：一定要保证字符编码
    request.setCharacterEncoding("utf-8");
    String recID = request.getParameter("recID");
    String book_name = request.getParameter("book_name");
    String book_type = request.getParameter("book_type");
    String book_price = request.getParameter("book_price");
    Connection con = null;
    Statement sql;
    ResultSet rs;
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
    }
    catch (Exception e){
        out.print("<h1>"+e);
    }
    String url = "jdbc:mysql://localhost:3306/test?useSSL=false&serverTimezone=UTC&characterEncoding=utf-8";
    String sql_user = "root";//数据库访问用户
    String sql_password = "1024";//数据库访问密码
    try{
        con = DriverManager.getConnection(url,sql_user,sql_password);
        sql=con.createStatement();
        //注意添加书名的时候是非数字串，因此要加上单引号
        String SQL = "INSERT INTO `book` values("+recID+",'"+book_name+"','"+book_type+"',"+book_price+")";
        int i = sql.executeUpdate(SQL);
        out.print("添加"+i+"条数据成功");
        con.close();    }
    catch (SQLException e){
        out.print("<h1>"+e);
    }
%>
