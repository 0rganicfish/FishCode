<h1 align="center"><b>Node.js</b></h1><br>

[TOC]

<br>

## Node 项目

### 初始化

- cd 到项目文件夹并运行 ↓ 后，按提示填写项目信息，就会生成 `package.json` 文件
  ```batch {.line-numbers}
  npm init
  rem 选默认值则是
  npm init -y
  ```
- `package.json` 文件包含的信息：
- <img src="../img/Node_package.png" width="70%">

- 其中最后的 `type` 字段是涉及到模块规范的支持，它有两个可选值： `commonjs` 和 `module` ，其默认值为 `commonjs` 。

  - 当不设置或者设置为 `commonjs` 时，扩展名为 `.js` 和 `.cjs` 的文件都是 `CommonJS` 规范的模块
  - 当不设置或者设置为 `module` 时，扩展名为 `.js` 和 `.mjs` 的文件都是 `ES Module` 规范的模块

  > 关于 `package.json` 的完整的选项可以在 [npm Docs](https://docs.npmjs.com/cli/v8/configuring-npm/package-json/)上查阅。

### 模块

#### Common JS

- **导出：** CJS 使用 `module.exports = {}` 语法导出模块，可以导出任意合法的 `JavaScript` 类型，例如：字符串、布尔值、对象、数组、函数等等
- **导入：** 使用 `require` 导入模块，在导入的时候，当文件扩展名是 `.js` 时，可以只写文件名

#### ES Module

- **导出：** 在要导出的 js 类型前加 `export`
- **导入：** `import {} from './module'`，重命名：`{mie as miemie}`
