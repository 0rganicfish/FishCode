<h1 align="center"><b>Express 框架</b></h1><br>

- **外链**
  - [README](../README.md)
  - [Node.js](Node.js.md)

[TOC]

<br>

## 路由

路由表示应用程序端点 (URI) 的定义以及端点响应客户机请求的方式

我们所使用的 app 与 `HTTP` 方法相对应的 `Express` 对象方法来定义路由，如 `app.get()` 用于处理 GET 请求

这些路由方法都指定了回调函数 ，当程序接收到指定的路由（端点）的时候（也就是说 `HTTP` 方法请求时被调用），来调用回调函数，换句话说就是应用程序监听与指定路由和方法匹配的请求，当检测到匹配时，他会调用对应的回调函数。

- **如：**
  ```ts {.line-numbers}
  import express from "express";
  export const app = express(); // 以下默认已经创建了 app
  app // 当浏览器发送了 GET /mie 请求(req)时
    .get("/mie", (req, res) => {
      res.send("data"); // 服务器就发送响应(res)数据
    })
    .listen("1023", () => {
      console.log("open on http://localhost:1023/mie");
    });
  ```
- **方法：**
  ```ts {.line-numbers}
  app.METHODS(path, callback);
  ```
  `path` 路径可以是 [正则匹配](https://www.npmjs.com/package/path-to-regexp)

### Request 属性 | Response 方法

- **Response:**
  - `res.send(data)`： 只发送一个 `https` 响应至请求端，只接收一个参数，这个参数可以是任何类型。因为执行这个方法的时候会自动设置响应头数据类型，即响应头里 `Content-Type` 字段。
  - `res.json(data)`：只发送 json 类型的数据
  - `res.status(num)`：设定 HTTP 状态码
  - `res.redirect([status,] path)`：重定向至...... 还能设置状态码(可选参数)
- **Request:**
  - `req.url`：返回请求的 URL
  - `req.query`：返回 URL ?后的参数，json 类型
  - `req.params`：返回 URL 中的自定义参数
  - `req.body`：返回 POST 请求的参数
  - `req.headers`：返回请求头数据，json 类型
