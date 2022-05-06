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

    echo "<table style=\"text-align: center;\" id=\"table\"><caption>学生信息表</caption><thead id=\"thead\"><tr>";
    foreach ($mysql->head as $item) {
        if ($item === "学分")
            echo "<th data-type=\"number\">";
        else
            echo "<th data-type=\"string\">";
        echo $item, '</th>';
    }
    echo "</tr></thead><tbody id=\"tbody\">";

    foreach ($mysql->arr as $row) {
        echo '<tr>';
        foreach ($mysql->head as $col)
            echo '<td>', $row[$col], '</td>';
        echo '</tr>';
    }
    echo "</tbody></table>";
    echo "<script src='styles/fish.js'>sort_table()</script>";
}

//var_dump($_GET);
if (@$_GET['sel'] == 'close')
    echo "";
else
    print_ans($_GET);
