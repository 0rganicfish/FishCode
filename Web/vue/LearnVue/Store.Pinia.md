<h1 align="center"><b>Store.Pinia</b></h1><br>

[TOC]

<style>
    
    </style>

<br>

## 关于

&emsp;&emsp;

Pinia 相比来说较为友好......

- **安装与启用**
  ```batch {.line-numbers}
  pnpm i pinia
  ```
  ```ts {.line-numbers}
  // main.ts
  import { createPinia } from "pinia";
  app.use(createPinia).
  ```
- **状态树的结构**
    <table><thead><tr><th >作用</th><th >Vue Component</th><th >Vuex</th><th >Pinia</th></tr></thead><tbody><tr><td >数据管理</td><td >data</td><td >state</td><td >state</td></tr><tr><td >数据计算</td><td >computed</td><td >getters</td><td >getters</td></tr><tr><td >行为方法</td><td >methods</td><td >mutations / actions</td><td >actions</td></tr></tbody></table>

## 创建 Store

必须为 `Store` 指定一个唯一的 `ID`，把导出的函数名命名为 `useXX` ，以 `use` 开头是 `Vue 3` 对可组合函数的一个命名规范

```ts {.line-numbers}
// src/stores/index.ts
import { defineStore } from "pinia";
export const useStore = defineStore("main", {
  //
});
// or:
export const useStore = defineStore({
  id: "main",
  //
});
```

## 管理 state

相当于是 `Vue3` 的 `data`，定义状态数据

### 添加 state

它是通过一个箭头函数的形式来返回数据，并且能够正确的帮你推导 `TypeScript` 类型：

```ts {.line-numbers}
// src/stores/index.ts
import { defineStore } from "pinia";

export const useStore = defineStore("main", {
  state: () => ({
    message: "Hello World", // 自动推导类型
    data: [] as string[], // 手动定义类型
  }),
  // ...
});
```

> `state` 的类型必须是 `state?: (() => {}) | undefined` ，要么不配置（就是 `undefined` ），要么只能是个箭头函数。

### 获取和更新 state
