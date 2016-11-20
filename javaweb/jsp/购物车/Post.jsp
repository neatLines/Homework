<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/10/31
  Time: 上午9:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html;charset=utf-8"%>
<%@ page import="java.util.*,java.io.*" %>
<%
    String select[] = request.getParameterValues("goods");
    if (select != null && select.length != 0) {
        for (int i = 0; i < select.length; i++) {
            session.setAttribute(select[i],"checked");
            out.println(select[i]);
        }
    }
%>
<html>
<head>
    <meta charset="UTF-8">

    <title>信息表</title>
</head>

<body>
提交成功
<script>
    window.setTimeout("window.location='index.jsp'",2000);
</script>
</body>
</html>