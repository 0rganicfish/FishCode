<p style="font-size: 40px; color: #fff; text-align:center"><b>HTTP</b></p><br>

- [README](../../README.md)

[TOC]

##

### 请求头

这里设置的主要是一些信息，包含客户端，服务器。

- `User-Agent`：浏览器的具体类型,如：`User-Agent：Mozilla/5.0 (Windows NT 6.1; rv:17.0) Gecko/20100101 Firefox/17.0`
- `Accept`：浏览器支持哪些数据类型,如：`Accept: text/html,application/xhtml+xml,application/xml;q=0.9;`
- `Accept-Charset`：浏览器采用的是哪种编码,如：`Accept-Charset: ISO-8859-1`
- `Accept-Encoding`：浏览器支持解码的数据压缩格式,如：`Accept-Encoding: gzip, deflate`
- `Accept-Language`：浏览器的语言环境,如：`Accept-Language zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3`
- `Host`：请求的主机名，允许多个域名同处一个 IP 地址，即虚拟主机。
- `Connection`：表示是否需要持久连接。`Keep-Alive/close`，HTTP1.1 默认是持久连接，它可以利用持久连接的优点，当页面包含多个元素时（例如 Applet，图片），显著地减少下载所需要的时间。
  要实现这一点，Servlet 需要在应答中发送一个 `Content-Length` 头，最简单的实现方法是：先把内容写入 `ByteArrayOutputStream`，然后在正式写出内容之前计算它的大小。如：`Connection: Keep-Alive`
- `Content-Length`：表示请求消息正文的长度。对于 `POST` 请求来说 `Content-Length` 必须出现。
- `Content-Type`：WEB 服务器告诉浏览器自己响应的对象的类型和字符集。例如：`Content-Type: text/html; charset='gb2312'`
- `Content-Encoding`：WEB 服务器表明自己使用了什么压缩方法（gzip，deflate）压缩响应中的对象。例如：`Content-Encoding：gzip`
- `Content-Language`：WEB 服务器告诉浏览器自己响应的对象的语言。
- `Cookie`：最常用的请求头，浏览器每次都会将 cookie 发送到服务器上，允许服务器在客户端存储少量数据。
- `Referer`：包含一个 URL，用户从该 URL 代表的页面出发访问当前请求的页面。服务器能知道你是从哪个页面过来的。`Referer: http://www.baidu.com/`

### 请求体

这里是提交给服务器的数据

需要注意的是,如果是往服务器提交数据,需要在请求头中设置 `Content-Type:application/x-www-form-urlencoded`

## 响应报文

响应报文是服务器发回给客户端的。组成部分有状态行，响应头，响应主体。

### 状态行

由协议版本号、状态码和状态信息构成

常见的状态码：

- 1XX：信息状态码
  - `100 Continue` 继续，一般在发送 post 请求时，已发送了 `http header` 之后服务端将返回此信息，表示确认，之后发送具体参数信息
- 2XX：成功状态码
  - `200 OK` 正常返回信息
  - `201 Created` 请求成功并且服务器创建了新的资源
  - `202 Accepted` 服务器已接受请求，但尚未处理
- 3XX：重定向
  - `301 Moved Permanently` 请求的网页已永久移动到新位置。
  - `302 Found` 临时性重定向。
  - `303 See Other` 临时性重定向，且总是使用 GET 请求新的 URI。
  - `304 Not Modified` 自从上次请求后，请求的网页未修改过。
- 4XX：客户端错误
  - `400 Bad Request` 服务器无法理解请求的格式，客户端不应当尝试再次使用相同的内容发起请求。
  - `401 Unauthorized` 请求未授权。
  - `403 Forbidden` 禁止访问。
  - `404 Not Found` 找不到如何与 URI 相匹配的资源。
- 5XX: 服务器错误
  - `500 Internal Server Error` 最常见的服务器端错误。
  - `503 Service Unavailable` 服务器端暂时无法处理请求（可能是过载或维护）。

### 响应头

- `Date`：响应时间
- `Server`：服务器信息
- `Last-Modified`：资源最后修改时间 由服务器自动生成
- `ETag`：资源修改后生成的唯一标识，由服务器自动生成
- `Content-Length`：响应主体长度
- `Content-Type`：响应资源的类型

### 响应主体

即服务端返回给客户端的内容 
