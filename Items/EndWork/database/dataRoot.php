<?php
include("database.php");
$sql = new SQL('localhost', 'root', 'fish', 'fishwork');

if (isset($_GET["type"]))
    if ($_GET["type"] === "students") {
        stuTable();
    }
//

if (isset($_POST["data"]))
    if ($_POST["type"] === "update") {
        edit(json_decode($_POST["data"], true));
    }


function queryJson(): void
{
    $json = json_decode(file_get_contents("stu.json"), true);
//    $str1 = "select  `stuId`, `stuName`,`major` from `stuinfo`;";
//    $str2 = "select `courseId`, `courseName` from `course`;";
//    $ans = [];
//    global $sql;
//
//    $sql->Run($str1); //学生数组
//    foreach ($sql->head as $key) {
//        foreach ($sql->arr as $item)
//            $ans[$key][] = $item[$key];
//    }
//    $ans["major"] = array_values(array_unique($ans["major"]));//去重
//    $ans["stuId"][] = "fishroot";
//
//    $sql->Run($str2); //课程数组
//    foreach ($sql->head as $key) {
//        foreach ($sql->arr as $item)
//            $ans[$key][] = $item[$key];
//    }
//
//    $json["totalData"] = $ans;
    $str = json_encode($json, JSON_UNESCAPED_UNICODE);
    file_put_contents("stu.json", $str);
}

function printTbody($head, $arr): void
{
    $i = 1;
    foreach ($arr as $row) {
        echo '<tr>';
        echo '<td>', $i++, '</td>';
        foreach ($head as $col)
            echo '<td>', $row[$col], '</td>';
        echo '</tr>';
    }
    echo '</tbody></table>';
}

function stuTable(): void
{
    global $sql;
    $str = "select `stuName`, `stuId`, `major`, format(avg(`gradePoint`), 1) GPA, `stuinfo`.`comments`
            from `stuinfo` join `score` using (`stuId`) group by `stuId`;";
    $sql->Run($str);
    $ans = $sql->arr;

    $i = 0;
    foreach ($ans as $item) {
        $class = substr($item["stuId"], 0, 2) .
            $item["major"] .
            substr($item["stuId"], 7, 1) . "班";
        $ans[$i++]["major"] = $class;
    }

    echo '<table><thead><tr><th><span class="sort_ico"></span><span class="checkbox"><input type="checkbox" name="check"></span></th><th>序号<span class="sort_ico"></span></th><th>姓名<span class="sort_ico"></span></th><th>学号<span class="sort_ico"></span></th><th>班级<span class="sort_ico"></span></th><th>GPA<span class="sort_ico"></span></th><th>备注<span class="sort_ico"></span></th><th>操作<span class="sort_ico"></span></th></tr></thead><tbody>';

    $i = 1;
    foreach ($ans as $row) {
        echo '<tr><td><span class="checkbox"><input type="checkbox" name="check"></span></td>';
        echo '<td>', $i++, '</td>';
        foreach ($sql->head as $col)
            echo '<td>', $row[$col], '</td>';
        echo '<td><input type="button" name="info" value="详情"><input type="button" name="edit" value="修改"><input type="button" name="delete" value="删除"></td></tr>';
    }
    echo '</tbody></table>';
}

function edit($data): void
{
    $uid = $data['stuId'];
    $info = $data['info'];
    $scoreInfo = $data['table'];
    global $sql;
    $str = '';

    foreach ($scoreInfo as $item) {
        if ($item["key"] === "scoreGot") {
            $str = "call GPACalc({$item['value']}, {$uid}, {$item['course']})";
            $sql->Run($str);
        }

    }


    echo '<br>', $uid, '<br>';
    print_r($info);
    print_r($scoreInfo);
}

//function editScore