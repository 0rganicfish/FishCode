<?php
include("database.php");
$sql = new SQL('localhost', 'root', 'fish', 'fishwork');

//表格切换
if (isset($_GET["type"]))
    if ($_GET["type"] === "students") {
        stuTable();
    } elseif ($_GET["type"] === "course") {
        courseTable();
    } elseif ($_GET["type"] === "score") {
        scoreAll($_GET["courseId"]);
    }


// 学生编辑
if (isset($_POST["data"]))
    if ($_POST["type"] === "update") {
        editStu(json_decode($_POST["data"], true));
    }

// 打印模板
function printTbody($arr, $head): void
{
    $i = 1;
    foreach ($arr as $row) {
        echo '<tr><td><span class="checkbox"><input type="checkbox" name="check"></span></td>';
        echo '<td>', $i++, '</td>';
        foreach ($head as $col)
            echo '<td>', $row[$col], '</td>';
        echo '<td><input type="button" name="info" value="详情"><input type="button" name="edit" value="修改"><input type="button" name="delete" value="删除"></td></tr>';
    }
    echo '</tbody></table>';
}


function stuTable(): void
{
    global $sql;
    $str = "select `stuName`, `stuId`, `major`, `GPA`, `stuinfo`.`comments`
            from `stuinfo` join `score` using (`stuId`) group by `stuId`;";
    $sql->Run($str);
    $ans = $sql->arr;

    $i = 0;
    foreach ($ans as $item) {
        $ans[$i++]["major"] =
            substr($item["stuId"], 0, 2) .
            $item["major"] .
            substr($item["stuId"], 7, 1) . "班";
    }

    echo '<table><thead><tr><th><span class="sort_ico"></span><span class="checkbox"><input type="checkbox" name="check"></span></th><th>序号<span class="sort_ico"></span></th><th>姓名<span class="sort_ico"></span></th><th>学号<span class="sort_ico"></span></th><th>班级<span class="sort_ico"></span></th><th>GPA<span class="sort_ico"></span></th><th>备注<span class="sort_ico"></span></th><th>操作<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($ans, $sql->head);
}

function editStu($data): void
{
    $uid = $data['stuId'];
    $info = $data['info'];
    $scoreInfo = $data['table'];
    global $sql;

    foreach ($scoreInfo as $item) {
        if ($item["key"] === "scoreGot") {
            $str = "call GPACalc('$uid', '{$item['course']}', '{$item['value']}');";
            $sql->Run($str);
        }
    }
    foreach ($info as $item) {
        $str = "call updateStuinfo('$uid', '{$item['key']}', '{$item['value']}');";
        $sql->Run($str);
    }
//    echo $uid; print_r($info); print_r($scoreInfo);
}


// 课程
function courseTable(): void
{
    global $sql;
    $str = "select `courseId`, `courseName`, `learnTime`, `credit`, `type`
            from `course`;";
    $sql->Run($str);

    echo '<table><thead><tr><th><span class="sort_ico"></span><span class="checkbox"><input type="checkbox" name="check"></span></th><th>序号<span class="sort_ico"></span></th><th>课程号<span class="sort_ico"></span></th><th>课程名<span class="sort_ico"></span></th><th>学时<span class="sort_ico"></span></th><th>学分<span class="sort_ico"></span></th><th>课程类别<span class="sort_ico"></span></th><th>操作<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($sql->arr, $sql->head);
}


//各科成绩
function scoreAll($id): void
{
    global $sql;
    $str = "select stuId, stuName, courseId, courseName, scoreGot, gradePoint, creditGot
            from score join stuinfo using (stuId) join course using (courseId)
            where courseId = '$id';";
    $sql->Run($str);

    echo '<table><thead><tr><th><span class="sort_ico"></span><span class="checkbox"><input type="checkbox" name="check"></span></th><th>学号<span class="sort_ico"></span></th><th>姓名<span class="sort_ico"></span></th><th>课程号<span class="sort_ico"></span></th><th>课程名<span class="sort_ico"></span></th><th>成绩<span class="sort_ico"></span></th><th>绩点<span class="sort_ico"></span></th><th>学分<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($sql->arr, $sql->head);
}