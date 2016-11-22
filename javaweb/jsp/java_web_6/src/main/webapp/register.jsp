<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/11/19
  Time: 上午10:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page  contentType="text/html;charset=gb2312" pageEncoding="gb2312"
          import="com.panis.*" %>
<jsp:useBean id="userBean" class="com.panis.model.UserBean" scope="request">
    <jsp:setProperty name="userBean" property="*"/>
</jsp:useBean>
<jsp:useBean id="regist" class="com.panis.repositor.UserRegister" scope="request"/>
<html>
<head>
    <title> 用户信息注册页面</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>
<body>
<%
//    int id = request.getParameter("id");
    String link = request.getParameter("link");
    String password = request.getParameter("password");
    String roles = request.getParameter("roles");
    String uid = request.getParameter("uid");
    String userName = request.getParameter("username");
    userBean.setId(12);
    userBean.setLink(link);
    userBean.setPwd(password);
    userBean.setRoles(roles);
    userBean.setUid(uid);
    userBean.setUsername(userName);
    System.out.println(userName+password);
%>
<%try {
      regist.setUserBean(userBean);
      out.println(12);
      regist.regist();
      out.println("注册成功");}
  catch(Exception e) {
      out.println(e.getMessage());
  }
%>
<br>
<a href="login.jsp">返回</a>
</body>
</html>