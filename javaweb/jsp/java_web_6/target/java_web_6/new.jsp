<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/11/19
  Time: 上午11:08
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- 上述3个meta标签*必须*放在最前面，任何其他内容都*必须*跟随其后！ -->
    <title>添加学生</title>

    <!-- 新 Bootstrap 核心 CSS 文件 -->
    <link rel="stylesheet" href="//cdn.bootcss.com/bootstrap/3.3.5/css/bootstrap.min.css">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
    <script src="//cdn.bootcss.com/html5shiv/3.7.2/html5shiv.min.js"></script>
    <script src="//cdn.bootcss.com/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
</head>
<body>
<div class="container">
    <h1>添加学生</h1>
    <hr/>
    <form action="/register.jsp" method="post">
        <div class="form-group">
            <label for="link">link:</label>
            <input type="number" class="form-control" id="link" name="link" placeholder="Enter Link:"/>
        </div>
        <div class="form-group">
            <label for="roles">Roles:</label>
            <input type="text" class="form-control" id="roles" name="roles" placeholder="Enter roles:"/>
        </div>
        <div class="form-group">
            <label for="pwd">Password:</label>
            <input type="password" class="form-control" id="pwd" name="pwd" placeholder="Enter password:"/>
        </div>
        <div class="form-group">
            <label for="uid">uid:</label>
            <input type="text" class="form-control" id="uid" name="uid" placeholder="Enter uid:"/>
        </div>
        <div class="form-group">
            <label for="username">username:</label>
            <input type="text" class="form-control" id="username" name="username" placeholder="Enter username:">
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-sm btn-success">提交</button>
        </div>
    </form>
</div>

<!-- jQuery文件。务必在bootstrap.min.js 之前引入 -->
<script src="//cdn.bootcss.com/jquery/1.11.3/jquery.min.js"></script>

<!-- 最新的 Bootstrap 核心 JavaScript 文件 -->
<script src="//cdn.bootcss.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
</body>
</html>