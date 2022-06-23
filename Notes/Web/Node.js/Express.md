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

### app 对象 属性和方法

- `app.route(path)`：即对同一个路径不同 HTTP 方法时：
  ```ts {.line-numbers}
  // 这样就不用在每个方法前都加路由地址了
  app.route("user/").get(fn).post(fn);
  ```
- `app.use([path,] fn)`：

### Request 属性 | Response 方法

- **Response:**
  - `res.end([data] [，encoding])`：用于快速结束没有数据的响应，而 data 只能是 `string | Buffer` 类型
  - `res.send(data)`： 只发送一个 `https` 响应至请求端，只接收一个参数，这个参数可以是任何类型。因为执行这个方法的时候会自动设置响应头数据类型，即响应头里 `Content-Type` 字段。
  - `res.json(data)`：只发送 json 类型的数据
  - `res.status(num)`：设定 HTTP 状态码
  - `res.redirect([status,] path)`：重定向至...... 还能设置状态码(可选参数)
  - `res.download(path, [filename, fn(err)])`：下载文件请求，`filename` 为下载文件的别名
  - `res.render(viewPath, [locals, fn(err, html)])`：渲染一个视图，并把一个 `HTML` 字符串发送给客户端，`locals` 是一个对象，其属性定义了视图内的局部变量。`fn` 是一个回调函数，如果提供了，这个方法返回可能的错误信息和渲染字符串。如果有错误，这个方法会使用一个 `next(err)` 的内部函数。
  - `res.cookie(name, value, [options])`：设置 **Cookie**。`options` 的属性：
    - `domain` ： `cookie` 在什么域名下有效，类型为 `String` 。默认为网站域名
    - `expires` ： `cookie` 过期时间，类型为 `Date` 。如果没有设置或者设置为 0 ，那么该 `cookie` 只在这个这个 `session` 有效，即关闭浏览器后，这个 `cookie` 会被浏览器删除
    - `httpOnly` ： 只能被 `web server` 访问，类型 `Boolean`
    - `maxAge` ： 实现 `expires` 的功能，设置 `cookie` 过期的时间，类型为 `String` ，指明从现在开始，多少毫秒以后， `cookie` 到期
    - `path` ： `cookie` 在什么路径下有效，默认为'/'，类型为 `String`
    - `secure` ：只能被 `HTTPS` 使用，类型 `Boolean` ，默认为 `false`
    - `signed` ：使用签名，类型 `Boolean` ，默认为 `false` 。 `express` 会使用 `req.secret` 来完成签名，需要 `cookie-parser` 配合使用
  - `res.clearCookie(name, [options])`：删 Cookie

<br>

- **Request ：**
  - `req.url`：返回请求的 URL
  - `req.query`：返回 URL ?后的参数，json 类型
  - `req.params`：返回 URL 中的自定义参数，json 类型。如：
    ```ts {.line-numbers}
    app.get("/home/:uid/:pages");
    // URL: "/home/2333/fish"
    // 返回：{ uid: 2333, pages: "fish" }
    ```
  - `req.body`：返回 POST 请求的参数
  - `req.headers`：返回请求头数据，json 类型
  - `req.baseUrl`：返回路由当前的根路径
  - `req.originalUrl`：返回原始请求 URL
  - `req.path`：返回请求路径

<br>

### 中间件

- **内置中间件：**
  - `express.json()` 解析 `Content-Type` 为 `application/json` 格式的请求体
  - `express.urlencoded()` 解析 `Content-Type` 为 `application/x-www-form-urlencoded` 格式的请求体
  - `express.raw()` 解析 `Content-Type` 为 `application/octet-stream` 格式的请求体
  - `express.text()` 解析 `Content-Type` 为 `text/plain` 格式的请求体
  - `express.static()` 托管静态资源文件
- **Cors:**
  - 3

<br>

## 参考

> Ref: [res.cookie 的使用](https://segmentfault.com/a/1190000004139342)
