<?php
const EOL = "<br>";

//$dd = 23.3424;
////printf("\$dd is %.1f ", $dd);
//echo '$dd is ', $dd, EOL, EOL;
//
//$a = [1, 23, "55"];
//$a[] = 4;
////var_dump($a);
//print_r($a);
//echo EOL;
////unset($a[2]);
//for ($i = 0; $i < count($a); ++$i)
//    echo $i, ": ", $a[$i], EOL;
//
//$map = [
//    'x' => 12,
//    'y' => 13,
//    'r' => 2
//];
////$map['x'] = 3;
//unset($map['r']);
//echo EOL, $map['x'], EOL;
//
//$add = function ($a, $b) {
//    return $a + $b;
//}; //匿名函数
//echo $add(1, 2), EOL;
//
//function multi($a, $b): int //非匿名函数必须声明函数的返回类型
//{
//    return $a * $b;
//}
//
//echo multi(3, 4), EOL;


$q = isset($_GET['q']) ? htmlspecialchars($_GET['q']) : '';
if ($q) {
    if ($q == 'RUNOOB') {
        echo '菜鸟教程<br>http://www.runoob.com';
    } else if ($q == 'GOOGLE') {
        echo 'Google 搜索<br>http://www.google.com';
    } else if ($q == 'TAOBAO') {
        echo '淘宝<br>http://www.taobao.com';
    }
} else {
    ?>
    <form action="" method="get">
        <label>
            <select name="q">
                <option value="">选择一个站点:</option>
                <option value="RUNOOB">Runoob</option>
                <option value="GOOGLE">Google</option>
                <option value="TAOBAO">Taobao</option>
            </select>
        </label>
        <label>
            <div>性别:</div>
            <input type="radio" name="gender" value="female">男
            <input type="radio" name="gender" value="male">女
        </label><br>
        <label>
            <input type="checkbox" name="funs" id="" value="football">足球<br>
            <input type="checkbox" name="funs" id="" value="basketball">篮球<br>
            <input type="checkbox" name="funs" id="" value="world peace">世界和平<br>
        </label>
        <input type="submit" value="提交">
    </form>
    <?php
    if ($_FILES['file']['error'] === 0) {
        // PHP 在会自动接收客户端上传的文件到一个临时的目录
        $temp_file = $_FILES['file']['tmp_name'];
        // 我们只需要把文件保存到我们指定上传目录
        $target_file = '../static/uploads/' . $_FILES['file']['name'];
        if (move_uploaded_file($temp_file, $target_file)) {
            $image_file = '/static/uploads/' . $_FILES['file']['name'];
        }
    }
}
?>
