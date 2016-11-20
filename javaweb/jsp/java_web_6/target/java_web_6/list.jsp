<%@ page import="com.panis.model.UserBean" %>
<%@ page import="java.util.List" %>
<%@ page import="com.panis.repositor.UserRegister" %><%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/11/19
  Time: 上午11:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>学生管理</title>

    <!-- 新 Bootstrap 核心 CSS 文件 -->
    <link rel="stylesheet" href="//cdn.bootcss.com/bootstrap/3.3.5/css/bootstrap.min.css">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
    <script src="//cdn.bootcss.com/html5shiv/3.7.2/html5shiv.min.js"></script>
    <script src="//cdn.bootcss.com/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
</head>

<%
    UserRegister userRegister = new UserRegister();
    List<UserBean> students = userRegister.findAll();
%>

<body>
<div class="container">
    <h1>学生管理</h1>
    <hr/>

    <h3>所有学生 <a href="/new.jsp" type="button" class="btn btn-primary btn-sm">添加</a></h3>

    <!-- 如果用户列表为空 -->
    <%
        if (students.isEmpty()) {
    %>
        <div class="alert alert-warning" role="alert">
            <span class="glyphicon glyphicon-info-sign" aria-hidden="true"></span>Student表为空，请<a href="/new.jsp" type="button" class="btn btn-primary btn-sm">添加</a>
        </div>
    <%
        }
    %>

            <!-- 如果用户列表非空 -->
    <%
        if (!students.isEmpty()) {
    %>
        <table class="table table-bordered table-striped">
            <tr>
                <th>link</th>
                <th>roles</th>
                <th>password</th>
                <th>uid</th>
                <th>username</th>
            </tr>

            <%
                for (int i = 0; i < students.size(); i++) {
                    UserBean student = students.get(i);
            %>
                <tr>
                    <td><%=student.getLink()%></td>
                    <th><%=student.getRoles()%></th>
                    <th><%=student.getPwd()%></th>
                    <th><%=student.getUid()%></th>
                    <th><%=student.getUsername()%></th>
                </tr>
            <%
                }
            %>
        </table>
    <%
        }
    %>
</div>

<!-- jQuery文件。务必在bootstrap.min.js 之前引入 -->
<script src="//cdn.bootcss.com/jquery/1.11.3/jquery.min.js"></script>

<!-- 最新的 Bootstrap 核心 JavaScript 文件 -->
<script src="//cdn.bootcss.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
</body>
</html>