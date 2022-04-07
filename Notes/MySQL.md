# SQL

- [README](../README.md)

[TOC]

## 基础语句

### SELECT

- **语法：**

  ```sql {.line-numbers}
  SELECT column_name| *
  FROM table_name;
  ```

- **结果：** 列出 `table` 中列名为 `column_name`的数据，`*` 则为表中所有数据

### DISTINCT

- **语法：**

  ```sql {.line-numbers}
  SELECT DISTINCT column_name
  FROM table_name;
  ```

- **结果：** 列出 **去重** 后的列数据

### WHERE

- **语法：**

  ```sql {.line-numbers}
  SELECT column_name, column_name
  FROM table_name
  WHERE column_name operator value;
  ```

- **结果：** 用于 **过滤** 列数据

- **`operator` 运算符：**

    <table class="reference"><tbody><tr><th width="20%">运算符</th><th width="80%">描述</th></tr><tr><td>=</td><td>等于</td></tr><tr><td>&lt;&gt;</td><td>不等于</td></tr><tr><td>&gt;</td><td>大于</td></tr><tr><td>&lt;</td><td>小于</td></tr><tr><td>&gt;=</td><td>大于等于</td></tr><tr><td>&lt;=</td><td>小于等于</td></tr><tr><td>BETWEEN</td><td>在某个范围内</td></tr><tr><td>LIKE</td><td>搜索某种模式 | 模糊判断</td></tr><tr><td>IN</td><td>指定针对某个列的多个可能值</td></tr></tbody></table></br>

- **逻辑运算符：** `()` 、`and` 、`not` 、`or`

- **特殊：**
  - 空值判断： `is null`
  - 范围判断（闭区间）：`between a and b`
  - 模糊判断： `LIKE`
    - `%a` ：以 a 结尾的数据
    - `a%` ：以 a 开头的数据
    - `%a%` ：含有 a 的数据
    - `_a_` ：三位且中间字母是 a 的
    - `_a` ：两位且结尾字母是 a 的
    - `a_` ：两位且开头字母是 a 的

### ORDER BY

- **语法：**

  ```sql {.line-numbers}
  SELECT column_name
  FROM table_name
  ORDER BY column_name ASC | DESC;
  ```

- **结果：** 用于排序，默认 `ASC` 升序
- 多列排序：先按第一个 `column_name` 来排，然后类推
- 顺序：`desc` 或者 `asc` 只对它紧跟着的第一个列名有效，其他不受影响，仍然是默认的升序。

### INSERT INTO

- **语法：**

  - 第一种形式无需指定要插入数据的列名，只需提供被插入的值即可：

    ```sql {.line-numbers}
    INSERT INTO table_name
    VALUES (value1, value2, value3,...);
    ```

  - 第二种形式需要指定列名及被插入的值：

    ```sql {.line-numbers}
    INSERT INTO table_name (column1, column2, column3,...)
    VALUES (value1, value2, value3,...);
    ```

- **结果：** 向表中插入新纪录

### UPDATE

- **语法：**

  ```sql {.line-numbers}
  UPDATE table_name
  SET column1 = value1, column2 = value2,...
  WHERE some_column = some_value;
  ```

- **结果：** 更新表中已有的数据，且一定要指定 `WHERE`

### DELETE

- **语法：**

  ```sql {.line-numbers}
  DELETE FROM table_name
  WHERE some_column = some_value;
  ```

- **结果：** 删除行。不带 `WHERE` 时则将整个表删除，但表的结构还在
- 令：别的删除
  - `DROP table_name`：将表完全删除
  - `TRUNCATE table_name`：仅删除内容并释放空间，表的结构还在

## 高级语句

### JOIN

- **结果：** 基于多个表之间 相同的内容 相联动

#### INNER JOIN

- **语法：**

  ```sql {.line-numbers}
  SELECT column_name(s)
  FROM table1
  INNER JOIN table2
  ON table1.column_name = table2.column_name;
  ```

- **结果：** 内连接，只连接匹配的行

## SQL 函数

## 自救

1.  删除原有的数据库（注：执行该命令需要管理员权限，所以你在打开 cmd 时需要以管理员的身份运行）。
    1. 查询 SQL 服务是否存在：
       > sc query mysql （对应的 SQL 服务名称）如果存在则会弹出一些信息，不存在则提示未找到服务。
    2. 删除服务：
       > sc delete mysql（对应的 SQL 服务名称）执行该命令即可删除服务
2.  初始化数据（注：root@localhost:后面的是你的登录密码）
    > mysqld --initialize --user=mysql --console
3.  安装服务（提示：Service successfully installed.就证明你安装成功了）
    > mysqld --install

> REF: [Access denied for user 'root'@'localhost' (using password: YES)](https://blog.csdn.net/huang6ing/article/details/103821495)
