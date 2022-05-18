<?php
include("database.php");
$sql = new SQL('localhost', 'root', 'fish', 'fishwork');
queryJson();

function queryJson(): void
{
    $json = json_decode(file_get_contents("stu.json"), true);
    $str1 = "select  `stuId`, `stuName`,`major` from `stuinfo`;";
    $str2 = "select `courseId`, `courseName` from `course`;";
    $ans = [];
    global $sql;

    $sql->Run($str1); //学生数组
    foreach ($sql->head as $key) {
        foreach ($sql->arr as $item)
            $ans[$key][] = $item[$key];
    }
    $ans["major"] = array_values(array_unique($ans["major"]));//去重
    $ans["stuId"][] = "fishroot";

    $sql->Run($str2); //课程数组
    foreach ($sql->head as $key) {
        foreach ($sql->arr as $item)
            $ans[$key][] = $item[$key];
    }

    $json["totalData"] = $ans;
    $str = json_encode($json, JSON_UNESCAPED_UNICODE);
    file_put_contents("stu.json", $str);
}
