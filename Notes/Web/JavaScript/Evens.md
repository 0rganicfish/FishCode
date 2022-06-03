 <h1 align="center"><b>DOM | Events<</b></h1><br>

- [JavaScript.md](JavaScript.md)
- [DOM.md](DOM.md)
- [README](../README.md)

[TOC]

<br>

# HTML 事件

事件 是某事发生的信号。所有的 DOM 节点都生成这样的信号（但事件不仅限于 DOM）。

## 分配事件处理程序的方式

```JavaScript {.line-numbers}
elem.on`<even> = function_name; // = ()=>`{ };
elem.addEventListener("even", function);
```

- **而：** 使用 `on<even>=function1` 就相当于是
  ```JavaScript {.line-numbers}
  function(even){
    function1();
  }
  ```
- 对于文档级的处理程序 —— **始终使用**的是 `addEventListener`
  - 当我们将事件处理程序分配给 `document` 对象时，我们应该始终使用 `addEventListener`，而不是 `document.on<event>`，因为后者会引起冲突：新的处理程序会覆盖旧的处理程序。
  - 对于实际项目来说。在 document 上有许多由代码的不同部分设置的处理程序，这是很正常的。

### Event

**构造函数：** `Event(typeArg[, eventInit])`
**参数说明：**

- `typeArg` ：代表事件类型字符串，例如 keypress，click
- `eventInit`
  - `bubbles` ：定义事件是否冒泡，默认为 `false`
  - `cancelable` ：定义事件是否可取消，默认为 `false`
  - `composed` ：指示事件是否会在影子 DOM 根节点之外触发侦听器。默认为 `false`

**方法：**

- `Event.preventDefault()` ：取消事件（如果可以取消）。
- `Event.stopImmediatePropagation()` ：对于此特定事件，阻止所有其他侦听器被调用。这包括附加到相同元素的侦听器以及附加到稍后将遍历的元素的侦听器（例如，在捕获阶段）。
- `Event.stopPropagation()` ：阻止事件在 DOM 中进一步传播。

### EventTarget

EventTarget 是一个 DOM 接口，由可以接收事件、并且可以创建侦听器的对象实现。

**方法：**

- ` EventTarget.removeEventListener()` ：EventTarget 中删除事件侦听器。
- `EventTarget.dispatchEvent()` ：将事件分派到此 EventTarget。
- `addEventListener()` 方法将指定的监听器注册到 `EventTarget` 上，当该对象**触发指定的事件**时，指定的回调**函数就会被执行**。

  - **定义：**
    ```JavaScript {.line-numbers}
    addEventListener(type, listener, options);
    ```
    - `type`：DOM 事件 (没有 on)
    - `listener` 函数或对象
    - `capture ` 选项有两个可能的值：
      - 如果为 `false`（默认值），则在**冒泡阶段**设置处理程序。
      - 如果为 `true`，则在**捕获阶段**设置处理程序。
  - 当 `listener` 为对象时：会调用对象中的 `handleEvent`函数

    ```JavaScript {.line-numbers}
    let obj = {
      name: "fish",
      handleEvent: function() {
        console.log(this.name);
      } //不能是箭头函数诶，会读取不到this
    };
    elem.addEventListener("even", obj);
    ```

    而且可以不用再 remove 掉 listener，还能通过**赋值**改变调用的函数

>

- **但是：** 在 `elem.addxx("xx", (event)=>{code;});` 中，如果 elem 的结构存在着嵌套：`<span><b>mie</b></span>`，那么，`even` 将指向的是**最深**一层的那个。要如期，则应该加上：`event.target.closest("elem")`，才匹配最近的祖先 `<span>`

>

- **事件阻止：**
  - `event.preventDefault()`

### 封装后的 addEventListener

- **码：**
  ```JavaScript {.line-numbers}
  const on = (el, evt, fn, opts = {}) => {
    const delegatorFn = (e) =>
      e.target.matches(opts.target) && fn.call(e.target, e);
    el.addEventListener(
      evt,
      opts.target ? delegatorFn : fn,
      opts.option || false
    );
    if (opts.target) return delegatorFn;
  };
  ```
- **Examples：**

  ```JavaScript {.line-numbers}
  const fn = () => console.log("mie!"),
    user = document.getElementById("user");

  on(user, "click", fn); //默认行为：点击 user 框后输出 mie，默认 冒泡
  on(user, "click", fn, { target: "img" }); //点击 user 下的 img 标签，输出 mie
  on(user, "click", fn, { option: true }); // 同默认，但是 捕获
  ```

<br>

## 默认的浏览器行为

一些常见的：

- `mousedown` —— 开始选择（移动鼠标进行选择）。
  在 `<input type="checkbox">` 上的 `click` —— 选中 | 取消选中 的 input。
- `submit` —— 点击 `<input type="submit">` 或者在表单字段中按下 Enter 键会触发该事件，之后浏览器将提交表单。
- `keydown` —— 按下一个按键会导致将字符添加到字段，或者触发其他行为。
- `contextmenu` —— 事件发生在鼠标右键单击时，触发的行为是显示浏览器上下文菜单。

&emsp;&emsp; 如果我们只想通过 JavaScript 来处理事件，那么所有默认行为都是可以被阻止的。
&emsp;&emsp; 想要阻止默认行为 —— 可以使用` event.preventDefault()` 或` return false`。第二个方法只适用于通过 `on<event>` 分配的处理程序。
&emsp;&emsp; `addEventListener` 的 `passive: true` 选项告诉浏览器该行为不会被阻止。这对于某些移动端的事件（像 `touchstart` 和 `touchmove`）很有用，用以告诉浏览器在滚动之前不应等待所有处理程序完成。
&emsp;&emsp; 如果默认行为被阻止，`event.defaultPrevented` 的值会变成 `true`，否则为 false。

<br>

## UI 事件

### 鼠标事件

|     属性      | 描述                               |
| :-----------: | :--------------------------------- |
|    `click`    | 当点击某个对象时调用的事件句柄。   |
| `contextmenu` | 在点击鼠标右键打开上下文菜单时触发 |
|  `dblclick`   | 当双击某个对象时调用的事件句柄。   |
|  `mousedown`  | 鼠标按钮被按下。                   |
| `mouseenter`  | 当鼠标指针移动到元素上时触发。     |
| `mouseleave`  | 当鼠标指针移出元素时触发           |
|  `mousemove`  | 鼠标被移动。                       |
|  `mouseover`  | 鼠标移到某元素之上。               |
|  `mouseout`   | 鼠标从某元素移开。                 |
|   `mouseup`   | 鼠标按键被松开。                   |

> &emsp;&emsp;

- **顺序：**
  当点击左键时，遵循 mousedown → mouseup → click 的顺序调用处理程序
- **按键状态：**
  `event.button` 的值为 0 => 左键， 1 => 中键， 2 => 右键
- **组合键：**

  - `shiftKey`：Shift
  - `altKey`：Alt（或对于 Mac 是 Opt）
  - `ctrlKey`：Ctrl
  - `metaKey`：对于 Mac 是 Cmd

  如果在事件期间按下了相应的键，则它们为 `true`

- **坐标：**
  - 相对于窗口的坐标：`clientX` 和 `clientY`
  - 相对于文档的坐标：`pageX` 和 `pageY` （随滚动而变
  - 相对于元素的坐标：`offsetX` 和 `offsetY`

>

- **元素拖拽：**

<br>

### 键盘事件

按一个按键总是会产生一个键盘事件，无论是符号键，还是例如 Shift 或 Ctrl 等特殊按键

**键盘事件：**

- `keydown` —— 在按下键时（如果长按按键，则将自动重复），
- `keyup` —— 释放按键时。

**键盘事件的主要属性：**

- `code` —— “按键代码”（"KeyA"，"ArrowLeft" 等），特定于键盘上按键的物理位置。
- k`ey —— 字符（"A"，"a" 等），对于非字符（non-character）的按键，通常具有与 code 相同的值。

<br>

## 表单事件

|    属性    | 描述                                                                            |
| :--------: | :------------------------------------------------------------------------------ |
|   `blur`   | 元素失去焦点时触发                                                              |
|  `change`  | 在表单元素的内容改变时触发( `<input>`, `<keygen>`, `<select>`, 和 `<textarea>`) |
|  `focus`   | 元素获取焦点时触发                                                              |
| `focusin`  | 元素即将获取焦点时触发                                                          |
| `focusout` | 元素即将失去焦点时触发                                                          |
|  `input`   | 元素获取输入时触发                                                              |
|  `reset`   | 表单重置时触发                                                                  |
|  `search`  | 向搜索域输入文本时触发 ( `<input="search">`)                                    |
|  `select`  | 选取文本时触发 ( `<input>` 和` <textarea>`)                                     |
|  `submit`  | 表单提交时触发                                                                  |

**访问：**

- `document.forms` 一个表单元素可以通过 `document.forms[name/index]` 访问到。
- `form.elements` 表单元素可以通过 `form.elements[name/index]` 的方式访问，或者也可以使用 `form[name/index]`。elements 属性也适用于 `<fieldset>`。
- `element.form` 元素通过 form 属性来引用它们所属的表单。
- `value` 可以被通过 `input.value` 等来获取到。
  - 对于单选按钮（radio button）和复选框（checkbox），可以使用 `input.checked` 来确定是否选择了一个值。
  - 对于 `<select>`，可以通过索引 `select.selectedIndex` 来获取它的 value，也可以通过 `<option>` 集合 `select.options` 来获取它的 value

<br>

## 框架/对象（Frame/Object）事件

|      属性      | 描述                                                                |
| :------------: | :------------------------------------------------------------------ |
|    `abort`     | 图像的加载被中断。 ( `<object>`)                                    |
| `beforeunload` | 在即将离开页面（刷新或关闭）时触发                                  |
|    `error`     | 在加载文档或图像时发生错误。 ( `<object>`, `<body>`和 `<frameset>`) |
|  `hashchange`  | 在当前 URL 的锚部分发生修改时触发。                                 |
|     `load`     | 一张页面或一幅图像完成加载。                                        |
|   `pageshow`   | 在访问页面时触发                                                    |
|   `pagehide`   | 在离开当前网页跳转到另外一个页面时触发                              |
|    `resize`    | 窗口或框架被重新调整大小。                                          |
|    `scroll`    | 当文档被滚动时发生的事件。                                          |
|    `unload`    | 退出页面。 ( `<body>` 和 `<frameset>`)                              |

## 数据更改事件

- `change` 值被改变 => 对于文本输入，当失去焦点时触发
- `input` 文本输入的每次更改 => 立即触发，与 `change` 不同
- `cut | copy | paste` 剪贴/拷贝/粘贴行为 => 行为可以被阻止。`event.clipboardData` 属性可以用于访问剪贴板

<br>

# 参考

1.  [DOM 事件 参考](https://www.runoob.com/jsref/dom-obj-event.html)
