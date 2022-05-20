<?php
session_start();
include("database/database.php");
$password = $checked = $uid = "";

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

    if (!empty($user) || $password === $uid) {
        $_SESSION = [
            "uid" => $uid,
            "logged" => true,
            "power" => $user[0]["Power"]
        ];

        if ($checked === "on") {
            setcookie("uid", $uid, time() + 3600 * 24 * 365);
        } else {
            setcookie("uid", $uid);
        }

        if ($_SESSION["power"])
            header("location:root.php");
        else
            header("location:../EndWork/");

    } else {
        echo "<script>alert('密码错误')</script>";
    }
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
    <div class="back"></div>
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
                    <div class="userid">
                        <label><input type="text" name="uid" placeholder="学号或教工号"/> </label>
                        <div class="tips">*请输入正确的10位学号或教工号</div>
                    </div>
                    <div class="password">
                        <label><input type="password" name="password" placeholder="密码"/> </label>
                        <div class="tips">*请输入长度为8~16位的密码</div>
                    </div>
                    <label>
                        <div class="checkbox">
                            <input type="checkbox" name="checked"/>
                            <span class="remember">记住我<span class="tips">*不是自己的电脑不要勾选此项</span></span>
                        </div>
                    </label>
                    <div class="submit">
                        <input type="submit" value="登录"/>
                    </div>
                    <div class="forget link">
                        <abbr title="那就试试密码为学号">忘记密码？无法验证？</abbr>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>
</body>

</html>