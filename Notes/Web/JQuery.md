 <p style="font-size: 40px; color: #fff; text-align:center"><b>JQuery</b></p><br>

- [README](README.md)
- [JavaScript](JavaScript/JavaScript.md)

[TOC]

<br>

## 函数入口

`window.onload()` 方法是等到页面中所有元素加载完毕之后，才执行，即 `javascript` 此时才可以访问网页中的任何元素。而 jQuery 使用 `$(document).ready()` 方法，可以在 DOM 载入就绪时就对其进行操纵并调用执行它所绑定的函数。也就是说在 jQ 中，不需要等待所有图片加载完再执行。

但是就会有个问题，当获取图片宽高的时候，可能获取不到。不过 jQ 中单独提出了一个页面加载的方法——`load()` 方法，如果这个处理函数绑定给 `window` 对象则会在所有内容加载完毕之后触发，且不会被覆盖：

```JavaScript {.line-numbers}
$(window).load(function(){
   // 执行代码
});
```

上面的代码，等同于 js 中的：

```JavaScript {.line-numbers}
window.onload = function(){
    // 执行代码
}
```

## 选择器

返回 JQuery 对象。基本与 css 一样，也催生出了 `document.querySelector(All)`
同时，它基本不用写循环，因为 JQuery 是隐式循环，源码本身就已经实现循环了

### 过滤器

**基本过滤器**

<table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>:first</code></td><td>$('<code>div:first</code>')</td><td>选取所有<code>div</code>元素中，第一个<code>div</code>元素</td></tr><tr><td><code>:last</code></td><td>$('<code>div:last</code>')</td><td>选取所有<code>div</code>元素中，最后一个<code>div</code>元素</td></tr><tr><td><code>:eq(index)</code></td><td>$('<code>li:eq(2)</code>')</td><td>选取所有<code>li</code>元素中，索引号为<code>2</code>的元素，<code>index</code>从<code>0</code>开始</td></tr><tr><td><code>:even</code></td><td>$('<code>li:even</code>')</td><td>选取所有<code>li</code>元素中，索引号为<code>偶数</code>的元素</td></tr><tr><td><code>:odd</code></td><td>$('<code>li:odd</code>')</td><td>选取所有<code>li</code>元素中，索引号为<code>奇数</code>的元素</td></tr><tr><td><code>:not(selector)</code></td><td>$('<code>div:not(.box)</code>')</td><td>选取所有<code>div</code>元素中，不是<code>.box</code>的<code>div</code>元素</td></tr><tr><td><code>:gt(index)</code></td><td>$('<code>li:gt(1)</code>')</td><td>选取所有<code>li</code>元素中，索引号<code>大于1</code>的元素，<code>index</code>从<code>0</code>开始</td></tr><tr><td><code>:lt(index)</code></td><td>$('<code>li:lt(5)</code>')</td><td>选取所有<code>li</code>元素中，索引号<code>小于5</code>的元素，<code>index</code>从<code>0</code>开始</td></tr><tr><td><code>:header</code></td><td>$('<code>:header</code>')</td><td>选取所有<code>标题</code>元素,<code>&lt;h1&gt;</code>、<code>&lt;h2&gt;</code>、<code>&lt;h3&gt;</code>...</td></tr><tr><td><code>:animated</code></td><td>$('<code>div:animated</code>')</td><td>选取正在执行动画的<code>div</code>元素</td></tr><tr><td><code>:focus</code></td><td>$('<code>:focus</code>')</td><td>选取当前获取焦点的元素</td></tr></tbody></table>

**内容过滤器：**

<table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>:contains(text)</code></td><td>$('<code>div:contains("我")</code>')</td><td>选取含有文本“<code>我</code>”的所有<code>div</code>元素</td></tr><tr><td><code>:empty</code></td><td>$('<code>div:empty</code>')</td><td>选取不包含子元素或者文本的空<code>div</code>元素</td></tr><tr><td><code>:has(selector)</code></td><td>$('<code>div:has(p)</code>')</td><td>选取含有<code>p</code>元素的<code>div</code>元素</td></tr><tr><td><code>:parent</code></td><td>$('<code>div:parent</code>')</td><td>选取含有子元素或者文本的<code>div</code>元素</td></tr></tbody></table>

**属性过滤器**

<table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>[attribute]</code></td><td>$('<code>div[id]</code>')</td><td>选取拥有属性<code>id</code>的<code>div</code>元素</td></tr><tr><td><code>[attribute=value]</code></td><td>$('<code>div[title=test]</code>')</td><td>选取属性<code>title</code>为<code>"test"</code>的<code>div</code>元素</td></tr><tr><td><code>[attribute!=value]</code></td><td>$('<code>div[title!=test]</code>')</td><td>选取属性<code>title</code>不为<code>"test"</code>的<code>div</code>元素(没有属性<code>title</code>的<code>div</code>也会被选取)</td></tr><tr><td><code>[attribute^=value]</code></td><td>$('<code>div[title^=test]</code>')</td><td>选取属性<code>title</code>以<code>"test"</code>开始的<code>div</code>元素</td></tr><tr><td><code>[attribute $=value]</code></td><td>$('<code>div[title$=test]</code>')</td><td>选取属性<code>title</code>以<code>"test"</code>结束的<code>div</code>元素</td></tr><tr><td><code>[attribute*=value]</code></td><td>$('<code>div[title*=test]</code>')</td><td>选取属性<code>title</code>含有<code>"test"</code>的<code>div</code>元素</td></tr><tr><td><code>[attribute=value]</code></td><td>$('<code>div[title="en"]</code>')</td><td>选取属性<code>title</code>为<code>en</code>或以<code>en</code>为前缀的<code>div</code>元素</td></tr><tr><td><code>[attribute~=value]</code></td><td>$('<code>div[title~="uk"]</code>')</td><td>选取属性<code>title</code>用空格分隔的值中包含字符<code>uk</code>的元素</td></tr><tr><td><code>[attribute][attribute2]</code></td><td>$('<code>div[id][titlr=test]</code>')</td><td>选取拥有属性<code>id</code>并且属性<code>title</code>为<code>test</code>的<code>div</code>元素</td></tr></tbody></table>

**表单过滤器**

<table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>:enabled</code></td><td>$('<code>#form:enabled</code>')</td><td>选取<code>id</code>名为“<code>form</code>”的表单内所有<code>可用</code>元素</td></tr><tr><td><code>:disabled</code></td><td>$('<code>#form:disabled</code>')</td><td>选取<code>id</code>名为“<code>form</code>”的表单内所有<code>不可用</code>元素</td></tr><tr><td><code>:checked</code></td><td>$('<code>input:checked</code>')</td><td>选取所有被选中的<code>input</code>元素(单选框、复选框)</td></tr><tr><td><code>:selected</code></td><td>$('<code>select option:selected</code>')</td><td>选取所有被选中的<code>选项</code>元素</td></tr></tbody></table>

### 方法

**选择器方法**

<table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>parent()</code></td><td><code>$('#first').parent();</code></td><td>查找父亲</td></tr><tr><td><code>eq(index)</code></td><td><code>$('li').eq(2);</code></td><td>index从0开始</td></tr><tr><td><code>next()</code></td><td><code>$('li').next()</code></td><td>找下一个兄弟 (All)</td></tr><tr><td><code>prev()</code></td><td><code>$('li').prev()</code></td><td>找上一个兄弟 (All)</td></tr><tr><td><code>siblings()</code></td><td><code>$('li').siblings()</code></td><td>匹配前后所有的兄弟</td></tr></tbody></table>

<br>

## 节点

### 节点操作

- **添加节点**
    <table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>append()</code></td><td><code>$('ul').append('&lt;li&gt;上海1&lt;/li&gt;')</code></td><td>在<code>ul</code>子元素的最后面依次添加<code>li</code></td></tr><tr><td><code>appendTo()</code></td><td><code>$('&lt;li&gt;上海2&lt;/li&gt;').appendTo('ul')</code></td><td>将<code>li</code>添加到<code>ul</code>子元素的最后面，参数与<code>append</code>正好颠倒过来</td></tr><tr><td><code>prepend()</code></td><td><code>$('ul').prepend('&lt;li&gt;北京1&lt;/li&gt;')</code></td><td>在<code>ul</code>子元素的最前面依次添加<code>li</code></td></tr><tr><td><code>prependTo()</code></td><td><code>$('&lt;li&gt;北京2&lt;/li&gt;').prependTo('ul')</code></td><td>将<code>li</code>添加到<code>ul</code>子元素的最前面，参数与<code>prepend</code>正好颠倒过来</td></tr><tr><td><code>after()</code></td><td><code>$('ul').after('&lt;h2&gt;哈哈哈1&lt;/h2&gt;')</code></td><td>在<code>ul</code>的后面添加<code>h2</code>(兄弟元素)</td></tr><tr><td><code>insertAfter()</code></td><td><code>$('&lt;h2&gt;哈哈哈2&lt;/h2&gt;').insertAfter('ul')</code></td><td>将<code>h2</code>添加到<code>ul</code>的后面，参数与<code>after</code>正好颠倒过来</td></tr><tr><td><code>before()</code></td><td><code>$('ul').before('&lt;h2&gt;城市1&lt;/h2&gt;')</code></td><td>在<code>ul</code>的前面添加<code>h2</code>(兄弟元素)</td></tr><tr><td><code>insertBefore()</code></td><td><code>$('&lt;h2&gt;城市2&lt;/h2&gt;').insertBefore('ul')</code></td><td>将<code>h2</code>添加到<code>ul</code>的前面，参数与<code>before</code>正好颠倒过来</td></tr></tbody></table>

- **删除节点**
  1. `remove()`：完全删除节点
  2. `detach()`：删除，但事件绑定还在
  3. `empty()`：相当于只是 `innerHTML = "";`
- **克隆节点**
  `clone()`：默认浅拷贝，加参数 true 则深拷贝
- **替换节点：**
  `replaceWith()`
- **包裹节点：**
    <table><thead><tr><th>名称</th><th>用法</th><th>描述</th></tr></thead><tbody><tr><td><code>wrap()</code></td><td><code>$('h3').wrap('&lt;i&gt;&lt;/i&gt;')</code></td><td>将所有的<code>h3</code>标签单独用<code>i</code>标签包裹起来</td></tr><tr><td><code>wrapAll()</code></td><td><code>$('h3').wrapAll('&lt;i&gt;&lt;/i&gt;')</code></td><td>将所有的<code>h3</code>标签全部包裹在<code>i</code>标签内</td></tr><tr><td><code>wrapInner()</code></td><td><code>$('h3').wrapInner('&lt;i&gt;&lt;/i&gt;')</code></td><td>将<code>h3</code>标签里面的子内容(包括文本节点)用<code>i</code>标签包裹起来</td></tr></tbody></table>

### attr 属性

- `$().attr(name | val)`：单参数时为获取，双参数为设置。设置多值时，参数为 json 对象
- `$().removeAttr()`：删除属性值，多值时空格间隔
- 而：对于 `checked、selected、disabled` 这类 boolean 类型的属性来说，不能用 attr 方法，只能用 `prop` 方法。
- `$().addClass(val)` | `$().removeClass(val)` ：只 添加 | 删除 而不是替换掉
- `$().toggleClass(val)`：切换 —— 存在则删除，不在则添加
- `$().is(val)`：判断元素是否包含某一属性

### CSS 样式

- `$().css(name | val)`：单属性名为获取，双参数为设置。设置多值时，参数为 json 对象

### 事件

- **事件监听：**
  - `$().on(event, fun)`：类同与原生的 `ele.onevent = fun`
- **事件绑定：** `$().event(fun)`：
- **事件合成：** `$().hover(enter, leaver)`，鼠标进入时触发 enter 函数，
- **阻止冒泡：** `fun(e){stopPropagation();}`
- **事件属性：**
  - `e.which`：获取点击的按键码(鼠标: e.button，键盘: e.code)
  - `e.metaKey`：获取 Ctrl 键
- **移除事件：** `$().unbind(event)`

### 取值

- `$().html()`：相当于 innerHTML，带参数则为设置
- `$().text()`：相当于 innerText，带参数则为设置
- `$().val()`：相当于 value，带参数则为设置

<br>

## 动画

- **显示 | 隐藏：**
  - `$().show(val)` | `$().hide(val)`：带参数则 淡入淡出地改变宽高和不透明度，val 为 毫秒
  - `$().fadeIn()` | `$().fadeout()`：只改透明度的淡入淡出
  - `slideUp()` 方法和 `slideDown()` 方法只会改变元素的高度，如果一个元素的 di`splay 属性值为“none”，调用 `slideDown()` 方法的时候元素由上至下延伸显示。`slideUp()` 正好相反，元素将由下到上缩短隐藏。
- **自定义：** `$().animate(params, speed, way, callback)`
  - `params`：一个包含样式和值的 json 对象，比如`{p1:"val1",p2:"val2",...}`；
  - `speed`：动画执行速度(可选)，默认 400；
  - `way`：表示过度使用哪种缓动函数(默认 `swing`，jQ 内部还支持一个 `linear`)
  - `callback`：在动画执行完之后，执行的函数(可选)。

<br>

## Ajax



<br><hr>

## 参考

> 1. [JQuery 入门[1] \_思否](https://segmentfault.com/a/1190000013677113)
> 2. [JQuery 入门[2] \_思否](https://segmentfault.com/a/1190000013677253)
