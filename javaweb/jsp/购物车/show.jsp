<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/11/7
  Time: 上午9:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <meta charset="UTF-8">
    <title>showCar</title>
</head>
<body>
<%
    String name1 = (String)session.getValue("牙刷"); //从session取出关键字为theusername的对象
%>
牙刷：<%=name1%>
<%
    String name2 = (String)session.getValue("牙膏"); //从session取出关键字为theusername的对象
%>
牙膏：<%=name2%>
<%
    String name3 = (String)session.getValue("牙刷杯"); //从session取出关键字为theusername的对象
%>
牙刷杯：<%=name3%>
<%
    String name4 = (String)session.getValue("洗面奶"); //从session取出关键字为theusername的对象
%>
洗面奶：<%=name4%>
</body>
</html>
