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
?>

<!DOCTYPE html>
<html lang="zh">

<head>
    <meta charset="UTF-8"/>
    <meta name="viewport"
          content="width=device-width, initial-scale=1.0, minimum-scale=0.5, maximum-scale=2.0, user-scalable=yes"/>
    <script async src="styles/Template.js"></script>
    <?php
    if ($_SESSION["power"]) {
        echo "<script async src='styles/teacher.js'></script>";
    } else {
        echo "<script async src='styles/student.js'></script>";
    }
    ?>
    <link rel="stylesheet" href="styles/index.css">
    <link rel="stylesheet" href="styles/Template.css"/>
    <link rel="icon" href="img/shark_50.png"/>
    <title>学生成绩管理系统</title>
</head>

<body>
<div class="app">
    <a href="?logout">注销</a>

</div>


</body>
<?php
} else {
    header("location:login.php");
}
?>
</html>