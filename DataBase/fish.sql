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



