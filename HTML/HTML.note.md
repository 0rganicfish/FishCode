# HTML.note

- [cpp.note.main](../cpp.note/main.md)
- [关键字缩写](#关键字缩写)
- [CSS](#CSS)
- [大杂烩](sample.html)

## 关键字缩写

- 参考字典：[HTML 元素参考](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element)

|    HTML 标签     |         英文全称          |            中文释义            |
| :--------------: | :-----------------------: | :----------------------------: |
|      `<a>`       |          Anchor           |               锚               |
|     `<abbr>`     |       Abbreviation        |             缩写词             |
|   `<acronym>`    |          Acronym          |        取首字母的缩写词        |
|   `<address>`    |          Address          |              地址              |
|     `<dfn>`      | Defines a Definition Term |          定义定义条目          |
|     `<kbd>`      |         Keyboard          |          键盘（文本）          |
|     `<samp>`     |          Sample           |           示例（文本           |
|     `<var>`      |         Variable          |          变量（文本）          |
|      `<tt>`      |         Teletype          |         打印机（文本）         |
|     `<code>`     |           Code            |         源代码（文本）         |
|     `<pre>`      |       Preformatted        |       预定义格式（文本）       |
|  `<blockquote>`  |      Block Quotation      |           区块引用语           |
|     `<cite>`     |         Citation          |              引用              |
|      `<q>`       |         Quotation         |             引用语             |
|    `<strong>`    |          Strong           |          加重（文本）          |
|      `<em>`      |        Emphasized         |          加重（文本）          |
|      `<b>`       |           Bold            |          粗体（文本）          |
|      `<i>`       |          Italic           |          斜体（文本）          |
|     `<big>`      |            Big            |          变大（文本）          |
|    `<small>`     |           Small           |          变小（文本）          |
|     `<sup>`      |       Superscripted       |          上标（文本）          |
|     `<sub>`      |        Subscripted        |          下标（文本）          |
|     `<bdo>`      | Direction of Text Display |          文本显示方向          |
|      `<br>`      |           Break           |              换行              |
|    `<center>`    |         Centered          |          居中（文本）          |
|     `<font>`     |           Font            |              字体              |
|      `<u>`       |        Underlined         |         下划线（文本）         |
| `<s>`/`<strike>` |      Strike through       |             删除线             |
|     `<div>`      |         Division          |              分隔              |
|     `<span>`     |           Span            |              范围              |
|      `<ol>`      |          Ordered          |            排序列表            |
|      `<ul>`      |      Unordered List       |           不排序列表           |
|      `<li>`      |         List Item         |            列表项目            |
|      `<dl>`      |      Definition List      |            定义列表            |
|      `<dt>`      |      Definition Term      |            定义术语            |
|      `<dd>`      |  Definition Description   |            定义描述            |
|     `<del>`      |          Deleted          |         删除（的文本）         |
|     `<ins>`      |         Inserted          |         插入（的文本）         |
|  `<h1>`~`<h6>`   |   Header 1 to Header 6    |        标题 1 到标题 6         |
|      `<p>`       |         Paragraph         |              段落              |
|      `<hr>`      |      Horizontal Rule      |             水平尺             |
|     `<href>`     |    hypertext reference    |           超文本引用           |
|     `<alt>`      |           alter           | 替用(一般是图片显示不出的提示) |
|     `<src>`      |          Source           |           源文件链接           |
|     `<cell>`     |           cell            |               巢               |
| `<cellpadding>`  |        cellpadding        |             巢补白             |
| `<cellspacing>`  |        cellspacing        |             巢空间             |
|      `<nl>`      |     navigation lists      |            导航列表            |
|      `<tr>`      |         table row         |          表格中的一行          |
|      `<th>`      |     table header cell     |          表格中的表头          |
|      `<td>`      |      table data cell      |       表格中的一个单元格       |
|    `<iframe>`    |       Inline frame        |          定义内联框架          |
|   `<optgroup>`   |       Option group        |           定义选项组           |
|       ` `        |           空格            |            `&nbsp;`            |
|       `<`        |          小于号           |             `&lt;`             |
|       `>`        |          大于号           |             `&gt;`             |
|       `&`        |           和号            |            `&amp;`             |
|       `"`        |           引号            |            `&quot;`            |
|       `'`        |           撇号            |      `&apos;` (IE 不支持)      |

## CSS

### 字体基础

- `line-height`，行间距，默认 1.2 ，当行间距等于盒子高度时，就可以使文字**垂直居中**
- `font-weight`，字重(粗细)，加粗：`bold`，细：`height`
- `font-size`，字体大小，默认 16px, 最小是 12px
- `font-family: "fangsong";`，字体样式
- `text-decoration`，下划线类型
- `text-indent` ： 第一行文字缩进长度
- `text-shadow` 设置文本阴影
- `text-transform` 控制元素中的字母
- `text-align` , 文字对齐方式
  - `left` ：行内内容向左侧边对齐。
  - `right` ：行内内容向右侧边对齐。
  - `center` ：行内内容**水平居中**。
  - `justify` ：文字向两侧对齐，对最后一行无效。
  - `justify-all` ：和 justify 一致，但是强制使最后一行两端对齐。
- `direction` 设置文本方向。
- `letter-spacing` 设置字符间距
- `unicode-bidi` 设置或返回文本是否被重写
- `vertical-align` 设置元素的垂直对齐
- `white-space` 设置元素中空白的处理方式
- `word-spacing` 设置字间距
- `color`，字体颜色值

### 图片

- `opacity` , 透明度

### 按钮/边框

- `border-radius` , 圆角半径
- `margin` , 外边距
  - 当只指定一个值时，该值会统一应用到**全部四个边**的外边距上。
  - 指定两个值时，第一个值会应用于**上边和下边**的外边距，第二个值应用于**左边和右边**。
  - 指定三个值时，第一个值应用于**上边**，第二个值应用于**右边和左边**，第三个则应用于**下边**的外边距。
  - 指定四个值时，依次（**顺时针方向**）作为上边，右边，下边，和左边的外边距。
  - 也可以单是 `margin-right`来指定
  - **居中**则是 `margin`的`left`和`right`为 **`auto`**，且同时元素的**宽是确定**的
- `padding` , 内边距
- `height`、`width` , 宽高
- 但是，如图 完整的框是指 长：`width + 2\*(margin + padding + border)`
  <br><img src="img/border.png" height="150px">
- h

### 列表

- 下列是对 `list-style` 属性的常见属性值的描述：
  - `none`：不使用项目符号
  - `disc`：实心圆
  - `circle`：空心圆
  - `square`：实心方块
  - `decimal`：阿拉伯数字
  - `lower-alpha`：小写英文字母
  - `upper-alpha`：大写英文字母
  - `lower-roman`：小写罗马数字
  - `upper-roman`：大写罗马数字

### 表格

-

### 组合选择与继承

- `div p {xxx}` ，是指以`div`父项的所有**子孙项**`p`的样式都受 xxx 影响
- `div>p {}` ，只有`div`的直接**子项**`p`才算，而孙项的`p`不受影响：`in html： <div><span><p>`
- `div+p{}` ，拥有**共同父项**的`div`和`p`（兄弟项），且`p`位于`div`下的**第一项**，`p`的样式才受影响；这时`div`的**子项**`p`不受影响
- `div~p{}` ，所有与`div`互为兄弟关系的`p`都受样式影响
- 但还有 **属性选择器**：
  - `input[type="text"] {}` ：类型为 input 且是`text`的样式受影响

### 伪类与伪元素

#### 伪类选择器分为两种。

- **伪类**

  - `：link` 超链接点击之前
  - `：visited` 链接被访问过之后
    - 但 `a`标签涵盖了`link`、`visited`的状态
  - `：hover` “悬停”：鼠标放到标签上的时候
  - `：active` “激活”： 鼠标点击标签，但是不松手时。
  - `：focus` 是某个标签获得焦点时的样式（比如某个输入框获得焦点）

- **伪元素**
  - `：first-letter` 选择每个元素的第一个字母
  - `：first-line` 选择每个元素的第一行
  - `：first-child` 选择器匹配属于任意元素的第一个**子元素**
  - `：before` 在每个元素之前插入内容
  - `：after` 在每个元素之后插入内容

### 布局

#### flex

##### 定义

&emsp;&emsp; 只要给`flex`元素的父元素声明 `display： flex` ，默认地所有子元素就会排成一行，且自动分配小大以充分展示元素的内容。所以是，**在父元素定义 `flex`，然后再在子元素再定义下列属性**（参考：[CSS flex 布局](http://www.ruanyifeng.com/blog/2015/07/flex-grammar.html)）

##### 子元素的分布

- **`flex-direction`**：默认为`row` 水平排列，`column`为竖直排列。`wrap`：溢出时自动换行换行。
  - 可以将两个属性 `flex-direction` 和 `flex-wrap` 组合为简写属性 `flex-flow`。第一个指定的值为 `flex-direction` ，第二个指定的值为 `flex-wrap`.
- **`flex-basic`**：设置子元素初始化大小
  - 默认 auto、百分比或具体数
- **`flex-grow`**：设置子项目如何瓜分剩余空间
  - 默认 0、百分比
- （可简写：`flex: grow basic`）

##### 子元素对齐方式

- **`align-items`**： 属性可以使元素在**交叉轴**方向对齐。这个属性的初始值为`stretch`。
  - 可分为：`center`、`flex-start`、`flex-end`、`stretch`(在交叉轴上撑满整个父元素)、`baseline`(基于内容基线)
- **`justify-content`** ： 属性用来使元素在**主轴**方向上对齐，主轴方向是通过`flex-direction` 设置的方向。初始值是`flex-start`。
  - 可分 为：`center`、`flex-start`、`flex-end`、`stretch`、`space-around`(元素之间的距离相等)、`space-between`(元素左右的空间相等、贴边)
- **`align-content`**：当 `flex-wrap：wrap*` 时(即 子元素 换行排列)，控制 子元素 在 cross axis(**交叉轴**)上的对齐方式。
