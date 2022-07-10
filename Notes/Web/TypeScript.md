<h1 align="center"><b>TypeScript</b></h1><br>

[TOC]

- [Node.js](Node.js/Node.js.md)
- [README](README.md)

<br>

# 语法

- **数据类型**
  - **enum** ：枚举类型对象，配合着 `switch` 使用
    ```ts {.line-numbers}
    enum httpStatus {
      success = 200,
      nodata = 404,
    }
    console.log(httpStatus.nodata); // 404
    // 编译成 js 就是：两个方向的对象
    var httpStatus = {
      '200': 'success',
      '404': 'nodata',
      success: 200,
      nodata: 404,
    };
    ```
    当没有定义`value`时，默认从 0 开始递增下标
  - \*\*

<br>

# 项目构建

## 初始化

- **构建 ts 项目：**
  ```batch {.line-numbers}
  tsc --init
  ```
- **配置 `tsconfig.json`：**
  ```json {.line-numbers}
  {
    "compilerOptions": {
      "target": "esnext",
      "module": "esnext",
      "moduleResolution": "node",
      "strict": true,
      "resolveJsonModule": true,
      "forceConsistentCasingInFileNames": true,
      "esModuleInterop": true,
      "noImplicitAny": true,
      "watch": true,
      "baseUrl": "./",
      "outDir": "build",
      "types": ["node"]
    },
    "include": ["src/**/*"],
    "exclude": ["node_modules", "static"]
  }
  ```
- **配置 `package.json`：**
  ```json {.line-numbers}
  {
    "type": "modules",
    "scripts": {
      "dev": "tsc", // pnpm dev
      "build": "nodemon --exec \"node --experimental-specifier-resolution=node ./build/main\"" // npm run build
    },
    "devDependencies": {
      // pnpm i --save-dev @types/node
      "@types/node": "^18.0.0", // 导入 node 内置模块
      "nodemon": "^2.0.16" // 监听文件更改
    }
  }
  ```

## 代码规范

- **安装：**
  ```batch {.line-numbers}
  pnpm i -D eslint typescript @typescript-eslint/parser @typescript-eslint/eslint-plugin prettier eslint-config-prettier
  ```
- **初始化：** 然后按照提示下去就好
  ```batch {.line-numbers}
  eslint --init
  ```

<br>

# 参考

- [TypeScript 中文手册][1]
- [Eslint 中文文档][2]
- [tsconfig 的配置][3]

[1]: http://www.patrickzhong.com/TypeScript/
[2]: http://eslint.cn/docs/user-guide/configuring
[3]: https://yesifang.com/zh/TypeScript%E7%B3%BB%E5%88%97%E6%95%99%E7%A8%8B/c2fff071/
