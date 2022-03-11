<p style="font-size: 40px; color: #fff"><b>Document</b></p>

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

### document.getElementsByClassName

根据元素的 class 返回一个即时的 `HTMLCollection`

**语法**

```JavaScript {.line-numbers}
var elements = document.getElementsByClassName(names); // or:
var elements = rootElement.getElementsByClassName(names);
```

**注意**：

1. 返回结果是一个即时的 `HTMLCollection`，会随时根据文档结构变化
2. IE9 以下浏览器不支持
3. 如果要获取 2 个以上 classname，可传入多个 classname，每个用空格相隔
4. 允许嵌套：
   ```JavaScript {.line-numbers}
   var elements = document.getElementById('main').getElementsByClassName('test');
   // id 为 main 下的 class 为 test 的对象
   ```

### document.getElementsByTagName

返回一个包括所有给定标签名称的元素的 HTML **集合** `HTMLCollection` (`Object` 类型)。 整个文件结构都会被搜索，包括根节点。返回的 HTML 集合是动态的, 意味着它可以自动更新自己来保持和 DOM 树的同步而不用再次调用

**语法**

```JavaScript {.line-numbers}
var elements = document.getElementsByTagName(name);
```

**注意**：

1. 如果要对 `HTMLCollection` 集合进行循环操作，最好将其长度缓存起来，因为每次循环都会去计算长度，暂时缓存起来可以提高效率
2. 如果没有存在指定的标签，该接口返回的不是 `null`，而是一个空的 `HTMLCollection`
3. name 是一个代表元素的名称的字符串。特殊字符 "\*" 代表了所有元素。

### document.getElementsByName

主要是通过指定的 name 属性来获取元素，它返回一个即时的 `NodeList` 对象

**语法**

```JavaScript {.line-numbers}
var elements = document.getElementsByName(name)
```

**注意**：

1. 返回对象是一个**即时**的 `NodeList`，它是随时变化的
2. 在 HTML 元素中，并不是所有元素都有 name 属性，比如 div 是没有 name 属性的，但是如果强制设置 div 的 name 属性，它也是可以被查找到的
3. 在 IE 中，如果 id 设置成某个值，然后传入 `getElementsByName` 的参数值和 id 值一样，则这个元素是会被找到的，所以最好不好设置同样的值给 id 和 name

### document.querySelector

&emsp;&emsp; 通过 css 选择器来查找，使用**深度优先搜索**返回第一个匹配的元素，如果没有匹配的元素，则返回 null。

**即**：若有相同的选择器，优先返回嵌套最深的那一个

**语法**

```JavaScript {.line-numbers}
var element = document.querySelector(selectors);
```

**注**：

&emsp;&emsp;`querySelector` 是**静态**的，不随文档而变化，且没有 `length`

## 页面修改型 API

### appendChild

将指定的节点添加到调用该方法的节点的子元素的末尾。

**语法**

```JavaScript {.line-numbers}
parent.appendChild(child);
//复制代码 child 节点将会作为 parent 节点的最后一个子节点。
```

**注意**：

1. 如果被添加的节点是一个页面中存在的节点，则执行后这个节点将会添加到指定位置，其原本所在的位置将移除该节点。也就是说不会同时存在两个该节点在页面上，相当于把这个节点移动到另一个地方。
2. 如果 child 绑定了事件，被移动时，它依然绑定着该事件。

### insertBefore

用来添加一个节点到一个参照节点之前

**语法**

```JavaScript {.line-numbers}
parentNode.insertBefore(newNode, refNode);
```

`parentNode` 表示新节点被添加后的父节点
`newNode` 表示要添加的节点
`refNode` 表示参照节点，新节点会添加到这个节点之前

### removeChild

删除指定的子节点并返回

**语法**

```JavaScript {.line-numbers}
var deletedChild = parent.removeChild(node);
```

`deletedChild` 指向被删除节点的引用，它等于 node，被删除的节点仍然存在于内存中，可以对其进行下一步操作。

### replaceChild

用于使用一个节点替换另一个节点

**语法**

```JavaScript {.line-numbers}
parent.replaceChild(newChild,oldChild);
```

`newChild` 是替换的节点，可以是新的节点，也可以是页面上的节点，如果是页面上的节点，则其将被转移到新的位置
`oldChild` 是被替换的节点

## 节点创造型 API

### createElement

`createElement` 通过传入指定的一个标签名来创建一个元素，如果传入的标签名是一个未知的，则会创建一个自定义的标签

**栗子**

```JavaScript {.line-numbers}
let elem = document.createElement("div");
elem.id = 'test';
elem.style = 'color: red';
elem.innerHTML = '我是新创建的节点';
document.body.appendChild(elem);
```

### createTextNode

用来创建一个文本节点

**语法**

```JavaScript {.line-numbers}
var text = document.createTextNode(data);
```

createTextNode 接收一个参数，这个参数就是文本节点中的文本

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
2. 如果复制的元素有 id，则其副本同样会包含该 id，由于 id 具有唯一性，所以在复制节点后必须要修改其 id
3. 调用接收的 deep 参数最好传入，如果不传入该参数，不同浏览器对其默认值的处理可能不同
4. 如果被复制的节点绑定了事件，则副本也会跟着绑定该事件吗？这里要分情况讨论：
   - 如果是通过 `addEventListener` 或者比如 onclick 进行绑定事件，则副本节点不会绑定该事件
   - 如果是内联方式绑定比如：`<div onclick="showParent()"></div>`，这样的话，副本节点同样会触发事件。

<br><br><hr>

# DOM 事件

## 鼠标事件

|      属性       | 描述                                   |
| :-------------: | :------------------------------------- |
|    `onclick`    | 当用户点击某个对象时调用的事件句柄。   |
| `oncontextmenu` | 在用户点击鼠标右键打开上下文菜单时触发 |
|  `ondblclick`   | 当用户双击某个对象时调用的事件句柄。   |
|  `onmousedown`  | 鼠标按钮被按下。                       |
| `onmouseenter`  | 当鼠标指针移动到元素上时触发。         |
| `onmouseleave`  | 当鼠标指针移出元素时触发               |
|  `onmousemove`  | 鼠标被移动。                           |
|  `onmouseover`  | 鼠标移到某元素之上。                   |
|  `onmouseout`   | 鼠标从某元素移开。                     |
|   `onmouseup`   | 鼠标按键被松开。                       |

> \* 装多个 `onclick` 触发事件时，只执行最后安装的那一个。

## 键盘事件

|     属性     | 描述                       |
| :----------: | :------------------------- |
| `onkeydown`  | 某个键盘按键被按下。       |
| `onkeypress` | 某个键盘按键被按下并松开。 |
|  `onkeyup`   | 某个键盘按键被松开。       |

## 框架/对象（Frame/Object）事件

|       属性       | 描述                                                                |
| :--------------: | :------------------------------------------------------------------ |
|    `onabort`     | 图像的加载被中断。 ( `<object>`)                                    |
| `onbeforeunload` | 该事件在即将离开页面（刷新或关闭）时触发                            |
|    `onerror`     | 在加载文档或图像时发生错误。 ( `<object>`, `<body>`和 `<frameset>`) |
|  `onhashchange`  | 该事件在当前 URL 的锚部分发生修改时触发。                           |
|     `onload`     | 一张页面或一幅图像完成加载。                                        |
|   `onpageshow`   | 该事件在用户访问页面时触发                                          |
|   `onpagehide`   | 该事件在用户离开当前网页跳转到另外一个页面时触发                    |
|    `onresize`    | 窗口或框架被重新调整大小。                                          |
|    `onscroll`    | 当文档被滚动时发生的事件。                                          |
|    `onunload`    | 用户退出页面。 ( `<body>` 和 `<frameset>`)                          |

## 剪贴板事件

|   属性    | 描述                           |
| :-------: | :----------------------------- |
| `oncopy`  | 该事件在用户拷贝元素内容时触发 |
|  `oncut`  | 该事件在用户剪切元素内容时触发 |
| `onpaste` | 该事件在用户粘贴元素内容时触发 |

<br><br><hr>

# 参考

1. [DOM 事件](https://www.jianshu.com/p/b815ae507ed8)
2. [JavaScript 操作 DOM 常用的 API](https://juejin.cn/post/6844903604445249543#heading-2)
