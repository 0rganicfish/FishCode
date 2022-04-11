/*
 Navicat Premium Data Transfer

 Source Server         : FishSQL
 Source Server Type    : MySQL
 Source Server Version : 80028
 Source Host           : localhost:3306
 Source Schema         : fish

 Target Server Type    : MySQL
 Target Server Version : 80028
 File Encoding         : 65001

 Date: 11/04/2022 14:00:10
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for employee
-- ----------------------------
DROP TABLE IF EXISTS `employee`;
CREATE TABLE `employee`
(
    `id`       varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `name`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `degree`   varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `born`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `sex`      varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `worktime` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `address`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `phone`    varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `workid`   varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of employee
-- ----------------------------
INSERT INTO `employee`
VALUES ('000001', '王林', '大专', '1966-01-23', '1', '8', '中山路32-1-508', '83355668', '2');
INSERT INTO `employee`
VALUES ('010008', '伍容华', '本科', '1976-03-28', '1', '3', '北京东路100-2', '833211321', '1');
INSERT INTO `employee`
VALUES ('011112', '李红', '本科', '1977-03-05', '1', '4', '东风路12-1-3', '82344553', '2');
INSERT INTO `employee`
VALUES ('020010', '王向荣', '硕士', '1982-12-09', '1', '2', '四牌路10-0-108', '83792361', '1');
INSERT INTO `employee`
VALUES ('020018', '李丽', '大专', '1960-07-30', '0', '6', '中山东路102-2', '83413301', '1');
INSERT INTO `employee`
VALUES ('102201', '刘明', '本科', '1972-10-18', '1', '3', '虎踞路100-2', '83606608', '5');
INSERT INTO `employee`
VALUES ('102208', '朱俊', '硕士', '1965-09-28', '1', '2', '牌楼巷5-3-106', '84708817', '5');
INSERT INTO `employee`
VALUES ('108991', '钟敏', '硕士', '1979-08-10', '0', '4', '中山路10-3-105', '83346722', '3');
INSERT INTO `employee`
VALUES ('111006', '张石兵', '本科', '1974-10-01', '1', '1', '解放路34-1-203', '84563418', '5');
INSERT INTO `employee`
VALUES ('210678', '林涛', '大专', '1977-04-02', '1', '2', '中山北路24-35', '83467336', '3');
INSERT INTO `employee`
VALUES ('302566', '李玉敏', '本科', '1968-09-20', '1', '3', '热河路209-3', '58765991', '4');
INSERT INTO `employee`
VALUES ('308759', '叶凡', '本科', '1978-11-18', '1', '2', '北京西路3-7-52', '83308901', '4');
INSERT INTO `employee`
VALUES ('504209', '陈林琳', '大专', '1969-09-03', '0', '5', '汉中路120-4-12', '84468158', '4');

-- ----------------------------
-- Table structure for salary
-- ----------------------------
DROP TABLE IF EXISTS `salary`;
CREATE TABLE `salary`
(
    `id`      varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `income`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `expense` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of salary
-- ----------------------------
INSERT INTO `salary`
VALUES ('000001', '2100.8', '123.09');
INSERT INTO `salary`
VALUES ('010008', '1582.62', '88.03');
INSERT INTO `salary`
VALUES ('011112', '2500.5', '103.5');
INSERT INTO `salary`
VALUES ('020010', '2860', '298');
INSERT INTO `salary`
VALUES ('020018', '2347.68', '180');
INSERT INTO `salary`
VALUES ('102201', '2569.88', '185.65');
INSERT INTO `salary`
VALUES ('102208', '1980', '100');
INSERT INTO `salary`
VALUES ('108991', '3259.98', '281.52');
INSERT INTO `salary`
VALUES ('111006', '1987.01', '79.58');
INSERT INTO `salary`
VALUES ('210678', '2240', '121');
INSERT INTO `salary`
VALUES ('302566', '2980.7', '210.2');
INSERT INTO `salary`
VALUES ('308759', '2531.98', '199.08');
INSERT INTO `salary`
VALUES ('504209', '2066.15', '108');

-- ----------------------------
-- Table structure for source
-- ----------------------------
DROP TABLE IF EXISTS `source`;
CREATE TABLE `source`
(
    `sour_id`   varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `sour_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `begin`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `period`    varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `credit`    varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of source
-- ----------------------------
INSERT INTO `source`
VALUES ('101', '计算机基础', '1', '50', '4');
INSERT INTO `source`
VALUES ('102', '程序设计语言', '1', '50', '4');
INSERT INTO `source`
VALUES ('103', '离散数学', '1', '50', '4');
INSERT INTO `source`
VALUES ('104', '高等数学', '2', '50', '4');
INSERT INTO `source`
VALUES ('105', '线性代数', '2', '50', '4');
INSERT INTO `source`
VALUES ('106', '计算机原理', '2', '50', '4');
INSERT INTO `source`
VALUES ('107', 'Web设计', '3', '50', '4');
INSERT INTO `source`
VALUES ('108', '数据库原理', '4', '50', '4');

-- ----------------------------
-- Table structure for stuinfo
-- ----------------------------
DROP TABLE IF EXISTS `stuinfo`;
CREATE TABLE `stuinfo`
(
    `stu_id`       varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `stu_name`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `pro_name`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `sex`          varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `born`         varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `total_credit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `coment`       varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of stuinfo
-- ----------------------------
INSERT INTO `stuinfo`
VALUES ('081101', '张三', '计算机', '男', '2000-01-01', '42', NULL);
INSERT INTO `stuinfo`
VALUES ('081102', '李四', '互联网技术', '男', '2000-01-02', '43', NULL);
INSERT INTO `stuinfo`
VALUES ('081103', '王五', '计算机', '女', '2000-01-03', '44', NULL);
INSERT INTO `stuinfo`
VALUES ('081104', '赵六', '软件工程', '男', '2000-01-04', '45', NULL);
INSERT INTO `stuinfo`
VALUES ('081105', '孙七', '计算机', '男', '2000-01-05', '46', NULL);
INSERT INTO `stuinfo`
VALUES ('081106', '杨八', '软件工程', '女', '2000-01-06', '47', NULL);
INSERT INTO `stuinfo`
VALUES ('081107', '陈九', '计算机', '男', '2000-01-07', '48', NULL);
INSERT INTO `stuinfo`
VALUES ('081108', '林氏', '计算机', '女', '2000-01-08', '49', NULL);
INSERT INTO `stuinfo`
VALUES ('081201', '程光', '电子工程', '男', '2000-01-09', '50', NULL);
INSERT INTO `stuinfo`
VALUES ('081202', '孙艳', '计算机科学', '男', '2000-01-10', '51', '国家级奖学金获得者');
INSERT INTO `stuinfo`
VALUES ('081203', '有机鱼', '电子工程', '女', '2000-01-11', '52', NULL);
INSERT INTO `stuinfo`
VALUES ('081204', '闫红', '网络工程', '男', '2000-01-12', '53', '免修');
INSERT INTO `stuinfo`
VALUES ('081205', '孙岩', '网络工程', '女', '2000-01-13', '54', NULL);
INSERT INTO `stuinfo`
VALUES ('081206', '李敏', '电子工程', '男', '2000-01-14', '55', '辅修');
INSERT INTO `stuinfo`
VALUES ('081207', '吴无', '网络安全', '女', '2000-01-15', '56', NULL);
INSERT INTO `stuinfo`
VALUES ('081208', '李洪庆', '电子工程', '男', '2000-01-16', '57', NULL);

-- ----------------------------
-- Table structure for stuscore
-- ----------------------------
DROP TABLE IF EXISTS `stuscore`;
CREATE TABLE `stuscore`
(
    `stu_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `sour_id` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `score`   varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of stuscore
-- ----------------------------
INSERT INTO `stuscore`
VALUES ('081101', '101', '70');
INSERT INTO `stuscore`
VALUES ('081102', '102', '71');
INSERT INTO `stuscore`
VALUES ('081103', '102', '72');
INSERT INTO `stuscore`
VALUES ('081104', '104', '73');
INSERT INTO `stuscore`
VALUES ('081105', '105', '74');
INSERT INTO `stuscore`
VALUES ('081106', '101', '75');
INSERT INTO `stuscore`
VALUES ('081107', '107', '76');
INSERT INTO `stuscore`
VALUES ('081108', '108', '77');
INSERT INTO `stuscore`
VALUES ('081201', '102', '78');
INSERT INTO `stuscore`
VALUES ('081202', '102', '79');
INSERT INTO `stuscore`
VALUES ('081203', '103', '80');
INSERT INTO `stuscore`
VALUES ('081204', '104', '81');
INSERT INTO `stuscore`
VALUES ('081205', '107', '82');
INSERT INTO `stuscore`
VALUES ('081206', '106', '83');
INSERT INTO `stuscore`
VALUES ('081207', '107', '84');
INSERT INTO `stuscore`
VALUES ('081208', '104', '85');

-- ----------------------------
-- Table structure for work
-- ----------------------------
DROP TABLE IF EXISTS `work`;
CREATE TABLE `work`
(
    `workid`   varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `workname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `comment`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of work
-- ----------------------------
INSERT INTO `work`
VALUES ('1', '财务部', 'null');
INSERT INTO `work`
VALUES ('2', '人力资源部', 'null');
INSERT INTO `work`
VALUES ('3', '经理办公室', 'null');
INSERT INTO `work`
VALUES ('4', '研发部', 'null');
INSERT INTO `work`
VALUES ('5', '市场部', 'null');

SET FOREIGN_KEY_CHECKS = 1;
