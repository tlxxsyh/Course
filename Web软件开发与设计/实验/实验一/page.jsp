<%--
  Created by IntelliJ IDEA.
  User: Shangyuhang
  Date: 2022/11/21
  Time: 16:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>表格</title>
</head>
<body>
<form action="">
    <table width="400" bgcolor="#ffffcc">
        <tr>
            <td bgcolor="#ffcc00" colspan="2" align="center">请完成以下表格</td>
        </tr>
        <tr>
            <td>姓名</td>
            <td><input type="text"></td>
        </tr>
        <tr>
            <td>密码</td>
            <td><input type="text"></td>
        </tr>
        <tr>
            <td>性别</td>
            <td><input type="radio" name="girl">女
                <input type="radio" name="boy">男
            </td>
        </tr>
        <tr>
            <td>职业</td>
            <td><select>
                <option>教育/研究</option>
                <option>等等</option>
            </select></td>
        </tr>
        <tr>
            <td>爱好</td>
            <td><input type="checkbox" name="music">音乐
                <input type="checkbox" name="dance">舞蹈
                <input type="checkbox" name="paint">绘画
            </td>
        </tr>
        <tr bgcolor="#ffcc00">
            <td colspan="2" align="center">填写完成后，选择下面的提交按钮提交表单</td>
        </tr>
        <tr>
            <td align="center" colspan="2"><input type="button" value="提交">
                <input type="reset" value="重置"></td>
        </tr>
    </table>
</form>
</body>
</html>
