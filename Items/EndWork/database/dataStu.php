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


function printScore(): void
{
    global $uid;
    global $sql;
    $str = "select `courseId`, `courseName`, `credit`, `type`, `scoreGot`,  `creditGot`, `gradePoint` , `score`.`comments`
            from `score` join `stuinfo` using (`stuId`) join `course` using (`courseId`)
            where `stuid` = $uid;";
    $sql->Run($str);

    echo '<table><thead><tr><th>序号<span class="sort_ico"></span></th><th>课程<span class="sort_ico"></span></th><th>学分<span class="sort_ico"></span></th><th>类别<span class="sort_ico"></span></th><th>成绩<span class="sort_ico"></span></th><th>取得学分<span class="sort_ico"></span></th><th>绩点<span class="sort_ico"></span></th><th>备注<span class="sort_ico"></span></th></tr></thead><tbody>';


    for ($i = 1; $i < count($sql->arr); ++$i) {
        echo '<tr id="' . $sql->arr[$i-1]["courseId"] . '">' . '<td>', $i, '</td>';
        for ($j = 1; $j < count($sql->head); ++$j)
            echo '<td id="', $sql->head[$j], '">', $sql->arr[$i][$sql->head[$j]], '</td>';
        echo '</tr>';
    }
    echo '</tbody></table>';
}

function printCourse(): void
{
    global $sql;
    global $uid;
    $str = "select `courseId`, `courseName`, `learnTime`, `credit`, `type`
            from `course` join `score` using (`courseId`)
            where `stuId` = $uid;";
    $sql->Run($str);

    echo '<table><thead><tr><th>序号<span class="sort_ico"></span></th><th>课程号<span class="sort_ico"></span></th><th>课程名<span class="sort_ico"></span></th><th>学时<span class="sort_ico"></span></th><th>学分<span class="sort_ico"></span></th><th>课程类别<span class="sort_ico"></span></th></tr></thead><tbody>';

    $i = 1;
    foreach ($sql->arr as $row) {
        echo '<tr><td>', $i++, '</td>';
        foreach ($sql->head as $col)
            echo '<td id="', $col, '">', $row[$col], '</td>';
        echo '</tr>';
    }
    echo '</tbody></table>';

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