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
         JOIN sourse USING (sour_id)
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



