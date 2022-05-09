/*
 Date: 2022-05-09
 */
create database if not exists fishwork;
set names utf8mb4; -- 四个字节一个字符
set foreign_key_checks = 0;
use fishwork;


-- 登录用户信息
drop table if exists users;
create table if not exists users
(
    Id        int auto_increment primary key,
    Username  varchar(10) not null,
    Passwords varchar(20) not null,
    Power     boolean     not null
);

-- 学生信息
drop table if exists stuinfo;
create table if not exists stuinfo
(
    Stuid       char(10) primary key,
    StuName     varchar(255) not null,
    Sex         boolean      not null,
    Major       varchar(255) not null,
    TotalCredit float,
    Ranking     int,
    Photo       varchar(255),
    Comments    varchar(255)
);

-- 课程信息
drop table if exists course;
create table if not exists course
(
    CourseId   char(3) primary key,
    CourseName varchar(255) not null,
    LearnTime  int          not null,
    Credit     float        not null
);

-- 成绩信息
drop table if exists score;
create table if not exists score
(
    StuId    char(10) not null,
    CourseID char(3)  not null,
    Score    float,
    Credit   float
);

-- 初始数据 --

-- 课程数据
insert into course
values ('101', '数据库应用技术', 30, 4),
       ('102', '面向对象程序设计', 30, 4),
       ('103', '高等数学2', 30, 2),
       ('104', '大学物理', 30, 2),
       ('105', '大学英语2', 30, 2),
       ('106', 'Web 设计', 30, 4);

-- 学生数据
insert into stuinfo
values ('2114100328', '有机鱼', 1, '计算机类', null, null, null, null),
       ('2114100306', '杨咩咩', 1, '计算机类', null, null, null, null),
       ('2114100314', '蓝习之', 1, '计算机类', null, null, null, null),
--       ('2114100350', '张三', 0, '计算机类', null, null, null, null),
--        ('2114100351', '陈思思', 0, '计算机类', null, null, null, null),
       ('2114100128', '何唐码朗', 1, '网络工程', null, null, null, null),
       ('2114100106', '蒋素', 0, '网络工程', null, null, null, null),
       ('2114100114', '程平平', 1, '网络工程', null, null, null, null);
--       ('2114100151', '陈圆圆', 0, '网络工程', null, null, null, null),
--      ('2114100152', '潘洋', 1, '网络工程', null, null, null, null);

-- 成绩数据
insert into score
values ('2114100328', '101', 80, 3),
       ('2114100328', '102', 81, 3.1),
       ('2114100328', '103', 82, 3.2),
       ('2114100328', '105', 83, 3.3),
       ('2114100306', '101', 84, 3.4),
       ('2114100306', '102', 85, 3.5),
       ('2114100306', '103', 86, 3.6),
       ('2114100306', '105', 87, 3.7),
       ('2114100314', '101', 88, 3.8),
       ('2114100314', '102', 89, 3.9),
       ('2114100314', '103', 90, 4),
       ('2114100314', '105', 91, 4.1),
       ('2114100128', '101', 80, 3),
       ('2114100128', '106', 81, 3.1),
       ('2114100128', '104', 82, 3.2),
       ('2114100128', '105', 83, 3.3),
       ('2114100106', '101', 84, 3.4),
       ('2114100106', '106', 85, 3.5),
       ('2114100106', '104', 86, 3.6),
       ('2114100106', '105', 87, 3.7),
       ('2114100114', '101', 88, 3.8),
       ('2114100114', '106', 89, 3.9),
       ('2114100114', '104', 90, 4),
       ('2114100114', '105', 91, 4.1);

-- 用户信息
insert into users
values (0, 'fish', 'fishroot', 1),
       (0, '2114100328', 'Fishfish', 0);