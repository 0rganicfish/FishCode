<p style="font-size: 40px; color: #fff"><b>Ajax</b></p><br>

- [README](README.md)

[TOC]

## 基础 —— XMLHttpRequest

- Ajax 可以实现网页局部地更新数据. 而起步是 JavaScript 的 XMLHttpRequest

### 创建

- 现代浏览器可直接 new 出来，要兼容则：
  ```JavaScript {.line-numbers}
  var xmlhttp
  if (window.XMLHttpRequest)
      //  IE7+, Firefox, Chrome, Opera, Safari 浏览器执行代码
      xmlhttp = new XMLHttpRequest()
  // IE6, IE5 浏览器执行代码
  else xmlhttp = new ActiveXObject("Microsoft.XMLHTTP")
  ```

### 发送请求

- `xmlhttp.open(method, url, async)` ： 规定请求的类型、URL 以及是否异步处理请求。
  - `method`：请求的类型；GET 或 POST
  - `url`：文件在服务器上的位置
  - `async`：默认 true（异步）或 false（同步）
- `xmlhttp.send(string)` ：将请求发送到服务器。
  - `string`：仅用于 POST 请求

-