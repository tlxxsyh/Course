# 说明

## 1
exam102.jsp和exam103.jsp是第一个小实验的代码，运行第一个jsp文件能访问到第二个文件即为成功

## 2
page.jsp是实现一个下面的表格

<form>
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

## 3
student.jsp是实现一个渐变的表格（markdown文件无法实现jsp代码功能）
