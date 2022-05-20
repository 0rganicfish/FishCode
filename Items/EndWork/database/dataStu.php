<?php
session_start();
include("database.php");

$uid = "";
$uid = $_GET["uid"] ?? $_SESSION["uid"];

$sql = new SQL('localhost', 'root', 'fish', 'fishwork');

getInfo($uid);
if ($_GET["type"] === "score")
    printScore();
else
    printCourse();

function printTbody($head, $arr): void
{
    $i = 1;
    foreach ($arr as $row) {
        echo '<tr>';
        echo '<td>', $i++, '</td>';
        foreach ($head as $col)
            echo '<td id="', $col, '">', $row[$col], '</td>';
        echo '</tr>';
    }
    echo '</tbody></table>';
}

function printScore(): void
{
    global $uid;
    global $sql;
    $str = "select `courseName`, `credit`, `type`, `scoreGot`,  `creditGot`, `gradePoint` , `score`.`comments`
            from `score` join `stuinfo` using (`stuId`) join `course` using (`courseId`)
            where `stuid` = $uid;";
    $sql->Run($str);

    echo '<table><thead><tr><th>序号<span class="sort_ico"></span></th><th>课程<span class="sort_ico"></span></th><th>学分<span class="sort_ico"></span></th><th>类别<span class="sort_ico"></span></th><th>成绩<span class="sort_ico"></span></th><th>取得学分<span class="sort_ico"></span></th><th>绩点<span class="sort_ico"></span></th><th>备注<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($sql->head, $sql->arr);
}

function printCourse(): void
{
    global $sql;
    global $uid;
    $str = "select `courseID`, `courseName`, `learnTime`, `credit`, `type`
            from `course` join `score` using (`courseId`)
            where `stuId` = $uid;";
    $sql->Run($str);

    echo '<table><thead><tr><th>序号<span class="sort_ico"></span></th><th>课程号<span class="sort_ico"></span></th><th>课程名<span class="sort_ico"></span></th><th>学时<span class="sort_ico"></span></th><th>学分<span class="sort_ico"></span></th><th>课程类别<span class="sort_ico"></span></th></tr></thead><tbody>';

    printTbody($sql->head, $sql->arr);
}

function getInfo($uid): void
{
    global $sql;
    $str = "select `major`, `stuId`, `stuName`, format(avg(`gradePoint`), 1) gpa
            from `stuinfo` join `score` using (`stuId`)
            where `stuId` = $uid;";
    $sql->Run($str);
    $ans = $sql->arr[0];
    $class = substr($ans["stuId"], 0, 2) .
        $ans["major"] .
        substr($ans["stuId"], 7, 1) . "班";

    $json = json_decode(file_get_contents("stu.json"), true);
    $ansData = [
        "class" => $class,
        "gpa" => $ans["gpa"],
        "id" => $ans["stuId"],
        "name" => $ans["stuName"]
    ];
    $json["data"]["stuInfo"] = $ansData;
    $str = json_encode($json, JSON_UNESCAPED_UNICODE);
    file_put_contents("stu.json", $str);
}