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
SElECT employee.*,
       salary.income
FROM employee
         JOIN salary ON salary.id = employee.id;
--
--
SELECT employee.name,
       income,
       expense
FROM salary
         JOIN employee ON employee.id = salary.id
WHERE income > 2000;
--
--
SELECT employee.*
FROM employee
         JOIN salary ON salary.id = employee.id
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

SELECT stu_name, total_credit
FROM stuinfo
WHERE total_credit >= (
    SELECT AVG(total_credit)
    FROM stuinfo
)
ORDER BY total_credit DESC;

SELECT pro_name                 '专业名',
       FLOOR(AVG(total_credit)) '平均学分',
       COUNT(pro_name)          '人数'
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
FROM employee
GROUP BY degree
ORDER BY degree;

SELECT workname '部门名称',
       COUNT(*) '人数'
FROM work
         JOIN employee USING (workid)
GROUP BY workid
HAVING COUNT(*) >= 3;

SELECT worktime '工作时长',
       COUNT(*) '人数'
FROM employee
GROUP BY worktime
ORDER BY worktime DESC;

SELECT name, sex, worktime
FROM employee
ORDER BY (SELECT income
          FROM salary
          WHERE employee.id = salary.id) DESC;

SELECT *
FROM employee
WHERE degree = '本科'
UNION
SELECT *
FROM employee
WHERE degree = '硕士';

handler salary open;
handler salary read first WHERE income > 2500;
handler salary read next WHERE income > 2500;
handler salary read next WHERE income > 2500;

use fish;
SELECT stu_id,
       stu_name,
       total_credit,
       (
           CASE
               WHEN total_credit IS NULL THEN '未选课'
               WHEN total_credit < 42 THEN '不及格'
               WHEN total_credit >= 42 AND total_credit <= 46 THEN '合格'
               WHEN total_credit >= 47 THEN '优秀'
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


create or replace view csinfo
as
select stu_id, stu_name, pro_name, sour_id, score
from stuinfo
         join stuscore using (stu_id)
where pro_name = '计算机';
select *
from csinfo;

create or replace view stusour(stu_id, sour_count)
as
select stu_id, count(*)
from stuscore
group by stu_id;
select *
from stusour;

create or replace view csavg(stu_id, avg_score)
as
select stu_id, avg(score)
from csinfo
group by stu_id;
select *
from csavg;

select stu_id, avg_score
from csavg
where avg_score >= 75;

