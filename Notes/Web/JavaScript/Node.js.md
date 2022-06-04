<h1 align="center"><b>Node.js</b></h1><br>

[TOC]

<br>

## Node 项目

### 初始化

- cd 到项目文件夹并运行 ↓ 后，按提示填写项目信息，就会生成 `package.json` 文件
  ```batch {.line-numbers}
  npm init
  ```
- `package.json` 文件包含的信息：
- <img src="../img/Node_package.png" width="70%">

- 其中最后的 `type` 字段是涉及到模块规范的支持，它有两个可选值： `commonjs` 和 `module` ，其默认值为 `commonjs` 。

  - 当不设置或者设置为 `commonjs` 时，扩展名为 `.js` 和 `.cjs` 的文件都是 `CommonJS` 规范的模块
  - 当不设置或者设置为 `module` 时，扩展名为 `.js` 和 `.mjs` 的文件都是 `ES Module` 规范的模块

  > 关于 `package.json` 的完整的选项可以在 [npm Docs](https://docs.npmjs.com/cli/v8/configuring-npm/package-json/)上查阅。
