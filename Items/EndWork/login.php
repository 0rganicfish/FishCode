<?php
session_start();
include("database/database.php");
//print_r($_POST);
if (isset($_POST["uid"])) {
    $uid = trim($_POST["uid"]);
    $password = trim($_POST["password"]);
    if (isset($_POST["checked"]))
        $checked = trim($_POST["checked"]);

    $sql = new SQL('localhost', 'root', 'fish', 'fishwork');
    $sql_str = "select `Username`, `Passwords`, `Power` from `users`
                where `Username`='$uid' and `Passwords`='$password';";
    $sql->Run($sql_str);
    $user = $sql->arr;

    if (!empty($user) || $password === $uid)
        header("location:index.html");
    else
        echo '<script>
                (() => {
                  const form = document.querySelector("form"),
                    tips = document.querySelectorAll(".tips");
                  form.addEventListener("submit", () => {
                    tips[1].style.color = "red";
                    return false;
                  });
                })();
            </script>';
}
?>

<!DOCTYPE html>
<html lang="zh">

<head>
    <meta charset="UTF-8"/>
    <meta name="viewport"
          content="width=device-width, initial-scale=1.0, minimum-scale=0.5, maximum-scale=2.0, user-scalable=yes"/>
    <script async src="styles/Template.js"></script>
    <script async src="styles/login.js"></script>
    <link rel="stylesheet" href="styles/login.css"/>
    <link rel="stylesheet" href="styles/Template.css"/>
    <link rel="icon" href="img/shark_50.png"/>
    <title>登录</title>
</head>

<body>
<div class="app">
    <div class="main">
        <div class="left">
            <div class="QRCode"></div>
            <div class="other-login">
                <span class="weChat"> </span>
                <span class="qq"> </span>
                <span class="todaySchool"> </span>
            </div>

            <div class="footer">
                <div class="introduce">
                    <span>By：<span class="link">有机鱼</span></span>
                </div>
                <div class="contact">
                    <span>联系方式：</span>
                    <span class="qqmail link">QQ邮箱</span>
                    <span> | </span>
                    <span class="weChat link">微信</span>
                </div>
            </div>
        </div>

        <div class="right">
            <div class="head">
                <img src="img/shark_100.png" width="10%" alt=""/>
                <div class="h1">学生成绩管理系统</div>
            </div>

            <div class="form">
                <form>
                    <label>
                        <div class="userid">
                            <input type="text" name="uid" placeholder="学号或教工号" id="uid"/>
                            <div class="tips">*请输入正确的10位学号或教工号</div>
                        </div>
                    </label>
                    <label>
                        <div class="password">
                            <input type="password" name="password" placeholder="密码" id="password"/>
                            <div class="tips">*请输入长度为8~16位的密码</div>
                        </div>
                    </label>
                    <div class="checkbox">
                        <label>
                            <input type="checkbox" name="checked" id="check"/>
                            <span class="remember">记住我<span class="tips">*不是自己的电脑不要勾选此项</span></span>
                        </label>
                    </div>
                    <div class="submit">
                        <input type="submit" value="登录"/>
                    </div>
                    <div class="forget">
                        <span class="link">忘记密码？无法验证？</span>
                        <div class="mes fore">那就试试密码为学号</div>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>
</body>

</html>