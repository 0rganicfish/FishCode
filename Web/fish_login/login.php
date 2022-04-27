<!DOCTYPE html>
<html lang="zh-cn">

<head>
    <meta charset='UTF-8'>
    <link rel='stylesheet' href='../sample.css'>
    <link rel='icon' href=''>
    <title>fish</title>
</head>

<body>

<div>
    <form id="fish">
        <label>
            账号：<input type="text" name="name"><span id="err"></span><br>
            密码：<input type="password" name="password"><span id="err"></span><br>
        </label>
        <input type="submit" value="提交" name="login"><br>
    </form>

    <script>
        // 不显示action的话要Ajax啦
        (() => {
            let form = document.getElementById('fish');
            form.action = 'login.php'
            form.method = 'post';
        })();
    </script>

    <?php
    header('Content-type:text/html; charset=utf-8');
    session_start();
    if (isset($_POST['login'])) {
        $name = trim($_POST['name']);
        $password = trim($_POST['password']);
        if ($name == '' || $password == '') {
            echo "不准空";
            exit;
        } elseif ($name != 'fish' || $password != 'fish') {
            echo "不准错";
            exit;
        } else {
            $_SESSION['name'] = $name;
            $_SESSION['is_login'] = 1;
            setcookie('name', '', time() - 999);
            setcookie('code', '', time() - 999);

            header('location:index.php');
        }
    }
    ?>

</div>

<!--<div>-->
<!--    <button id="ajaxButton" type="button">Make a request</button>-->
<!--    <script src="fish.js"></script>-->
<!--</div>-->
</body>

</html>