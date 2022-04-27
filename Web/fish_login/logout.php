<html lang="zh-cn">
<head>
    <meta charset='UTF-8'>
    <script src=''></script>
    <link rel='stylesheet' href='../sample.css'>
    <link rel='icon' href='../img/bili.ico'>
    <title> 注销了</title>
</head>
<body>

<?php
header('Content-type:text/html; charset=utf-8');
session_start();

@$username = $_SESSION['name'];
$_SESSION = array();
session_destroy();

setcookie('name', '', time() - 99);
setcookie('code', '', time() - 99);

?>

<div>
    <p>欢迎下次光临。 <a href='login.php'> 重新登录</a></p>
</div>

</body>
</html>