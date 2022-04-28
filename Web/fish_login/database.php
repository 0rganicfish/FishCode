<?php

class fish_sql
{
    protected PDO $db;
    protected array $sqlarr;

    public function __construct($host, $user, $pw, $dbname)
    {
        try {
            $dns = "mysql:host=" . $host . ";dbname=" . $dbname;
            $this->db = new PDO($dns, $user, $pw);
        } catch (PDOException $err) {
            die('链接失败! ' . $err->getMessage());
        }
    }

    public function Import($url)
    {
        if (!file_exists($url))
            exit('文件不存在');
        $sqlfile = file_get_contents($url);
        if (!$sqlfile)
            exit('文件打开错误');
        // 将表导到数组
        $str = $sqlfile;
        $str = preg_replace('/--.*/i', '', $str);
        $str = preg_replace('/\/\*.*\*\/(;)?/i', '', $str);
        $str = explode(";\n", $str);

        foreach ($str as $v) {
            $v = trim($v);
            if (empty($v))
                continue;
            else
                $this->sqlarr[] = $v;
        }
    }
}

class sql_query extends fish_sql
{
    public array $head, $arr;

    public function Run()
    {
        foreach ($this->sqlarr as $item)
            $this->arr = $this->db->query($item)->fetchAll(PDO::FETCH_ASSOC);

        $this->head = array_keys($this->arr[0]);
    }
}