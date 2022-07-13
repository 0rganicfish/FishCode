  <h1 align="center"><b>DOM</b></h1>

- **外链**
  - [README](../README.md)
  - [JavaScript](JavaScript.md)
  - [Events](Evens.md)

[TOC]

<br>

# DOM 树

## 概述

&emsp;&emsp; HTML 文档的主干是标签（tag）。根据文档对象模型（DOM），每个 HTML 标签都是一个对象。嵌套的标签是闭合标签的“子标签（children）”。标签内的文本也是一个对象。
&emsp;&emsp; 所有这些对象都可以通过 JS 来访问，我们可以使用它们来修改页面。例如，`document.body` 是表示 `<body>` 标签的对象。

- **节点：**

  - 每个树的节点都是一个对象。
    &emsp;&emsp; 标签被称为 元素节点（或者仅仅是元素），并形成了树状结构：`<html>` 在根节点，`<head>` 和 `<body>` 是其子项，等。
    &emsp;&emsp; 元素内的文本形成 文本节点，被标记为 `＃text`。一个文本节点只包含一个字符串。它没有子项，并且总是树的叶子。

- 请注意文本节点中的**特殊字符：**
  - 换行符：`↵`（在 JS 中为 `\n`）
  - 空格：`␣`

&emsp;&emsp; 空格和换行符都是完全有效的字符，就像字母和数字。它们形成**文本节点**并成为 DOM 的一部分

## DOM 的自动修正

&emsp;&emsp;如果浏览器遇到格式不正确的 HTML，它会在形成 DOM 时自动更正它。
&emsp;&emsp; 例如，顶级标签总是 `<html>`。即使它不存在于文档中 — 它也会出现在 DOM 中，因为浏览器会创建它。对于 `<body>` 也是一样。
&emsp;&emsp; 例如，如果一个 HTML 文件中只有一个单词 “Hello”，浏览器则会把它包装到 `<html>` 和 `<body>` 中，并且会添加所需的 `<head>`

## 访问 DOM

&emsp;&emsp; 给定一个 DOM 节点，我们可以使用导航（navigation）属性访问其直接的邻居，并返回实时更新的 **集合 (Set)**

- 这些属性主要分为两组：
  - 对于所有节点：
    `parentNode`，`childNodes`，`firstChild`，`lastChild`，`previousSibling`，`nextSibling`。
  - 仅对于元素节点：
    `parentElement`，`children`，`firstElementChild`，`lastElementChild`，`previousElementSibling`，`nextElementSibling`。

&emsp;&emsp; 某些类型的 DOM 元素，例如 table，提供了用于访问其内容的其他属性和集合。
&emsp;&emsp; 且由于空格与换行也算作节点，因此用 `*Nodes` 访问是包括了这些**文本节点**的

## 主要的 DOM 节点属性

- `nodeType`
  我们可以使用它来查看节点是文本节点还是元素节点。它具有一个数值型值：1 表示元素，3 表示文本节点，其他一些则代表其他节点类型。只读。
- `nodeName/tagName`
  用于元素名，标签名（除了 XML 模式，都要大写）。对于非元素节点，nodeName 描述了它是什么。只读。
- `innerHTML`
  元素的 HTML 内容。可以被修改。
- `outerHTML`
  元素的完整 HTML。对 `elem.outerHTML` 的写入操作不会触及 elem 本身。而是在外部上下文中将其替换为新的 HTML。
- `nodeValue/data`
  非元素节点（文本、注释）的内容。两者几乎一样，我们通常使用 data。可以被修改。
- `textContent`
  元素内的文本：HTML 减去所有 `<tags>`。写入文本会将文本放入元素内，所有特殊字符和标签均被视为文本。可以安全地插入用户生成的文本，并防止不必要的 HTML 插入。
- `hidden`
  当被设置为 true 时，执行与 CSS `display:none` 相同的事。

&emsp;&emsp; DOM 节点还具有其他属性，具体有哪些属性则取决于它们的类。例如，`<input>` 元素 支持 value，type，而 `<a>` 元素 则支持 href 等。大多数标准 HTML 特性（attribute）都具有相应的 DOM 属性。

## NodeList 与 HTMLCollection

`HTMLCollection` 是一个实时更新的节点对象，由 `getElementsByClassName()` | `node.children` 获得

`NodeList` 是一个 DOM 节点快照的集合，仅检测 `innerHTML` 的更新，由 `querySelectorAll()` | `node.childNodes` 获得

- 但只有 `NodeList` 才能被 `forEach()` 和 `for(.. of ..)` 遍历。但可以转为数组：`const arr = [...HTMLCol]`

<br><br>

# DOM 对象

## Document

以 `document.*` 为形式的对象和方法

### 方法

#### 节点查询型

- `document.getElementById()`：根据元素 id 返回元素，返回值是 Element 类型，如果不存在该元素，则返回 null.
- `document.getElementsBy\*()`：

  - `document.getElementsByClassName()`： 根据元素的 class 返回一个即时的 `HTMLCollection`
  - `document.getElementsByName()` 通过 name 属性来获取元素，返回一个即时的 `NodeList` 对象

  > 但这些 `getElementsBy*` 已经成了历史的眼泪......因为还不如用 **选择器** 查找。但同时，也就这些是实时更新的

- `document.querySelector()`
  &emsp;&emsp; 通过 css 选择器来查找，使用 **深度优先搜索** 返回第一个匹配的元素，如果没有匹配的元素，则返回 null。且相当于是 `document.querySelectorAll()[0]` 但速度更快
  **即**：若有相同的选择器，优先返回嵌套最深的那一个
  **但是**：`querySelector` 是 **静态** 的，不随文档而变化，且没有 `length`

#### 页面修改型

- **插入节点** 元素插入方法，指明了不同的插入位置：

  - `node.append(...nodes or strings)` —— 在 node 末尾 插入节点或字符串，
  - `node.prepend(...nodes or strings)` —— 在 node 开头 插入节点或字符串，
  - `node.before(...nodes or strings)` —— 在 node 前面 插入节点或字符串，
  - `node.after(...nodes or strings)` —— 在 node 后面 插入节点或字符串，
  - `node.replaceWith(...nodes or strings)` —— 将 node 替换为给定的节点或字符串。

  **注意**：

  1. 如果被添加的节点是一个页面中存在的节点，则执行后这个节点将会添加到指定位置，其原本所在的位置将移除该节点。也就是说不会同时存在两个该节点在页面上，相当于把这个节点移动到另一个地方。
  2. 如果 child 绑定了事件，被移动时，它依然绑定着该事件。

- **替换**：`node.replaceWith(...nodes or strings)` — 替换 node。

&emsp;&emsp;

- 子节点修改 **\*Old School**
  - `parent.appendChild(child);` 将指定的节点添加到调用该方法的节点的子元素的末尾。
    child 节点将会作为 parent 节点的最后一个子节点。
  - ` parentNode.insertBefore(newNode, refNode)` 用来添加一个节点到一个参照节点之前
    - `parentNode` 表示新节点被添加后的父节点
    - `newNode` 表示要添加的节点
    - `refNode` 表示参照节点，新节点会添加到这个节点之前
  - `parent.removeChild(node)` 删除指定的子节点并返回
  - `deletedChild` 指向被删除节点的引用，它等于 node，被删除的节点仍然存在于内存中，可以对其进行下一步操作。
  - `parent.replaceChild(newChild, oldChild)` 用于使用一个节点替换另一个节点
    - `newChild` 是替换的节点，可以是新的节点，也可以是页面上的节点，如果是页面上的节点，则其将被转移到新的位置
    - `oldChild` 是被替换的节点

> 由于历史原因，还存在“老式”的 DOM 操作方法。这些方法来自真正的远古时代。如今，没有理由再使用它们了

#### 节点创造型

- `document.createElement(tagName)`：通过传入指定的一个**标签名**来创建一个元素，如果传入的标签名是一个未知的，则会创建一个自定义的标签
- `document.createTextNode(value)`：用来创建一个文本节点，接收一个参数，这个参数就是文本节点中的
- `let newNode = oldNode.cloneNode(deep)`：返回调用该方法的节点的一个副本

  - `node` 将要被克隆的节点
  - `dupNode` 克隆生成的副本节点
  - `deep`（可选）是否采用深度克隆,如果为 true,则该节点的所有后代节点也都会被克隆,如果为 false,则只克隆该节点本身.

  **注意**:

  1. 和 `createElement` 一样，`cloneNode` 创建的节点只是游离有 HTML 文档外的节点，要调用 `appendChild` 方法才能添加到文档树中
  2. 如果复制的元素有 id，则其副本同样会包含该 id，由于 **id 具有唯一性**，所以在复制节点后必须要修改其 id
  3. 调用接收的 deep 参数最好传入，如果不传入该参数，不同浏览器对其默认值的处理可能不同
  4. 如果被复制的节点绑定了事件，则副本也会跟着绑定该事件吗？这里要分情况讨论：
     1. 如果是通过 `addEventListener` 或者比如 `onclick` 进行绑定事件，则副本节点不会绑定该事件
     2. 如果是内联方式绑定比如：`<div onclick="showParent()"></div>`，这样的话，副本节点同样会触发事件。

### 属性

- `document.cookie`：返回与当前文档有关的所有 cookie
- `document.URL`：返回当前文档在服务器的绝对路径
- `document.domain`：返回当前文档的域名
- `document.forms`、`document.images`、`document.links`、`document.scripts`、`document.title`：返回这些的集合
- `document.referrer`：返回跳转到当前文档的链接

### 参考

1. [JavaScript 操作 DOM 常用的 API](https://juejin.cn/post/6844903604445249543#heading-2)
2. [现代 JS 教程\_DOM 查询](https://zh.javascript.info/searching-elements-dom)
3. [querySelector(All) 相比 getElement(s)By 在生产环境中有哪些优势？ 知乎](https://www.zhihu.com/question/404365645/answer/1314691976)

<br><hr>

## Element

元素一定是节点，但节点不一定是元素 => 节点还分文本节点、注释节点等等

### 方法

### 属性

- `ele.attributes`：返回包含元素属性(id, class, data, name ...)的属性数组，可直接用 `attr.id`访问
- `ele.childNodes`：返回元素的子节点数组(NodeList)
- `ele.children`：返回元素的子元素的集合(HTMLCollection)
- `ele.parentElement`：返回元素的父元素
- `ele.classList`：返回元素的类名数组
- `ele.className`：返回元素的类名(string)
- `ele.firstChild` | `ele.firstElementChild`：返回元素的第一个子节点 | 元素
- `ele.nodeName`：返回元素的大写标签名
- `ele.nextElementSibling` | `ele.previousElementSibling`：返回元素的兄弟元素
- `ele.title`：设置或返回元素的 title 属性

## DOM 事件

令见 [Events](Evens.md)

## Image 对象

- **创建：**
  ```js {.line-numbers}
  const img = new Image();
  // 可带两个参数表宽高
  ```
- **属性：**
  - `src`：返回图像的 src
  - `currentSrc`：返回图像的绝对路径
  - `alt`：返回图像的 alt
  - `width`、`height`：返回图片的显示宽高
  - `naturalWidth`：返回图片的实际宽高
  - `complete`：返回图片加载完成情况的布尔值
  - `crossOrigin`：返回图片的跨域设置，有两种情况：
    - `anonymous`：跨域请求不要求用户身份（`credentials`），这是默认值。
    - `use-credentials`：跨域请求要求用户身份。
- **方法：**
  - `onload`：加载完成
  - `onerror`：加载失败
