<?php
include("database.php");
$sql = new SQL();

//表格切换
if (isset($_GET["type"]))
    if ($_GET["type"] === "students") {
        stuTable();
    } elseif ($_GET["type"] === "course") {
        courseTable();
    } elseif ($_GET["type"] === "score")
        scoreAll();

if (isset($_POST["data"]))
    if ($_POST["type"] === "update") {
        editStu(json_decode($_POST["data"], true));
    } elseif ($_POST["type"] === "course") {
        editCourse(json_decode($_POST["data"], true));
    } elseif ($_POST["type"] === "delete") {
        deleteInfo(json_decode($_POST["data"], true));
    }


// 打印模板
function printTbody($arr, $head, $edit): void
{
    $i = 1;
    foreach ($arr as $row) {
        echo '<tr><td><input type="checkbox" name="check"></td>';
        echo '<td>', $i++, '</td>';
        foreach ($head as $col)
            echo '<td id="', $col, '">', $row[$col], '</td>';
        if ($edit)
            echo '<td><input type="button" name="info" value="详情"><input type="button" name="edit" value="修改"><input type="button" name="delete" value="删除"></td></tr>';
    }
    echo '</tbody></table>';
}


function stuTable(): void
{
    global $sql;
    $str = "select `stuId`, `stuName`, `major`, `GPA`, `stuinfo`.`comments`
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

    echo '<table><thead><tr><th class="dig"><span class="sort_ico"></span><input type="checkbox" name="check"></th><th class="dig">序号<span class="sort_ico"></span></th><th>学号<span class="sort_ico"></span></th><th>姓名<span class="sort_ico"></span></th><th>班级<span class="sort_ico"></span></th><th class="dig">GPA<span class="sort_ico"></span></th><th>备注<span class="sort_ico"></span></th><th>操作<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($ans, $sql->head, true);
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

    echo '<table><thead><tr><th class="dig"><span class="sort_ico"></span><input type="checkbox" name="check"></th><th class="dig">序号<span class="sort_ico"></span></th><th class="dig">课程号<span class="sort_ico"></span></th><th>课程名<span class="sort_ico"></span></th><th class="dig">学时<span class="sort_ico"></span></th><th class="dig">学分<span class="sort_ico"></span></th><th>课程类别<span class="sort_ico"></span></th><th>操作<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($sql->arr, $sql->head, true);
}

function editCourse($data): void
{
//    print_r($data);
    $id = $data["courseId"];
    global $sql;
    foreach ($data["data"] as $item) {
        $str = "call updateCourse('$id',' {$item['key']}', '{$item['value']}')";
        $sql->Run($str);
    }

}

//各科成绩
//下拉选课程......就懒了
function scoreAll(): void
{
    global $sql;
    $str = "select stuId, stuName, courseId, courseName, scoreGot, gradePoint, creditGot
            from score join stuinfo using (stuId) join course using (courseId)";
    $sql->Run($str);

    echo '<table><thead><tr><th class="dig"><span class="sort_ico"></span><input type="checkbox" name="check"></th><th class="dig">序号<span class="sort_ico"></span></th><th>学号<span class="sort_ico"></span></th><th>姓名<span class="sort_ico"></span></th><th class="dig">课程号<span class="sort_ico"></span></th><th>课程名<span class="sort_ico"></span></th><th class="dig">成绩<span class="sort_ico"></span></th><th class="dig">绩点<span class="sort_ico"></span></th><th class="dig">学分<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($sql->arr, $sql->head, false);
}

//删除信息
function deleteInfo($data): void
{
    global $sql;
    foreach ($data['data'] as $item) {
        if ($data['type'] === "score") //飞线
            $str = "delete from score where stuId = '{$item['stuId']}' and courseId = '{$item['courseId']}';";
        else
            $str = "call deleteInfo('{$data['type']}', '{$item}')";
        $sql->Run($str);
    }
}

