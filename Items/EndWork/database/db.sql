/*
 CreateDate: 2022-05-09 16:52
 */
create database if not exists fishwork;
set names utf8mb4; -- 四个字节一个字符
set foreign_key_checks = 0;
use fishwork;


-- 登录用户信息
drop table if exists users;
create table if not exists users
(
    id        int auto_increment primary key,
    userName  varchar(10) not null,
    passWords varchar(20) not null,
    power     boolean     not null
);

-- 学生信息
drop table if exists stuinfo;
create table if not exists stuinfo
(
    stuId       char(10) primary key,
    stuName     varchar(255) not null,
    sex         boolean      not null,
    major       varchar(255) not null,
    totalCredit float,
    comments    varchar(255)
);

-- 课程信息
drop table if exists course;
create table if not exists course
(
    courseId   char(3) primary key,
    courseName varchar(255) not null,
    learnTime  int          not null,
    credit     float        not null,
    type       varchar(255) not null
);

-- 成绩信息
drop table if exists score;
create table if not exists score
(
    stuId      char(10) not null,
    courseId   char(3)  not null,
    scoreGot   float,
    creditGot  float,
    gradePoint float,
    comments   varchar(255)
);

-- 初始数据 --

-- 课程数据
insert into course
values ('101', '数据库应用技术', 30, 4, '必修课'),
       ('102', '面向对象程序设计', 30, 4, '必修课'),
       ('103', '高等数学2', 30, 2, '必修课'),
       ('104', '大学物理', 30, 2, '必修课'),
       ('105', '大学英语2', 30, 2, '必修课'),
       ('106', 'Web 设计', 30, 4, '必修课');

-- 学生数据
insert into stuinfo
values ('2114100328', '有机鱼', 1, '计算机类', 14, null),
       ('2114100306', '杨咩咩', 1, '计算机类', 14, null),
       ('2114100314', '蓝习之', 1, '计算机类', 14, null),
--       ('2114100350', '张三', 0, '计算机类', null, null, null, null),
--        ('2114100351', '陈思思', 0, '计算机类', null, null, null, null),
       ('2114110128', '何唐码朗', 1, '网络工程', 14, null),
       ('2114110106', '蒋素', 0, '网络工程', 14, null),
       ('2114110114', '程平平', 1, '网络工程', 14, null);
--       ('2114100151', '陈圆圆', 0, '网络工程', null, null, null, null),
--      ('2114100152', '潘洋', 1, '网络工程', null, null, null, null);

-- 成绩数据
INSERT INTO fishwork.score
VALUES ('2114100328', '101', 80, 4, 3, null),
       ('2114100328', '102', 81, 4, 3.1, null),
       ('2114100328', '103', 82, 2, 3.2, null),
       ('2114100328', '104', 83, 2, 3.3, null),
       ('2114100328', '105', 88, 2, 3.3, null),
       ('2114100306', '101', 84, 4, 3.4, null),
       ('2114100306', '102', 85, 4, 3.5, null),
       ('2114100306', '103', 86, 2, 3.6, null),
       ('2114100306', '104', 83, 2, 3.3, null),
       ('2114100306', '105', 87, 2, 3.7, null),
       ('2114100314', '101', 88, 4, 3.8, null),
       ('2114100314', '102', 89, 4, 3.9, null),
       ('2114100314', '103', 90, 2, 4, null),
       ('2114100314', '105', 91, 2, 4.1, null),
       ('2114100314', '106', 89, 4, 3.9, null),
       ('2114110128', '101', 80, 4, 3, null),
       ('2114110128', '102', 81, 4, 3.1, null),
       ('2114110128', '106', 81, 4, 3.1, null),
       ('2114110128', '104', 82, 2, 3.2, null),
       ('2114110128', '105', 83, 2, 3.3, null),
       ('2114110106', '101', 84, 4, 3.4, null),
       ('2114110106', '103', 86, 2, 3.6, null),
       ('2114110106', '106', 85, 4, 3.5, null),
       ('2114110106', '104', 86, 2, 3.6, null),
       ('2114110106', '105', 87, 2, 3.7, null),
       ('2114110114', '101', 88, 4, 3.8, null),
       ('2114110114', '106', 89, 4, 3.9, null),
       ('2114110114', '104', 90, 2, 4, null),
       ('2114110114', '105', 91, 2, 4.1, null),
       ('2114110114', '103', 86, 2, 3.6, null);


-- 用户信息
insert into users
values (0, '2114100328', 'Fishfish', 0),
       (0, 'fishroot', 'fishroot', 1);

# select CourseName, Credit, Type, scoreGot, Credit, CreditGot, score.Comments
# from score
#          join stuinfo using (StuId)
#          join course using (CourseID)
# where Stuid = '2114100328';

# select CourseID, CourseName, LearnTime, Credit, Type
# from course join score using (CourseId)
# where StuId = '2114100328';

# select StuId, StuName, format(avg(GradePoint), 1)
# from stuinfo join score using (Stuid)
# where Stuid = '2114100328';


# select `stuName`, `stuId`, `major`, format(avg(`gradePoint`), 1) GPA, `stuinfo`.`comments`
# from `stuinfo` join `score` using (`stuId`) group by `stuId`;


# create temporary table idd
# select stuId
# from stuinfo;
# ;
#
# update stuinfo
# set totalCredit = (select sum(creditGot)
#                    from score
#                    where score.stuId in (select * from idd))
# where stuId in (select * from idd);

