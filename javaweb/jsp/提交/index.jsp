<%--
  Created by IntelliJ IDEA.
  User: fuyipeng
  Date: 2016/10/31
  Time: 上午8:18
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>emailLogin</title>
    <link rel="stylesheet prefetrch" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
</head>
<body>
<script type="text/javascript">
    function submit() {
        var info = document.info;
        var x = document.getElementById('in1').value;
        var pass = document.getElementById('ps1').value;
        var pass2 = document.getElementById('ps2').value;
        var email = document.getElementById('email').value;
        var phoneNumber = document.getElementById('phoneNumber').value;
        var date = document.getElementById('birthday').value;
        var ReUs=/^[a-zA-Z].*/;
        var ReEm=/^(\w)+(\.\w+)*@(\w)+((\.\w+)+)$/;;
        var ReDa=/^([0-9]{4})+\-([0-9]{2})/;
        if (x.length<6||x.length>10||!ReUs.test(x)) {
            var y = document.getElementById("text1");
            y.style.color="red";
            info.Post.focus();
        }
        if (pass!=pass2||pass==""||pass2=="") {
            var y = document.getElementById("text2");
            y.style.color="red";
            info.Post.focus();
        }
        if (!ReEm.test(email)) {
            var y = document.getElementById('text3');
            y.style.color="red";
            info.Post.focus();
        }
        if (!ReDa.test(date)) {
            var y = document.getElementById('text4');
            y.style.color="red";
            info.Post.focus();
        }
        if (phoneNumber.length!=11) {
            var y = document.getElementById('text5');
            y.style.color="red";
            info.Post.focus();
        }
        info.submit();
    }

    function reset() {
        var x = document.getElementsByTagName('input');
        for (var i = x.length - 1; i >= 0; i--) {
            x[i].value="";
        }
        x = document.getElementsByTagName('textarea');
        for (var i = x.length - 1; i >= 0; i--) {
            x[i].value="";
        }
    }
</script>
<div class="container">
    <div class="jumbotron">
        <div class="row">
            <form name="info" action="Post.jsp" method="post">
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <h4>
                    <font style="color: red">*</font>用户名:
                    <input id="in1" type="text" name="username">
                </h4>
                <div class="coption col-xs-12 col-sm-10 col-sm-offset-1 col-md-8">
                    <font id="text1" style="color: grey"> 长度6-10位以字母开头</font>
                </div>
                <br>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <h4><font style="color: red">*</font>密码:
                    <input id="ps1" type="password" name="password">
                </h4>
                <br>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <h4><font style="color: red">*</font>确认密码:
                    <input id="ps2" type="password" name="passwordCont">
                </h4>
                <div class="coption col-xs-12 col-sm-10 col-sm-offset-1 col-md-8">
                    <font id="text2" style="color: grey"> 密码必须相同且不能为空 </font>
                </div>
                <br>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <div class="col-xs-4">
                    <h4><font style="color: red">*</font>籍贯:</h4>
                </div>
                <div class="col-xs-4">
                    <select name="native" class="form-control">
                        <option>北京</option>
                        <option>上海</option>
                        <option>广州</option>
                        <option>深圳</option>
                        <option>杭州</option>
                    </select>
                </div>
                <br>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <div class="col-xs-4">
                    <h4><font style="color: red">*</font>性别:</h4>
                </div>
                <div class="col-xs-4">
                    <select name="sex" class="form-control">
                        <option>男</option>
                        <option>女</option>
                        <option>保密</option>
                    </select>
                </div>
                <br>
            </div>

            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <h4><font style="color: red">*</font>出生年月:
                    <input id="birthday" type="date" name="birthday">
                </h4>
                <div class="coption col-xs-12 col-sm-10 col-sm-offset-1 col-md-8">
                    <font id="text4" style="color: grey"> 符合日期格式(yyyy-mm)</font>
                </div>
                <br>
            </div>


            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                    <div class="form-group">
                        <h4><font style="color: red">*</font>个人爱好:</h4>
                        <textarea id="hobby" name="hobby" class="form-control" rows="3"></textarea>
                    </div>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                    <div class="form-group">
                        <h4><font style="color: red">*</font>个人介绍:</h4>
                        <textarea id="profile" name="profile" class="form-control" rows="3"></textarea>
                    </div>
            </div>

            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <h4><font style="color: red">*</font>手机号码:
                    <input id="phoneNumber" type="text" name="phone_number">
                </h4>
                <div class="coption col-xs-12 col-sm-10 col-sm-offset-1 col-md-8">
                    <font id="text5" style="color: grey"> 符合手机号格式</font>
                </div>
                <br>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <h4><font style="color: red">*</font>邮箱:
                    <input id="email" type="email" name="e-mail">
                </h4>
                <div class="coption col-xs-12 col-sm-10 col-sm-offset-1 col-md-8">
                    <font id="text3" style="color: grey"> 符合邮箱格式</font>
                </div>
                <br>
            </div>
            <div class="col-xs-12 col-sm-10 col-sm-offset-1 col-md-8 col-md-offset-2">
                <button class="btn btn-success" onclick="submit()">提交</button>
                <button class="btn btn-danger" onclick="reset()">重置</button>
            </div>
            </form>
        </div>
    </div>
</div>
</body>
</html>