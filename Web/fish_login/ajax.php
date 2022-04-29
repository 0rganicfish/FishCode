<?php
include 'database.php';
$mysql = new fish_sql('localhost', 'root', 'fish', 'fish');
$mysql->Import('fish.sql');

function print_ans($q)
{
    global $mysql;
    $key = array_keys($q)[0];
    if ($key == "sort")
        $mysql->Sort($q["sort"]);
    else
        $mysql->Query($q);

    echo '<table><caption>学生信息表</caption><tr>';
    foreach ($mysql->head as $item)
        echo '<th>', $item, '</th>';
    echo '</tr>';

    foreach ($mysql->arr as $row) {
        echo '<tr>';
        foreach ($mysql->head as $col)
            echo '<th>', $row[$col], '</th>';
        echo '</tr>';
    }
    echo '</table>';
}

//var_dump($_GET);
if (@$_GET['sel'] == 'close')
    echo "";
else
    print_ans($_GET);
