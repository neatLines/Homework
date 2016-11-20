<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/10/31
  Time: 上午9:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html;charset=utf-8"%>
<%@ page import="java.util.*,java.io.*" %>
<html>
<head><title>信息表</title></head>
<body>
<!--对提交到该JSP页面含有中文的信息实现以中文正常显示-->
<%request.setCharacterEncoding("utf-8");%>
<center>
    <table width="400">
        <tbody>
        <tr>
            <td><b>注册名称</b></td>
            <!--从用户提交表单获取注册名称-->
            <td><%=request.getParameter("username")%></td>
        </tr>
        <tr>
            <td><b>登陆密码</b></td>
            <!--从用户提交表单获取登录密码-->
            <td><%=request.getParameter("password")%></td>
        </tr>
        <tr>
            <td><b>籍贯</b></td>
            <!--从用户提交表单获取真是姓名-->
            <td><%=request.getParameter("native")%></td>
        </tr>
        <tr>
            <td><b>性别</b></td>
            <!--从用户提交表单获取性别-->
            <td>
                <%=request.getParameter("sex")%>
            </td>
        </tr>
        <tr>
            <td><b>出生日期</b></td>
            <!--从用户提交表单获取出生日期-->
            <td><%=request.getParameter("birthday")%></td>
        </tr>
        <tr>
            <td><b>个人爱好</b></td>
            <!--从用户提交表单获取联系电话-->
            <td><%=request.getParameter("hobby")%></td>
        </tr>
        <tr>
            <td><b>个人介绍</b></td>
            <!--从用户提交表单获取联系电话-->
            <td><%=request.getParameter("profile")%></td>
        </tr>
        <tr>
            <td><b>联系电话</b></td>
            <!--从用户提交表单获取联系电话-->
            <td><%=request.getParameter("phone_number")%></td>
        </tr>
        <tr>
            <td><b>E-mail</b></td>
            <td><%=request.getParameter("e-mail")%></td>
        </tr>

        </tbody>
    </table>
</center>
</body>
</html>