<html lang="zh-cn">
<head>
    <meta charset='UTF-8'>
    <script src=''></script>
    <link rel='stylesheet' href='../sample.css'>
    <link rel='icon' href='../img/bili.ico'>
    <title> 咩！</title>
</head>
<body>

<?php
session_start();
if (isset($_COOKIE['name'])) {
    $_SESSION['name'] = $_COOKIE['name'];
    $_SESSION['is_login'] = 1;
}
if (isset($_SESSION['is_login'])) {
    echo '<p>', "你好! ", $_SESSION['name'], '</p>';
    ?>

    <div>
        <div id="">
            <button id="play">点击</button>
            <button id="none">关闭</button>
            <a href='logout.php'> 注销 </a><br>
        </div>

        <div id="table" style="">
            <?php
            include 'database.php';
            $mysql = new sql_query('localhost', 'root', 'fish', 'fish');
            $mysql->Import('fish.sql');
            $mysql->Run();
            ?>
            <table>
                <caption>学生信息表</caption>
                <?php
                echo '<tr>';
                foreach ($mysql->head as $item)
                    echo '<th>', $item, '</th>';
                echo '</tr>';

                foreach ($mysql->arr as $row) {
                    echo '<tr>';
                    foreach ($mysql->head as $col)
                        echo '<th>', $row[$col], '</th>';
                    echo '</tr>';
                }
                ?>
            </table>
        </div>

        <script>
            let table = document.getElementById('table'),
                play = document.getElementById('play'),
                none = document.getElementById('none')
            play.addEventListener('click', () => {
                table.style.display = 'flex';
            });
            none.addEventListener('click', () => {
                table.style.display = 'none';
            });
        </script>
    </div>

    <?php
} else {
    ?>
    <div>
        <p>您还没有登录,请<a href='login.php'><b> 登录</b></a>。</p>
    </div>
    <?php
}
?>
</body>
</html>