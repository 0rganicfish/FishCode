  <h1 align="center"><b>Ajax</b></h1><br>

- [README](README.md)

[TOC]

&emsp;&emsp;

<br>

# 原理

&emsp;&emsp; 客户端与服务器，可以在「不必刷新整个浏览器」的情况下，与服务器进行异步通讯的技术

&emsp;&emsp; 传统的 web 前端与后端的交互中，浏览器直接访问 Tomcat 的 Servlet 来获取数据。Servlet 通过转发把数据发送给浏览器。

&emsp;&emsp; 当我们使用 AJAX 之后，浏览器是先把请求发送到 `XMLHttpRequest` 异步对象之中，异步对象对请求进行封装，然后再与发送给服务器。服务器并不是以转发的方式响应，而是以流的方式把数据返回给浏览器

&emsp;&emsp; `XMLHttpRequest` 异步对象会不停监听服务器状态的变化，得到服务器返回的数据，就写到浏览器上【因为不是转发的方式，所以是无刷新就能够获取服务器端的数据】

&emsp;&emsp;

# 基础 —— XMLHttpRequest

Ajax 可以实现网页局部地更新数据. 而起步是 JavaScript 的 `XMLHttpRequest`

## 创建

- 现代浏览器可直接 new 出来，要兼容则：
  ```JavaScript {.line-numbers}
  function getXHR() {
    var xhr = null;
    if (window.XMLHttpRequest) {
      xhr = new XMLHttpRequest();
    } else if (window.ActiveXObject) {
      try {
        xhr = new ActiveXObject("Msxml2.XMLHTTP");
      } catch (e) {
        try {
          xhr = new ActiveXObject("Microsoft.XMLHTTP");
        } catch (e) {
          alert("您的浏览器暂不支持Ajax!");
        }
      }
    }
    return xhr;
  }
  ```

## 发送请求

- `xmlhttp.open(method, url, async)` ： 规定请求的类型、URL 以及是否异步处理请求。
  - `method`：请求的类型；GET 或 POST
  - `url`：文件在服务器上的位置
  - `async`：默认 true（异步）或 false（同步）
- `xmlhttp.send(string)` ：将请求发送到服务器。
  - `string`：仅用于 POST 请求

## 获取 response 数据

xhr 提供了 3 个属性来获取请求返回的数据，分别是：`xhr.response`、`xhr.responseText`、`xhr.responseXML`

### xhr.response

- **默认值**：空字符串 `""`
- 当请求**完成**时，此属性才有正确的值
- 请求**未完成**时，此属性的值可能是 `""` 或者 null，具体与 `xhr.responseType`有关：当 responseType 为 `""` 或"text"时，值为 `""` ；responseType 为其他值时，值为 null

### xhr.responseText

- **默认值**：空字符串 `""`
- 只有当 `responseType` 为"text"、 `""` 时，xhr 对象上才有此属性，此时才能调用`xhr.responseText`，否则抛错
- 只有当请求成功时，才能拿到正确值。以下 2 种情况下值都为空字符串 `""` ：请求未完成、请求失败

### xhr.responseXML

- **默认值**： null
- 只有当 `responseType` 为"text"、""、"document"时，xhr 对象上才有此属性，此时才能调用`xhr.responseXML`，否则抛错
- 只有当请求成功且返回数据被正确解析时，才能拿到正确值。以下 3 种情况下值都为 null：请求未完成、请求失败、请求成功但返回数据无法被正确解析时

## 发送过程的状态

- <img src="img/Ajax_onreadystate.png" width="80%">

## 设置请求的超时时间

如果请求过了很久还没有成功，为了不会白白占用的网络资源，我们一般会主动终止请求。XMLHttpRequest 提供了 timeout 属性来允许设置请求的超时时间。

- `xhr.timeout`
  - 单位： `milliseconds` 毫秒
  - 默认值： `0`，即不设置超时

从 **请求开始** 算起，若超过 `timeout` 时间请求还没有结束（包括成功/失败），则会触发`ontimeout`事件，主动结束该请求。

- **请求开始:**
  - xhr.onloadstart 事件触发的时候，也就是调用 xhr.send()方法的时候
    > 因为 xhr.open()只是创建了一个连接，但并没有真正开始数据的传输，而 xhr.send()才是真正开始了数据的传输过程。只有调用了 xhr.send()，才会触发 xhr.onloadstart 。
- **请求结束：**
  - xhr.loadend 事件触发的时候。

> **另外：** 可以在 send()之后再设置此 xhr.timeout，但计时起始点仍为调用 xhr.send()方法的时刻。

<br>

## 事件

### 事件触发条件

- <img src="img/Ajax_onxxx.png">

### 事件触发顺序

- 当请求一切正常时，相关的事件触发顺序如下：
  1.  触发 `xhr.onreadystatechange`(之后每次 readyState 变化时，都会触发一次)
  2.  触发 `xhr.onloadstart`
      //上传阶段开始：
  3.  触发 `xhr.upload.onloadstart`
  4.  触发` xhr.upload.onprogress`
  5.  触发 `xhr.upload.onload`
  6.  触发 `xhr.upload.onloadend`
      //上传结束，下载阶段开始：
  7.  触发 `xhr.onprogress`
  8.  触发 `xhr.onload`
  9.  触发 `xhr.onloadend`

### 异常处理

在请求的过程中，有可能发生 abort | timeout | error 这 3 种异常。那么一旦发生这些异常，xhr 后续会进行哪些处理呢？后续处理如下：

1.  一旦发生 `abort` 或 `timeout` 或 `error` 异常，先立即中止当前请求
2.  将 `readystate` 置为 4，并触发 `xhr.onreadystatechange` 事件
3.  如果上传阶段还没有结束，则依次触发以下事件：
    1.  `xhr.upload.onprogress`
    2.  ` xhr.upload.[onabort 或 ontimeout 或 onerror]`
    3.  `xhr.upload.onloadend`
4.  触发` xhr.onprogress` 事件
5.  触发 `xhr.[onabort 或 ontimeout 或 onerror]` 事件
6.  触发 `xhr.onloadend` 事件

### 在哪个 xhr 事件中注册成功回调？

- 从上面介绍的事件中，可以知道若 xhr 请求成功，就会触发 `xhr.onreadystatechange` 和` xhr.onload` 两个事件。且 `xhr.onreadystatechange` 是每次 `xhr.readyState` 变化时都会触发，而不是` xhr.readyState = 4` 时才触发。
  ```JavaScript {.line-numbers}
  xhr.onload = function () {
    //如果请求成功
    if(xhr.status == 200){
      //do successCallback
    }
  }
  ```
- 上面的示例代码是很常见的写法：先判断 http 状态码是否是 200，如果是，则认为请求是成功的，接着执行成功回调。
- 这样的判断是有坑儿的，比如当返回的 http 状态码不是 200，而是 201 时，请求虽然也是成功的，但并没有执行成功回调逻辑。所以更靠谱的判断方法应该是：当 http 状态码为 **2xx** 或 **304** 时才认为成功。
  ```JavaScript {.line-numbers}
  xhr.onload = function () {
    //如果请求成功
    if((xhr.status >= 200 && xhr.status < 300) || xhr.status == 304){
      //do successCallback
    }
  }
  ```

&emsp;&emsp;

<br>

# Ajax | Axios 模块

## 栗子

- **创建：**
  ```js {.line-numbers}
  const ajax = axios.create({
    baseURL: "xx/api",
    timeout: 2333,
  });
  ajax
    .get("user/", { config })
    .then((res) => {
      //xxx
    })
    .catch((err) => {
      console.log(err);
    });
  ```
- **微博热搜：**
  ```js {.line-numbers}
  const url = "https://weibo.com/ajax/side/hotSearch";
  axios.get(url).then((res) => {
    const data = res.data.data.realtime,
      ans = [];
    data.forEach((element) => {
      ans.push(element.word);
    });
    console.log(ans);
  });
  ```

## API

### 请求

- `baseURL: "https://domain.com/api/"`： `baseURL` 将自动加在 `url` 前面，表示请求的主 URL
- `url: "/user"`： `url` 是用于请求的服务器 URL | 相对 URL
- `method: "get"`： 默认为 get
- `transformRequest` 允许在向服务器发送前，修改请求数据
  它只能用于 `PUT`, `POST` 和 `PATCH` 这几个请求方法
  数组中最后一个函数必须返回一个字符串， 一个 `Buffer` 实例，`ArrayBuffer`，`FormData`，或 `Stream`
  ```js {.line-numbers}
  transformRequest: [
    function (data, headers) {
    // 对发送的 data 进行任意转换处理
    return data;
    },
  ],
  ```
- `transformResponse`： 在传递给 then/catch 前，允许修改响应数据
  ```js {.line-numbers}
  transformResponse: [
    function (data) {
    // 对接收的 data 进行任意转换处理
    return data;
    },
  ],
  ```
- `headers: { "X-Requested-With": "XMLHttpRequest" }`： 自定义请求头
- `params` 是与请求一起发送的 `URL` 参数，必须是一个简单对象或 `URLSearchParams` 对象
  ```js {.line-numbers}
  params: {
    ID: 12345,
    name: "fish",
  },
  ```
- `data`：作为请求体被发送的数据。仅适用 'PUT'， 'POST'， 'DELETE 和 'PATCH' 请求方法，在没有设置 `transformRequest` 时，则必须是以下类型之一:
  - `string`， `plain object`， `ArrayBuffer`， `ArrayBufferView`， `URLSearchParams`
  - 浏览器专属: `FormData`， `File`， `Blob`
  - `Node` 专属: `Stream`， `Buffer`
- `timeout`： 指定请求超时的毫秒数。如果请求时间超过 `timeout` 的值，则请求会被中断。默认值是 `0` (永不超时)
- `withCredentials`：表示跨域请求时是否需要使用凭证，默认为 `false`
- `responseType`：表示浏览器将要响应的数据类型。选项包括： `arraybuffer`， `document`， `json`， `text`， `stream` | 浏览器专属：`blob`
- `responseEncoding` 表示用于解码响应的编码 (Node.js 专属) 注意：忽略 `responseType` 的值为 `stream`，或者是客户端请求。默认为 `utf-8`
- `onUploadProgress(progress)` 允许为上传处理进度事件
- `onDownloadProgress(progress)` 允许为下载处理进度事件
- `proxy` 定义了代理服务器的主机名，端口和协议。
  您可以使用常规的`http_proxy` 和 `https_proxy` 环境变量。
  - 使用 `false` 可以禁用代理功能，同时环境变量也会被忽略。
    `auth`表示应使用 HTTP Basic auth 连接到代理，并且提供凭据。
  - 这将设置一个 `Proxy-Authorization` 请求头，它会覆盖 `headers` 中已存在的自定义 `Proxy-Authorization` 请求头。
    如果代理服务器使用 HTTPS，则必须设置 protocol 为`https`
  ```js {.line-numbers}
  proxy: {
    protocol: "https",
    host: "127.0.0.1",
    port: 9000,
    auth: {
      username: "fish",
      password: "mie",
    },
  },
  ```

### 响应

请求成功后使用 `.then(res => {})` 得到的响应体如下

- `data` ：由服务器提供的响应
- `status` ：来自服务器响应的 `HTTP` 状态码
- `statusText` ：来自服务器响应的 `HTTP` 状态信息
- `headers` ：服务器响应头。所有的 `header` 名称都是小写，而且可以使用方括号语法访问。例如: `response.headers['content-type']`
- `config` ： `axios` 请求的配置信息
- `request` ：生成此响应的请求
  - 在 `node.js` 中它是最后一个 `ClientRequest` 实例 `(in redirects)`，
  - 在浏览器中则是 `XMLHttpRequest` 实例 `request: {}`

### 拦截器

- 拦截器分两种：请求拦截器、响应拦截器。
  - 请求拦截器：在请求发送前进行必要操作处理，例如添加统一 cookie、请求体加验证、设置请求头等，相当于是对每个接口里相同操作的一个封装；
  - 响应拦截器：同理，响应拦截器也是如此功能，只是在请求得到响应之后，对响应体的一些处理，通常是数据统一处理等，也常来判断登录失效等。
- 应用场景：
  - 每个请求都带上的参数，比如 token，时间戳等。
  - 对返回的状态进行判断，比如 token 是否过期
- **请求拦截：**
  ```js {.line-numbers}
  const ajax = axios.create({ xxx });
  ajax.interceptors.request.use(
    (req) => {
      // 在发送请求前要做的事儿
      return req;
    },
    (err) => {
      // 在请求错误时要做的事儿
      // 该返回的数据则是axios.catch(err)中接收的数据
      return Promise.reject(err);
    }
  );
  ```

<br><hr>

# 参考

- [万字 Ajax\_掘金](https://juejin.cn/post/6844903469896171533)
- [你真的会 Ajax 吗？](https://segmentfault.com/a/1190000004322487)
- [入门 Ajax](https://segmentfault.com/a/1190000013286987)
- [Axios 文档](https://www.axios-http.cn/docs/intro)
