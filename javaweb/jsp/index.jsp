<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/10/24
  Time: 上午8:31
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<html>
<head>
  <title>java 计数器程序</title>
</head>
<body>
<%
  if (application.getAttribute("count") == null) {
    application.setAttribute("count", new Integer(0));
  }
  Integer count = (Integer) application.getAttribute("count");
  application
          .setAttribute("count", new Integer(count.intValue() + 1));
  count = (Integer) application.getAttribute("count");

  java.text.SimpleDateFormat simpleDateFormat = new java.text.SimpleDateFormat(
          "yyyy-MM-dd HH:mm:ss");
  java.util.Date currentTime = new java.util.Date();
  String time = simpleDateFormat.format(currentTime).toString();   //放到页面的head中}

  int n_day = currentTime.getDay();
  String strDate = null;
  switch (n_day)
  {
    case 0:
      strDate = "星期日";
      break;
    case 1:
      strDate = "星期一";
      break;
    case 2:
      strDate ="星期二";
      break;
    case 3:
      strDate = "星期三";
      break;
    case 4:
      strDate = "星期四";
      break;
    case 5:
      strDate = "星期五";
      break;
    case 6:
      strDate = "星期六";
      break;
    case 7:
      strDate = "星期日";
      break;
  }
  String noon = null;
  if (currentTime.getHours()<12) {
    noon = "上午";
  } else {
    noon = "下午";
  }
%>
<center>这是第<%=count.intValue()%>个访问者</center>
<center>time:<%=time.toString()%></center>
<center>今天是<%=strDate.toString()%><%=noon.toString()%><%=currentTime.getHours()%>:<%=currentTime.getMinutes()%></center>
<center><label id="time">  </label></center>


<script language="JavaScript">
  document.all.time.innerHTML = new Date().toDateString();
</script>

</body>
</html>