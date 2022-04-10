# SQL

- [README](../README.md)

[TOC]

## 基础语句

### SELECT

- **语法：**
  ```sql {.line-numbers}
  SELECT column1
  FROM table1;
  ```
- **结果：** 列出 `table` 中列名为 `column1`的数据，`*` 则为表中所有数据

### DISTINCT

- **语法：**
  ```sql {.line-numbers}
  SELECT DISTINCT column1
  FROM table1;
  ```
- **结果：** 列出 **去重** 后的列数据

### WHERE

- **语法：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  WHERE column1 operator value;
  ```
- **结果：** 用于 **过滤** 列数据

- **`operator` 运算符：**

    <table class="reference"><tbody><tr><th width="20%">运算符</th><th width="80%">描述</th></tr><tr><td>=</td><td>等于</td></tr><tr><td>&lt;&gt;</td><td>不等于</td></tr><tr><td>&gt;</td><td>大于</td></tr><tr><td>&lt;</td><td>小于</td></tr><tr><td>&gt;=</td><td>大于等于</td></tr><tr><td>&lt;=</td><td>小于等于</td></tr><tr><td>BETWEEN</td><td>在某个范围内</td></tr><tr><td>LIKE</td><td>搜索某种模式 | 模糊判断</td></tr><tr><td>IN</td><td>指定针对某个列的多个可能值</td></tr></tbody></table></br>

- **逻辑运算符：** `()` 、`and` 、`not` 、`or`

- **特殊：**
  - 空值判断： `is null`
  - 范围判断（闭区间）：`between a and b`，可以是数值、文本或日期
  - `IN`：用于匹配多组数据，类似于 `OR`。如：
    ```sql {.line-numbers}
    SELECT stu1 FROM stuinfo
    WHERE stu1 IN ('有机鱼', '张三')
    ```

### ORDER BY

- **语法：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  ORDER BY column1 ASC | DESC;
  ```
- **结果：** 用于排序，默认 `ASC` 升序
- 多列排序：先按第一个 `column1` 来排，然后类推
- 顺序：`desc` 或者 `asc` 只对它紧跟着的第一个列名有效，其他不受影响，仍然是默认的升序。
- **自定义排序：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  ORDER BY FIELD(sorted_column, 'value1', 'value2');
  ```

### INSERT INTO

- **语法：**
  - 第一种形式无需指定要插入数据的列名，只需提供被插入的值即可：
    ```sql {.line-numbers}
    INSERT INTO table1
    VALUES (value1, value2, value3,...);
    ```
  - 第二种形式需要指定列名及被插入的值：
    ```sql {.line-numbers}
    INSERT INTO table1 (column1, column2, column3,...)
    VALUES (value1, value2, value3,...);
    ```
- **结果：** 向表中插入新纪录

### UPDATE

- **语法：**
  ```sql {.line-numbers}
  UPDATE table1
  SET column1 = value1, column2 = value2,...
  WHERE column1 = value1;
  ```
- **结果：** 更新表中已有的数据，且一定要指定 `WHERE`

### DELETE

- **语法：**
  ```sql {.line-numbers}
  DELETE FROM table1
  WHERE column1 = value1;
  ```
- **结果：** 删除行。不带 `WHERE` 时则将整个表删除，但表的结构还在
- 令：别的删除
  - `DROP table1`：将表完全删除
  - `TRUNCATE table1`：仅删除内容并释放空间，表的结构还在

<br><br>

## 高级语句

### 匹配

- **区别：**
  - `like` 整个字段匹配表达式成功才返回， 即: `re.match`
  - `regexp` 部分字符匹配表达式成功即可返回, 即：`re.search`

#### LIKE 通配符

- **语法：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  WHERE column1 LIKE xx;
  ```
- **通配符**

  - `%` ： 代替零个或多个字符
  - `_` ： 仅代替一个字符
  - `[charlist]` ： 字符列中的任意一个字符（^ 表示取反）

- **如：**
  - `%a` ：以 a 结尾的数据
  - `a%` ：以 a 开头的数据
  - `%a%` ：含有 a 的数据
  - `_a_` ：三位且中间字母是 a 的
  - `_a` ：两位且结尾字母是 a 的
  - `a_` ：两位且开头字母是 a 的
  - `[ABC]%`：以 A 或 B 或 C 开头的单词

#### REGEXP 正则表达式

- **语法：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  WHERE column1 REGEXP 'xx';
  ```

### 子查询

- 如求某列最值的其他信息时，不能单用函数，只能是再套一层：
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  WHERE column1 = (
    SELECT MAX(column1) FROM table1
  );
  ```

### JOIN

- **结果：** 基于多个表之间 相同的内容 相联动

#### INNER JOIN

- **语法：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  JOIN table2
  ON table1.column1 = table2.column2;
  ```
- **结果：** 内连接，只连接匹配的行
- 当两个表之间有相同的列名时，可用：`USING`
  ```sql {.line-numbers}
  JOIN stuscore USING (stu_id);
  -- 相当于
  JOIN stuscore ON stuinfo.stu_id = stuscore.stu_id;
  ```

#### LEFT | RIGHT JOIN

- **结果：** 当左（右）值没有时，显示 `NULL`

### AS 别名

- **语法：**
  ```sql {.line-numbers}
  SELECT column1  other_name
  FROM table1 AS '表别名';
  ```
- **结果：** 列别名则为展示表格时的表头名。别名主要是为了方便
- 如果别名中有空格，则用 `' '` 括起来
- `AS` 是可选的

### LIMIT | OFFSET

- **语法：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  LIMIT (pos,) count OFFSET count;
  ```
- **结果：**
  - `LIMIT`： 仅列出从 `pos` 开始的 `count` 个数据。
  - `OFFSET`：从 0 开始不取 `count` 个数据
- 常结合用于分页数据

### GROUP BY

- **语法：**
  ```sql {.line-numbers}
  SELECT column1, column2, ... FROM table1
  GROUP BY column1;
  ```
- **结果：** 将相同的值分组，常与 `COUNT` 一起。
- 且：可以通过 **HAVING** 进行分组的筛选（像`WHERE`）

###

<br><br>

## SQL 函数

- **固定格式：**
  ```sql {.line-numbers}
  SELECT column1 FROM table1
  WHERE function();
  ```

### 常见

- `AVG()`：求得平均数
- `SUM()`：求和
-

### IF 函数

- **语法：**
  ```sql {.line-numbers}
  IF (exp1, ret1, ret2)
  ```
- **结果：** 如果 exp1 为 true 则返回 ret1，否则返回 ret2

<br><br>

---

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
