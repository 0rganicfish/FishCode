<?php

class SQL
{
    public PDO $db;
    public array $head, $arr;
    protected array $sqlarr;
    private string $sql = "";

    public function __construct($host, $user, $pw, $dbname)
    {
        try {
            $dns = "mysql:host=" . $host . ";dbname=" . $dbname;
            $this->db = new PDO($dns, $user, $pw);
        } catch (PDOException $err) {
            die('链接失败! ' . $err->getMessage());
        }
    }

    public function Run($str): void
    {
        $run = $this->db->prepare($str);
        $run->execute();
        $this->arr = $run->fetchAll(PDO::FETCH_ASSOC);
        if (!empty($this->arr))
            $this->head = array_keys($this->arr[0]);
    }
}
