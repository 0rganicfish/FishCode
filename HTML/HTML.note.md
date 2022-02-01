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

- `line-height: 1.2;`，行间距，默认 1.2
- `font-weight: 700;`，字重(粗细)，加粗：`bold`，细：`height`
- `font-size: 16px;`，字体大小，默认 16px
- `font-family: "fangsong";`，字体样式
- `text-decoration: none;`，下划线类型
- `text-indent` : 第一行文字缩进长度
- `text-indent` 缩进元素中文本的首行
- `text-shadow` 设置文本阴影
- `text-transform` 控制元素中的字母
- `text-align` , 文字对齐方式
  - `left` ：行内内容向左侧边对齐。
  - `right` ：行内内容向右侧边对齐。
  - `center` ：行内内容居中。
  - `justify` ：文字向两侧对齐，对最后一行无效。
  - `justify-all` ：和 justify 一致，但是强制使最后一行两端对齐。
- `direction` 设置文本方向。
- `letter-spacing` 设置字符间距
- `unicode-bidi` 设置或返回文本是否被重写
- `vertical-align` 设置元素的垂直对齐
- `white-space` 设置元素中空白的处理方式
- `word-spacing` 设置字间距
- `color: #282c34;`，颜色值

### 图片

- `opacity` , 透明度

### 按钮/边框

- `border-radius` , 圆角半径
- `margin` , 外边距
  - 当只指定一个值时，该值会统一应用到**全部四个边**的外边距上。
  - 指定两个值时，第一个值会应用于**上边和下边**的外边距，第二个值应用于**左边和右边**。
  - 指定三个值时，第一个值应用于**上边**，第二个值应用于**右边和左边**，第三个则应用于**下边**的外边距。
  - 指定四个值时，依次（**顺时针方向**）作为上边，右边，下边，和左边的外边距。
  - 也可以单是 `margin-right: `来指定
- `padding` , 内边距
- `height`、`width` , 宽高
-
