<p style="font-size: 40px; color: #fff"><b>Document_API</b></p>

- [JavaScript.note](JavaScript.md)
  [TOC]

# API

## 节点查询型 API

### document.getElementById

根据元素 id 返回元素，返回值是 Element 类型，如果不存在该元素，则返回 null.

**语法**：

```JavaScript {.line-numbers}
var element = document.getElementById(name);
```

### getElementsBy\*

- `document.getElementsByClassName` 根据元素的 class 返回一个即时的 `HTMLCollection`
  - **语法**
    ```JavaScript {.line-numbers}
    var elements = document.getElementsByClassName(names); // or:
    var elements = rootElement.getElementsByClassName(names);
    ```
- `document.getElementsByTagName`
  - **语法**
    ```JavaScript {.line-numbers}
    var elements = document.getElementsByTagName(name);
    ```
- `document.getElementsByName` 通过 name 属性来获取元素，返回一个即时的 `NodeList` 对象
  - **语法**
  ```JavaScript {.line-numbers}
  var elements = document.getElementsByName(name)
  ```

> 但这些 `getElementsBy*` 已经成了历史的眼泪......因为还不如用 **选择器** 查找。但同时，也就这些是实时更新的

<br>

### document.querySelector

&emsp;&emsp; 通过 css 选择器来查找，使用**深度优先搜索**返回第一个匹配的元素，如果没有匹配的元素，则返回 null。且相当于是 `document.querySelectorAll()[0]` 但速度更快

**即**：若有相同的选择器，优先返回嵌套最深的那一个

**语法**

```JavaScript {.line-numbers}
var element = document.querySelector(selectors);
```

**注**：

&emsp;&emsp;`querySelector` 是**静态**的，不随文档而变化，且没有 `length`

<br>

## 页面修改型 API

### 插入节点

元素插入方法，指明了不同的插入位置：

- `node.append(...nodes or strings)` —— 在 node 末尾 插入节点或字符串，
- `node.prepend(...nodes or strings)` —— 在 node 开头 插入节点或字符串，
- `node.before(...nodes or strings)` —— 在 node 前面 插入节点或字符串，
- `node.after(...nodes or strings)` —— 在 node 后面 插入节点或字符串，
- `node.replaceWith(...nodes or strings)` —— 将 node 替换为给定的节点或字符串。

**注意**：

1. 如果被添加的节点是一个页面中存在的节点，则执行后这个节点将会添加到指定位置，其原本所在的位置将移除该节点。也就是说不会同时存在两个该节点在页面上，相当于把这个节点移动到另一个地方。
2. 如果 child 绑定了事件，被移动时，它依然绑定着该事件。

### 替换

- `node.replaceWith(...nodes or strings)` — 替换 node。

<br>

### 子节点修改 \*Old School

> 由于历史原因，还存在“老式”的 DOM 操作方法。这些方法来自真正的远古时代。如今，没有理由再使用它们了

- `appendChild` 将指定的节点添加到调用该方法的节点的子元素的末尾。
  - **语法**
    ```JavaScript {.line-numbers}
    parent.appendChild(child);
    //child 节点将会作为 parent 节点的最后一个子节点。
    ```
- `insertBefore` 用来添加一个节点到一个参照节点之前
  - **语法**
    ```JavaScript {.line-numbers}
    parentNode.insertBefore(newNode, refNode);
    ```
  - `parentNode` 表示新节点被添加后的父节点
  - `newNode` 表示要添加的节点
  - `refNode` 表示参照节点，新节点会添加到这个节点之前
- `removeChild` 删除指定的子节点并返回
  - **语法**
    ```JavaScript {.line-numbers}
    var deletedChild = parent.removeChild(node);
    ```
  - `deletedChild` 指向被删除节点的引用，它等于 node，被删除的节点仍然存在于内存中，可以对其进行下一步操作。
- ` replaceChild` 用于使用一个节点替换另一个节点
  - **语法**
    ```JavaScript {.line-numbers}
    parent.replaceChild(newChild,oldChild);
    ```
  - `newChild` 是替换的节点，可以是新的节点，也可以是页面上的节点，如果是页面上的节点，则其将被转移到新的位置
  - `oldChild` 是被替换的节点

<br>

## 节点创造型 API

### createElement

通过传入指定的一个**标签名**来创建一个元素，如果传入的标签名是一个未知的，则会创建一个自定义的标签

**栗子**

```JavaScript {.line-numbers}
let elem = document.createElement("div");
elem.id = 'test';
elem.style = 'color: red';
elem.innerHTML = '我是新创建的节点';
document.body.appendChild(elem);
```

### createTextNode

用来创建一个文本节点，接收一个参数，这个参数就是文本节点中的**文本**

**语法**

```JavaScript {.line-numbers}
var text = document.createTextNode(value);
```

### cloneNode

返回调用该方法的节点的一个副本

**语法**

```JavaScript {.line-numbers}
var dupNode = node.cloneNode(deep);
```

`node` 将要被克隆的节点
`dupNode` 克隆生成的副本节点
`deep`（可选）是否采用深度克隆,如果为 true,则该节点的所有后代节点也都会被克隆,如果为 false,则只克隆该节点本身.

**注意**:

1. 和 `createElement` `一样，cloneNode` 创建的节点只是游离有 HTML 文档外的节点，要调用 `appendChild` 方法才能添加到文档树中
2. 如果复制的元素有 id，则其副本同样会包含该 id，由于 **id 具有唯一性**，所以在复制节点后必须要修改其 id
3. 调用接收的 deep 参数最好传入，如果不传入该参数，不同浏览器对其默认值的处理可能不同
4. 如果被复制的节点绑定了事件，则副本也会跟着绑定该事件吗？这里要分情况讨论：
   - 如果是通过 `addEventListener` 或者比如 `onclick` 进行绑定事件，则副本节点不会绑定该事件
   - 如果是内联方式绑定比如：`<div onclick="showParent()"></div>`，这样的话，副本节点同样会触发事件。

<br><br><hr>

# 参考

1. [JavaScript 操作 DOM 常用的 API](https://juejin.cn/post/6844903604445249543#heading-2)
2. [现代 JS 教程\_DOM 查询](https://zh.javascript.info/searching-elements-dom)
3. [querySelector(All) 相比 getElement(s)By 在生产环境中有哪些优势？ 知乎](https://www.zhihu.com/question/404365645/answer/1314691976)
