# SQL

- [README](../README.md)

[TOC]

## 基础语句

### Create

- **语法：**
  ```sql {.line-numbers}
  Create table if not exists table1
  (
    column1 type
  )ENGINE = InnoDb
  DEFAULT CHARSET = utf8;
  ```
- **结果：** 创建表
- **表属性**
  1. 选项
     1. 指定列选项：`default`，`comment`
     2. 指定列选项：`engine`，`auto_increment`，`comment`
  2. 约束
     1. `not null`：非空约束
     2. `unique`：唯一性约束
     3. `primary key`：住建约束
     4. `foreign key`：外键
     5. `check`：检查 —— `enum`，`set` <sup><b>\*</b></sup>
- <sup><b>\*</b></sup> 约束中的 `enum`，`set`：
  - `enum`：单选字符串数据类型，适合存储表单界面中的 “单选值”。设定 enum 的时候，需要给定“固定的几个选项”；存储的时候就只存储其中的一个值。
    - 设定 enum 的格式：
      ```sql {.line-numbers}
      enum("value1", "value2", "value3", ...);
      ```
      &emsp;&emsp; 实际上，enum 的选项都会对应一个数字，依次是 1，2，3，4，5...，最多有 65535 个选项。使用的时候，可以使用选项的字符串格式，也可以使用对应的数字。
  - `set`：其实就是可多选的 enum。可插入多值，Select 出来的也是多值

### Drop

- **语法：**
  ```sql {.line-numbers}
  Drop table table1;
  ```
- **结果：** 删除表

### Insert into

- **语法：**
  - 第一种形式无需指定要插入数据的列名，只需提供被插入的值即可：
    ```sql {.line-numbers}
    Insert into table1
    VALUES (value1, value2, value3,...);
    ```
  - 第二种形式需要指定列名及被插入的值：
    ```sql {.line-numbers}
    Insert into table1 (column1, column2, column3,...)
    VALUES (value1, value2, value3,...);
    ```
- **结果：** 向表中插入新纪录

### Select

- **语法：**
  ```sql {.line-numbers}
  Select column1
  From table1;
  ```
- **结果：** 列出 `table` 中列名为 `column1`的数据，`*` 则为表中所有数据
- 加上 `DISTINCT` 则列出 去重 后的数据

### Where

- **语法：**
  ```sql {.line-numbers}
  Select column1 From table1
  Where column1 operator value;
  ```
- **结果：** 用于 **过滤** 列数据

- **`operator` 运算符：**

    <table class="reference"><tbody><tr><th width="20%">运算符</th><th width="80%">描述</th></tr><tr><td>=</td><td>等于</td></tr><tr><td>&lt;&gt;</td><td>不等于</td></tr><tr><td>&gt;</td><td>大于</td></tr><tr><td>&lt;</td><td>小于</td></tr><tr><td>&gt;=</td><td>大于等于</td></tr><tr><td>&lt;=</td><td>小于等于</td></tr><tr><td>BETWEEN</td><td>在某个范围内</td></tr><tr><td>Like</td><td>搜索某种模式 | 模糊判断</td></tr><tr><td>in</td><td>指定针对某个列的多个可能值</td></tr></tbody></table></br>

- **逻辑运算符：** `()` 、`and` 、`not` 、`or`

- **特殊：**
  - 空值判断： `is null`
  - 范围判断（闭区间）：`between a and b`，可以是数值、文本或日期
  - `in`：用于匹配多组数据，类似于 `OR`。如：
    ```sql {.line-numbers}
    Select stu1 From stuinfo
    Where stu1 in ('有机鱼', '张三')
    ```

### Order by

- **语法：**
  ```sql {.line-numbers}
  Select column1 From table1
  Order by column1 ASC | DESC;
  ```
- **结果：** 用于排序，默认 `ASC` 升序
- 多列排序：先按第一个 `column1` 来排，然后类推
- 顺序：`desc` 或者 `asc` 只对它紧跟着的第一个列名有效，其他不受影响，仍然是默认的升序。
- **自定义排序：**
  ```sql {.line-numbers}
  Select column1 From table1
  Order by FIELD(sorted_column, 'value1', 'value2');
  ```
- 随机选择 n 行：
  ```sql {.line-numbers}
  Select table1 From column1
  Order by rand() Limit n;
  ```

### update

- **语法：**
  ```sql {.line-numbers}
  update table1
  SET column1 = value1
  Where column1 = value1;
  ```
- **结果：** 更新(修改)表中已有的数据，且一定要指定 `Where`

### Delete

- **语法：**
  ```sql {.line-numbers}
  Delete From table1
  Where column1 = value1;
  ```
- **结果：** 删除行。不带 `Where` 时则将整个表删除，但表的结构还在
- 令：别的删除
  - `Drop table1`：将表完全删除
  - `TRUNCATE table1`：仅删除内容并释放空间，表的结构还在

<br><br>

## 高级语句

### 匹配

- **区别：**

  - `like` 整个字段匹配表达式成功才返回， 即: `re.match`
  - `regexp` 部分字符匹配表达式成功即可返回, 即：`re.search`
    <br>

- **`Like` 通配符**
  - **语法：**
    ```sql {.line-numbers}
    Select column1 From table1
    Where column1 Like xx;
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
- **`REGEXP` 正则表达式**
  - **语法：**
    ```sql {.line-numbers}
    Select column1 From table1
    Where column1 REGEXP 'xx';
    ```

### 子查询

- 如求某列最值的其他信息时，不能单用函数，只能是再套一层：
  ```sql {.line-numbers}
  Select column1 From table1
  Where column1 = (
    Select MAX(column1) From table1
  );
  ```

### Join

- **结果：** 基于多个表之间 **相同的内容** 相联动
- **inner join**

  - **语法：**
    ```sql {.line-numbers}
    Select column1 From table1
    Join table2
    ON table1.column1 = table2.column2;
    ```
  - **结果：** 内连接，只连接匹配的行
  - 当两个表之间有相同的列名时，可用：`USING`
    ```sql {.line-numbers}
    Join stuscore USING (stu_id);
    -- 相当于
    Join stuscore ON stuinfo.stu_id = stuscore.stu_id;
    ```

- **LEFT | RIGHT Join**
  - **结果：** 当左（右）值没有时，显示 `NULL`

### As 别名

- **语法：**
  ```sql {.line-numbers}
  Select column1  other_name
  From table1 As '表别名';
  ```
- **结果：** 列别名则为展示表格时的表头名。别名主要是为了方便
- 如果别名中有空格，则用 `' '` 括起来
- `As` 是可选的

### Limit | Offset

- **语法：**
  ```sql {.line-numbers}
  Select column1 From table1
  Limit (pos,) count Offset count;
  ```
- **结果：**
  - `Limit`： 仅列出从 `pos` 开始的 `count` 个数据。
  - `Offset`：从 0 开始不取 `count` 个数据
- 常结合用于分页数据

### Group by

- **语法：**
  ```sql {.line-numbers}
  Select column1, column2, ... From table1
  Group by column1;
  ```
- **结果：** 将相同的值分组，常与 `COUNT` 一起。
- 且：可以通过 **HAVING** 进行分组的筛选（像`Where`）

### Delimiter

- **语法：**
  ```sql {.line-numbers}
  Delimiter//
  -- 语句;
  -- 语句;
  Delimiter;
  ```
- **结果：** 分隔符，表示在这之间的分号不再当做程序的结束符，而只是语句之间的分隔符。

###

<br><br>

## SQL 函数

- **固定格式：**
  ```sql {.line-numbers}
  Select column1 From table1
  Where function();
  ```

### 数字函数

- `Avg()`：求得平均数，`Sum()`：求和
- `Ceil()`：向大取整； `floor`：向小取整
- `Greatest()`：列表中的最大值； `Least`：最小值
- `Floor(Rand() * @x)`：0 到 @x 之间的随机数
- `Round(@x)`：将 @x 四舍五入至整数
- `Format(x, n)`：将数字 x 四舍五入地保留 n 位小数

### 字符串函数

- MySQL 的字符串下标是以 1 开始的
- `Insert(s1, x, len, s2)`：将 s1 中下标为 x，长度为 len 的替换为 s2
  ```sql {.line-numbers}
  Select Insert('mie.com', 1, 3, 'fish'); -- fish.com
  ```
- `Length(s)`：s 的长度
- `Concat(s1, s2, s3, ...)`：将这些字符串拼接起来
- `Upper(s)`、`Lower(s)`：全部转为大写 | 小写
- `Trim(s)`：去掉 s 所有的空格（也有 LTrim 和 RTrim）
- `Substr(s, pos, len)`：返回从 pos 开始截取 s 长度为 len 的字符串
- `Locate(s1, s2)`：返回 s1 在 s2 的位置
- `Repeat(s, n)`：返回将 s 重复 n 次
- `Reverse(s)`：返回将 s 翻转
- `Strcmp(s1, s2)`：s1 == s2 返回 0， s1 < s2 返回-1， s1 > s2 返回 1

### 日期函数

- 获取时间：
  ```sql {.line-numbers}
  Select Curdate(), -- 年-月-日
         Curtime(), -- 时-分-秒
         Now(), -- 静态的时间
         sysdate(), -- 动态获取的时间
         localtime,
         Current_timestamp(); -- 年月日时分秒
  -- 时间戳：
  Select Unix_timestamp();
  ```
- 加减时间：
  ```sql {.line-numbers}
  Select  date_sub(t, interval x day | hour ...),
          date_add(t, interval x day | hour ...);
  ```
- 提取时间：
  ```sql {.line-numbers}
  Select Time(@t) | Date() | Day() | Hour() ...
  -- or：
  Select Extract(Type From t);
  ```
- 时间差：
  ```sql {.line-numbers}
  Select Datediff(t1, t2),
         Timediff(t1, t2); -- 返回 t1 - t2
  ```
- 今天是第几？
  ```sql {.line-numbers}
  Select DayofMonth(t), -- 本月第几天
        DayofWeek(t), -- 本周第几天
        DayofYear(t), -- 今年第几天
        Dayname(t), -- 今天星期几
        Monthname(t); -- 今天几月
  ```
- 格式化输出时间
  ```sql {.line-numbers}
  Select Date_format(t, '%Y年%m月%d日 %h时%m分%s秒');
  -- 格式化时间戳：
  Select From_unixtime(stamp, s);
  -- 字符串到时间
  Select str_to_date(str, 'format');
  ```

### 高级函数

- **if 函数**
  - **语法：**
    ```sql {.line-numbers}
    if (exp1, ret1, ret2)
    ```
  - **结果：** 如果 exp1 为 true 则返回 ret1，否则返回 ret2
- **Cast**：类型转换
  ```sql {.line-numbers}
  Cast('mie' as Binary | Decimal | Char |
                Signed | Unsigned | Date |
                Datetime Time);
  ```
- **Conv(x, a, b)：** 将 a 进制的 x 转为 b 进制

  <br><br>

## 存储过程

主要是用于封装数据库，且便于查询。相当于是函数。

### 一些......

- **创建：**
  ```sql {.line-numbers}
  Create procedure name_(parameters para_name para_type)
  ```
- **参数：**

  - `in`：仅传形参，不可变，没返回。如：

    ```sql {.line-numbers}
    delimiter //
    Create procedure fishstu(in in_sex int)
    begin
        Select stu_id, stu_name, sex
        from stuinfo
        where sex = in_sex;
    end //

    call fishstu(1);--sex=1 的数据
    ```

  - `out`：不传参，可改变存储值，并可返回。如：

    ```sql {.line-numbers}
    delimiter //
    Create procedure fishsex(in in_sex int,
                            out sex_total int)
    begin
        Select count(sex) into sex_total
        from stuinfo
        where sex = in_sex;
    end //

    call fishsex(1, @sex1);
    Select @sex1; --sex=1 的数量
    ```

  - `inout`：传参可变，可返回。如：

    ```sql {.line-numbers}
    delimiter //
    Create procedure counts(inout cnt int, in x int)
    begin
        set cnt = cnt + x;
    end //

    set @a = 0;
    call counts(@a, 12);
    Select @a --12
    ```

### 语句

- **判断**

  - **if**
    ```sql {.line-numbers}
    if exp1
    then xx;
    elseif exp2
    then xx;
    else xx;
    end if;
    ```
  - **case**
    ```sql {.line-numbers}
    case
      when exp1 then xx
      when exp2 then xx
      else xx
      end;
    ```

- **循环：**

  - **while**
    ```sql {.line-numbers}
    while exp do
      xx;
    end while;
    ```
  - **repeat**
    ```sql {.line-numbers}
    repeat
      xx;
    until exp
    end repeat;
    ```
  - **loop**
    ```sql {.line-numbers}
    loop_name:
    loop
      if exp1 then
        xx;
      elseif exp2 then
        leave loop_name; -- break
      elseif exp3 then
        iterate loop_name; -- continue
      end if;
      xx;
    end loop;
    ```

<br><br>

---

# 自救救

## 密码失败

- 管理员 cmd `cd` 到 `bin`：
  ```batch {.line-numbers}
  cd C:\Program Files\MySQL\MySQL Server 8.0\bin
  ```
- 关闭 MySQL 服务
  ```batch {.line-numbers}
  net stop mysql
  ```
- 跳过密码登录
  ```batch {.line-numbers}
  mysqld --console --skip-grant-tables --shared-memory
  ```
- 新建 cmd 窗口，输入 `mysql` 即可进入
- 更改密码
  - 使用 MySQL 数据库：
  ```batch {.line-numbers}
  use mysql;
  ```
  - 一定要先更新权限：
  ```batch {.line-numbers}
  flush privileges;
  ```
  - 更新密码：
  ```batch {.line-numbers}
  alter user 'root' @'localhost' IDENTifIED BY '新密码';
  ```
  > REF: [MySQL8 root 密码](https://blog.csdn.net/weixin_42359480/article/details/89931700)

<br>

## 无法 启动 | 关闭 MySQL 服务

- 查找端口占用
  ```batch {.line-numbers}
  netstat -ano
  ```
- 找到 (`Ctrl + F`) 3306 端口的 PID (行尾数字)
- 可以去 **任务管理器** $ \to $ 详细信息 $ \to $ 按 `PID` 排序 $ \to $ 找到并结束该端口的进程
- 就可以用管理员 cmd 启动 MySQL 服务了
