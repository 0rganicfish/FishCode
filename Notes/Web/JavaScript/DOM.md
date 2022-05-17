<p style="font-size: 40px; color: #fff"><b>DOM</b></p>

- [README](../README.md)
- [JS](JS.md)

[TOC]

# DOM 树

## 树结构

### 概述

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

### DOM 的自动修正

&emsp;&emsp;如果浏览器遇到格式不正确的 HTML，它会在形成 DOM 时自动更正它。
&emsp;&emsp; 例如，顶级标签总是 `<html>`。即使它不存在于文档中 — 它也会出现在 DOM 中，因为浏览器会创建它。对于 `<body>` 也是一样。
&emsp;&emsp; 例如，如果一个 HTML 文件中只有一个单词 “Hello”，浏览器则会把它包装到 `<html>` 和 `<body>` 中，并且会添加所需的 `<head>`

### 访问 DOM

&emsp;&emsp; 给定一个 DOM 节点，我们可以使用导航（navigation）属性访问其直接的邻居，并返回实时更新的 **集合 (Set)**

- 这些属性主要分为两组：
  - 对于所有节点：
    `parentNode`，`childNodes`，`firstChild`，`lastChild`，`previousSibling`，`nextSibling`。
  - 仅对于元素节点：
    `parentElement`，`children`，`firstElementChild`，`lastElementChild`，`previousElementSibling`，`nextElementSibling`。

&emsp;&emsp; 某些类型的 DOM 元素，例如 table，提供了用于访问其内容的其他属性和集合。
&emsp;&emsp; 且由于空格与换行也算作节点，因此用 `*Nodes` 访问是包括了这些**文本节点**的

### 主要的 DOM 节点属性

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

### NodeList 与 HTMLCollection

`HTMLCollection` 是一个实时更新的节点对象，由 `getElementsByTagName()` | `node.children` 获得

`NodeList` 是一个 DOM 节点快照的集合，仅检测 `innerHTML` 的更新，由 `querySelectorAll()` | `node.childNodes` 获得

- 但只有 `NodeList` 才能被 `forEach()` 和 `for(.. of ..)` 遍历。但可以转为数组：`const arr = [...HTMLCol]`

<br><br>

# API

## Document

**令见：**[DOM Document API](DOM_Document_API.md)

## Element

`Element` 是一个通用性非常强的基类，所有 `Document` 对象下的对象都继承自它。这个接口描述了所有相同种类的元素所普遍具有的方法和属性。一些接口继承自 `Element` 并且增加了一些额外功能的接口描述了具体的行为。

**令见：** [DOM Element](DOM_Element.md)

## 其他 API
