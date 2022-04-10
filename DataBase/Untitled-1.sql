SELECT stuinfo.stu_id,
    stuinfo.stu_name,
    sourse.sour_name,
    stuscore.score
FROM stuinfo
    JOIN stuscore ON stuinfo.stu_id = stuscore.stu_id
    JOIN sourse ON sourse.sour_id = stuscore.sour_id
WHERE stuscore.score > 50
    and sourse.sour_name = '离散数学';
-- 
-- 
--
SELECT stuinfo.stu_name,
    sourse.sour_name,
    stuscore.score
FROM stuscore
    JOIN stuinfo ON stuinfo.stu_id = stuscore.stu_id
    JOIN sourse ON stuscore.sour_id = sourse.sour_id;
--
--
--
SELECT stuinfo.*,
    stuscore.sour_id
FROM stuinfo
    JOIN stuscore ON stuscore.stu_id = stuinfo.stu_id;
--
--
--
SELECT DISTINCT sourse.sour_name
FROM sourse
    JOIN stuscore ON sourse.sour_id = stuscore.sour_id;
--
--
--
SELECT *
FROM stuinfo
WHERE stuinfo.stu_id = '081206';
--
--
--
SELECT *
FROM stuinfo
WHERE stuinfo.bron LIKE "2000%";
--
--
--
SELECT stuinfo.stu_id,
    stuinfo.stu_name,
    stuinfo.pro_name,
    stuinfo.sex
FROM stuinfo
WHERE stuinfo.stu_name LIKE "王%";
--
--
--
SELECT stu_name,
    stu_id,
    TIMESTAMPDIFF(DAY, bron, now()) - (
        SELECT TIMESTAMPDIFF(DAY, bron, now())
        FROM stuinfo
        WHERE stu_id = "081208"
    ) DIFF
FROM stuinfo
WHERE stu_id <> "081208"
    AND sex = "男";
--
--
--
SELECT stu_name,
    stu_id
FROM stuinfo
WHERE sex = (
        SELECT sex
        FROM stuinfo
        WHERE stu_id = "081108"
    )
    AND total_period = (
        SELECT total_period
        FROM stuinfo
        WHERE stu_id = "081108"
    );
--
--
--
SElECT employee.*,
    salary.income
FROM employee
    JOIN salary ON salary.id = employee.id;
--
--
--
SELECT work.workname
FROM work
    JOIN employee ON employee.workid = work.workid
WHERE employee.name = "王林";
--
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
--
SELECT employee.*
FROM employee
    JOIN salary ON salary.id = employee.id
WHERE salary.income < 2500;
--
--
 