<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/10/24
  Time: ����8:31
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<html>
<head>
  <title>java ����������</title>
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
  String time = simpleDateFormat.format(currentTime).toString();   //�ŵ�ҳ���head��}

  int n_day = currentTime.getDay();
  String strDate = null;
  switch (n_day)
  {
    case 0:
      strDate = "������";
      break;
    case 1:
      strDate = "����һ";
      break;
    case 2:
      strDate ="���ڶ�";
      break;
    case 3:
      strDate = "������";
      break;
    case 4:
      strDate = "������";
      break;
    case 5:
      strDate = "������";
      break;
    case 6:
      strDate = "������";
      break;
    case 7:
      strDate = "������";
      break;
  }
  String noon = null;
  if (currentTime.getHours()<12) {
    noon = "����";
  } else {
    noon = "����";
  }
%>
<center>���ǵ�<%=count.intValue()%>��������</center>
<center>time:<%=time.toString()%></center>
<center>������<%=strDate.toString()%><%=noon.toString()%><%=currentTime.getHours()%>:<%=currentTime.getMinutes()%></center>
<center><label id="time">  </label></center>


<script language="JavaScript">
  document.all.time.innerHTML = new Date().toDateString();
</script>

</body>
</html>