<h1 align="center"><b>Node.js</b></h1><br>

[TOC]

<br>

## Node 项目

### 初始化

- cd 到项目文件夹并运行 ↓ 后，按提示填写项目信息，就会生成 `package.json` 文件
  ```batch {.line-numbers}
  pnpm init
  rem 选默认值则是
  pnpm init -y
  ```
- `package.json` 文件包含的信息：
- <img src="../img/Node_package.png" width="80%">

- 其中最后的 `type` 字段是涉及到模块规范的支持，它有两个可选值： `commonjs` 和 `module` ，其默认值为 `commonjs` 。
  > 关于 `package.json` 的完整的选项可以在 [npm Docs](https://docs.npmjs.com/cli/v8/configuring-npm/package-json/)上查阅。

### With Typescript

- **构建 ts 项目：**
  ```batch {.line-numbers}
  tsc --init
  ```
- **配置 `tsconfig.json`：**
  ```json {.line-numbers}
  {
    "compilerOptions": {
      "target": "es6",
      "module": "es6",
      "esModuleInterop": true,
      "forceConsistentCasingInFileNames": true,
      "strict": true,
      "skipLibCheck": true,
      "noImplicitAny": false, //含有any时报错
      "rootDir": "./src",
      "outDir": "./build", // 编译后的输出目录
      "watch": true, // 监听文件更改
      "types": [
        "node" // 导入内置模块
      ],
      "typeRoots": ["./node_modules/@types"]
    },
    "include": [
      "./src/**/*" // 要编译的目录
    ],
    "exclude": ["static", "node_modules"],
    "compileOnSave": true
  }
  ```
- **配置 `package.json`：**
  ```json {.line-numbers}
  {
    "type": "modules",
    "scripts": {
      "dev": "tsc --watch", // pnpm dev
      "build": "node build/" // npm run build
    },
    "dependencies": {
      // pnpm i --save @types/node
      "@types/node": "^18.0.0" // 导入 node 内置模块
    }
  }
  ```

## 模块

### Common JS | ES Modules

- **`CommonJS`：**
  - **导出：** CJS 使用 `module.exports = {}` 语法导出模块，可以导出任意合法的 `JavaScript` 类型，例如：字符串、布尔值、对象、数组、函数等等
  - **导入：** 使用 `require` 导入模块，在导入的时候，当文件扩展名是 `.js` 时，可以只写文件名
- **`ESModules`：**
  - **导出：** 在要导出的 js 类型前加 `export`
  - **导入：** `import {} from './module'`，重命名：`{mie as miemie}`

### node 模块

#### fs



### 第三方模块
