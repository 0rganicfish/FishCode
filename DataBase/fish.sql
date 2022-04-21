-- --------
-- 实验五 ↓
-- --------

SELECT stuinfo.stu_id,
       stuinfo.stu_name,
       source.sour_name,
       stuscore.score
FROM stuinfo
         JOIN stuscore ON stuinfo.stu_id = stuscore.stu_id
         JOIN source ON source.sour_id = stuscore.sour_id
WHERE stuscore.score > 50
  and source.sour_name = '离散数学';
--
--
SELECT stuinfo.stu_name,
       source.sour_name,
       stuscore.score
FROM stuscore
         JOIN stuinfo ON stuinfo.stu_id = stuscore.stu_id
         JOIN source ON stuscore.sour_id = source.sour_id;
--
--
SELECT stuinfo.*,
       stuscore.sour_id
FROM stuinfo
         JOIN stuscore ON stuscore.stu_id = stuinfo.stu_id;
--
--
SELECT DISTINCT source.sour_name
FROM source
         JOIN stuscore ON source.sour_id = stuscore.sour_id;
--
--
SELECT *
FROM stuinfo
WHERE stuinfo.stu_id = '081206';
--
--
SElECT employees.*,
       salary.income
FROM employees
         JOIN salary ON salary.id = employees.id;
--
--
SELECT employees.name,
       income,
       outcome
FROM salary
         JOIN employees ON employees.id = salary.id
WHERE income > 2000;
--
--
SELECT employees.*
FROM employees
         JOIN salary ON salary.id = employees.id
WHERE salary.income < 2500;



-- --------
-- 实验六 ↓
-- --------

SELECT COUNT(IF(sex = '男', 1, NULL)) AS '男生数量',
       COUNT(IF(sex = '女', 1, NULL)) AS '女生数量'
FROM stuinfo;

SELECT sex,
       COUNT(*) AS '数量'
FROM stuinfo
GROUP BY sex;

SELECT stu_name, credit
FROM stuinfo
WHERE credit >= (
    SELECT AVG(credit)
    FROM stuinfo
)
ORDER BY credit DESC;

SELECT pro_name           '专业名',
       FLOOR(AVG(credit)) '平均学分',
       COUNT(pro_name)    '人数'
FROM stuinfo
GROUP BY pro_name;

SELECT pro_name                      '专业名',
       COUNT(IF(sex = '男', 1, NULL)) '男生数量',
       COUNT(IF(sex = '女', 1, NULL)) '女生数量',
       COUNT(*)                      '专业人数'
FROM stuinfo
GROUP BY pro_name;

SELECT stu_id, score
FROM stuscore
         JOIN stuinfo USING (stu_id)
WHERE pro_name = '计算机'
  AND score >= 75;

SELECT stu_name, pro_name, sour_name, score
FROM stuscore
         JOIN stuinfo USING (stu_id)
         JOIN source USING (sour_id)
WHERE pro_name = '计算机'
  AND sour_name = '离散数学'
ORDER BY score DESC;

--
--

SELECT degree,
       COUNT(*) AS '数量'
FROM employees
GROUP BY degree
ORDER BY degree;

SELECT workname '部门名称',
       COUNT(*) '人数'
FROM work
         JOIN employees USING (workid)
GROUP BY workid
HAVING COUNT(*) >= 3;

SELECT worktime '工作时长',
       COUNT(*) '人数'
FROM employees
GROUP BY worktime
ORDER BY worktime DESC;

SELECT name, sex, worktime
FROM employees
ORDER BY (SELECT income
          FROM salary
          WHERE employees.id = salary.id) DESC;

SELECT *
FROM employees
WHERE degree = '本科'
UNION
SELECT *
FROM employees
WHERE degree = '硕士';

handler salary open;
handler salary read first WHERE income > 2500;
handler salary read next WHERE income > 2500;
handler salary read next WHERE income > 2500;

use fish;
SELECT stu_id,
       stu_name,
       credit,
       (
           CASE
               WHEN credit IS NULL THEN '未选课'
               WHEN credit < 42 THEN '不及格'
               WHEN credit >= 42 AND credit <= 46 THEN '合格'
               WHEN credit >= 47 THEN '优秀'
               END) '等级'
FROM stuinfo;


-- -----
--
-- -----

create table if not exists fishstu
(
    id    char(6)      not null primary key,
    name  varchar(255) not null,
    born  date         not null,
    score int(3)       not null
) ENGINE = InnoDb
  DEFAULT CHARSET = utf8;

insert into fishstu
    value ('210101', '有机鱼', '2000-01-01', 75),
    ('210102', '无机鱼', '2002-05-04', 77),
    ('210201', '咩咩', '2001-10-30', 86),
    ('210202', '蛤哦', '2003-05-02', 57);
select *
from fishstu;

update fishstu
set score = 76
where id = '210102';

select *
from fishstu
order by rand()
limit 1;

alter table fishstu
    change column name name varchar(64) not null;

create table fishes
(
    id     char(6) primary key auto_increment,
    name   varchar(64) not null,
    sex    char(1)     not null,
    hashes char(8) unique

);

-- ------
-- 实验七
-- -----

create or replace view csinfo
as
select stu_id, stu_name, pro_name, sour_id, score
from stuinfo
         join stuscore using (stu_id)
where pro_name = '通信工程';
select *
from csinfo;

create or replace view stusour(stu_id, sour_count)
as
select stu_id, count(*)
from stuscore
group by stu_id;


create or replace view csavg(stu_id, avg_score)
as
select stu_id, avg(score)
from csinfo
group by stu_id;
select *
from csavg;

select stu_id, avg_score
from csavg
where avg_score >= 85;

create or replace view cs1994
as
select *
from stuinfo
where born like '1994%';
insert into cs1994
    value ('081256', '张三', '通信工程', 1, '1994-10-21', 50, NULL);
select *
from cs1994;

update csinfo
set score = 85
where stu_id = '081210';
select *
from csinfo
where stu_id = '081210';

delete
from cs1994
where stu_id = '081256';

create or replace view csinfo
as
select stu_id, stu_name, credit
from stuinfo
where pro_name = '通信工程';

create view ds_view
as
select *
from work;

create or replace view emp_view
as
select id, name, income
from employees
         join salary using (id);

create view emp_all
as
select id, name, workname, income
from employees
         join work using (workid)
         join salary using (id);

select workname
from ds_view;

select name, income
from emp_view
where name = '李丽';

insert into ds_view
    value (6, '财务部', '财务管理');

update ds_view
set workname = '生产部'
where workid = 5;

-- -----
-- 函数
-- -----

select 0x43, cast(0x43 as unsigned) as '数字';
set @HI = hex('HI');
select @HI, unhex(@HI) as '字符';
select true, false;
select ceil(2.23);
select Greatest(1, 23, 4, 3, 24, 23, 4, 23, 3);
select Ln(2), log(2);
set @x = 1000;
select floor(rand() * @x);
select Round(1.643);
select Length('miemie');
Select Insert('mie.com', 1, 3, 'fish');
Set @x = 123.345;
Set @y = Format(@x, 2);
Select @y;

Set @s1 = 'mie.com', @s2 = 'fish';
Set @ans = Insert(@s1, 1, Locate('.', @s1) - 1, @s2);
Set @ans = 'mie.fish.com';
Select Substr(@ans, 5);
Select Position(@s2 in @ans);
Select Locate('fish', 'mie.fish.com');

Select Curdate(), -- 年-月-日
       Curtime(), -- 时-分-秒
       Current_timestamp(); -- 年月日时分秒

Set @t = 6;
select Adddate(Curdate(), 2000),
       Addtime(Curtime(), @t);
SELECT Hour(CURRENT_TIMESTAMP());
SELECT Datediff(ADDDATE(CURRENT_TIMESTAMP(), 100), CURRENT_TIMESTAMP());
SELECT Date_format(CURRENT_TIMESTAMP(), '%Y年%m月%d日 | %h时%m分%s秒');

Select DayofMonth(Curdate()),
       DayofWeek(Curdate()),
       DayofYear(Curdate()),
       Dayname(Curdate());

Select Extract(day From CURRENT_TIMESTAMP());

SELECT UNIX_TIMESTAMP();

-- ----
-- 存储
-- ----

delimiter //
create procedure fishpro()
begin
    select stu_id, stu_name, born
    from stuinfo;
end //
delimiter ;
call fishpro();

delimiter //
create procedure mie(in a int)
begin
    select a;
end //
set @in_a = 123;
call mie(@in_a);
select @in_a;
delimiter ;

delimiter //
create procedure fishstu(in in_sex int)
begin
    select stu_id, stu_name, sex
    from stuinfo
    where sex = in_sex;
end //
delimiter ;
call fishstu(1);
call fishstu(0);

delimiter //
create procedure fishsex(in in_sex int,
                         out sex_total int)
begin
    select count(sex)
    into sex_total
    from stuinfo
    where sex = in_sex;
end //
call fishsex(1, @sex1);
select @sex1;

delimiter //
create procedure counts(INOUT cnt int, IN x int)
begin
    set cnt = cnt + x;
end //
set @a = 0;
call counts(@a, 12);
select @a;
delimiter ;

