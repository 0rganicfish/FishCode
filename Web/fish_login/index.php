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

        <div id="mysql" style="display: none;">
            <?php
            try {
                $db = new PDO('mysql:host=localhost;dbname=fish', 'root', 'fish');
                $sql = 'select stu_id, stu_name, sex from stuinfo;';

                $row = $db->query($sql)->fetchAll(PDO::FETCH_ASSOC);
                $col = ['stu_id', 'stu_name', 'sex'];

                $db = null;
            } catch (PDOException $err) {
                echo '连接失败！ ', $err->getMessage(), ' <br>';
                die();
            }
            ?>
            <table>
                <tr>
                    <th>学号</th>
                    <th>姓名</th>
                    <th>性别</th>
                </tr>
                <?php
                foreach ($row as $rows) {
                    echo '<tr>';
                    foreach ($col as $cols) {
                        echo '<th>', $rows[$cols], '</th>';
                    }
                    echo '</tr>';
                }
                ?>
            </table>
        </div>

        <script>
            let table = document.getElementById('mysql'),
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
        <p>您还没有登录,请<a href='login.php'><b> 登录。</b></a></p>
    </div>
    <?php
}
?>
</body>
</html>