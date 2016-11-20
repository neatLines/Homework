<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/10/31
  Time: 上午8:18
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@ page import="java.io.*,java.util.*" %>
<%
    String id = session.getId();
%>
<html>
<head>
    <meta charset="UTF-8">
    <title>购物车</title>
    <link rel="stylesheet prefetrch" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">

</head>
<body>
<script language="JavaScript" type="text/javascript">
    function show() {
        window.location.href="/show.jsp";
    }
</script>
<div class="container">
    <div class="jumbotron">
        <div class="row">
            <form name="info" action="Post.jsp">
            <center><h1>购物车</h1></center>
            <div class="checkbox">
                <center><label>
                    <input type="checkbox" name="goods" value="牙膏">
                    牙膏
                </label></center>
            </div>
            <div class="checkbox">
                <center><label>
                    <input type="checkbox" name="goods" value="牙刷">
                    牙刷
                </label></center>
            </div>
            <div class="checkbox">
                <center><label>
                    <input type="checkbox" name="goods" value="牙刷杯">
                    牙刷杯
                </label></center>
            </div>
            <div class="checkbox">
                <center><label>
                    <input type="checkbox" name="goods" value="洗面奶">
                        洗面奶
                    </label></center>
                </div>
                <div>
                    <center>
                    <button class="btn btn-success" type="submit" value="submit">submit</button>
                    </center>
                </div>

            </form><center>
            <button class="btn btn-danger" onclick="show()" value="查看购物车">查看购物车</button>
            </center>
        </div>
    </div>
</div>

</body>
</html>