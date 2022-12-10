<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    int user_found=0;//是否找到匹配的用户名与密码
    String name = request.getParameter("name");
    String password = request.getParameter("password");
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
        //查询用户名与密码
        String SQL = "select `name`,`password` from user;";
        rs = sql.executeQuery(SQL);
        //逐个匹配
        while(rs.next()){
            if(rs.getString(1).equals(name)&&rs.getString(2).equals(password)){
                out.print("欢迎访问本页面");
                user_found=1;//标记找到了
                break;
            }
        }
        //如果未找到，那么重定向回a.jsp，并传一个密码错误的值
        if(user_found==0){
            response.sendRedirect("a.jsp?msg=mistake");
        }
        con.close();    }
    catch (SQLException e){
        out.print("<h1>"+e);
    }
%>
