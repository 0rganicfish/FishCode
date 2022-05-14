<?php
session_start();
if (isset($_COOKIE["uid"])) {
    $_SESSION["uid"] = $_COOKIE["uid"];
    $_SESSION["logged"] = true;
}
if ($_SESSION["logged"]) {

    if (isset($_GET["logout"])) {
        setcookie("uid", "", time() - 1);
        $_SESSION["logged"] = false;
        header("location:login.php");
    }

    if ($_SESSION["power"]) {
        header("location:root.php");
    }

?>

    <!DOCTYPE html>
    <html lang="zh">

    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=0.5, maximum-scale=2.0, user-scalable=yes" />
        <script async src="styles/Template.js"></script>
        <script async src='styles/index.js'></script>
        <link rel="stylesheet" href="styles/index.css">
        <link rel="stylesheet" href="styles/Template.css" />
        <link rel="icon" href="img/shark_50.png" />
        <title>我的成绩</title>
    </head>

    <body>
        <div class="app">
            <div class="back"></div>
            <div class="main">
                <div class="left">
                    <div class="head">
                        <img src="img/shark_100.png" alt="" class="logo" />
                        <div class="title">学生成绩管理系统</div>
                    </div>

                    <div class="buttons">
                        <label class="button active">
                            <input type="radio" name="options" checked="" />
                            <span>我的成绩</span>
                        </label>
                        <label class="button">
                            <input type="radio" name="options" />
                            <span>课程信息</span>
                        </label>
                    </div>

                    <div class="footer">
                        <div class="introduce">
                            By：
                            <span class="link">有机鱼</span>
                        </div>
                        <div class="contact">
                            <span>联系方式：</span>
                            <span class="qqmail link">QQ邮箱</span>
                            <span> | </span>
                            <span class="weChat link">微信</span>
                        </div>

                        <div class="logout">
                            <a class="link" href="?logout">退出登录</a>
                        </div>
                    </div>
                </div>

                <div class="mid"></div>

                <div class="right"></div>
            </div>
        </div>
    </body>
<?php
} else {
    header("location:login.php");
}
?>

    </html>