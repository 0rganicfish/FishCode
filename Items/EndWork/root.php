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

    if (!$_SESSION["power"]) {
        header("location:../EndWork/");
    }

?>


<?php
} else {
    header("location:login.php");
}
?>

</html>