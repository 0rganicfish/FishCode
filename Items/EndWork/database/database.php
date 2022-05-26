<?php

if ((empty($_POST) && empty($_GET) )|| empty($_COOKIE))
    header('HTTP/1.1 404 Not Found');

class SQL
{
    private PDO $db;
    public array $head = [], $arr = []; //表头及表内容

    public function __construct()
    {
        $host = "localhost";
        $user = "root";
        $pw = "fish"; //只需要修改为自己的密码即可
        $dbname = "fishwork";

        try {
            $dns = "mysql:host=$host;dbname=$dbname";
            $this->db = new PDO($dns, $user, $pw);
        } catch (PDOException $err) {
            die('链接失败! ' . $err->getMessage());
        }
    }

    public function Run($str): void
    {
        try {
            $this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
//            $this->db->beginTransaction();
            $run = $this->db->query($str);
//            $run = $this->db->prepare($str);
//            $run->execute();
//            $this->db->commit();
            $this->arr = $run->fetchAll(PDO::FETCH_ASSOC);
            if (!empty($this->arr))
                $this->head = array_keys($this->arr[0]);
        } catch (PDOException $e) {
            $this->db->rollback();
            echo $str, "   ", $e->getMessage(), '<br>';
        }
    }
}
