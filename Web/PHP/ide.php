<?php

$db = new PDO('mysql:host=localhost;dbname=fish', 'root', 'fish');
$sql = 'select stu_id, stu_name from stuinfo limit 5;';

$arr1 = $db->query($sql)->fetch(PDO::FETCH_ASSOC);
$arr2 = $db->query($sql)->fetchall(PDO::FETCH_ASSOC);

print_r($arr1);
echo '<br><br>';
print_r($arr2);


$username = $_POST['username'];
$oldpwd = $_POST['oldpwd'];
$newpwd = $_POST['newpwd'];

$s_sql = "select * from userinfo where username='$username'";
$s_result = $db->query($s_sql);
list($username, $password) = $s_result->fetch(PDO::FETCH_NUM);

if ($password != $oldpwd)
    echo "原密码错误!";
else {
    if (!preg_match('/^\w{6,20}$/', $newpwd))
        echo "新密码格式不满足要求!";
    else {
        $update_sql = "update userinfo set password='$newpwd' where username='$username'";
        if ($db->exec($update_sql))
            echo "密码修改成功!";
        else
            echo "密码修改失败!";
    }
}
