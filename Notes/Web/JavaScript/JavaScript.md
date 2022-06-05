 <h1 align="center"><b>JavaScript</b></h1>

- **外链**
  - [README.md](../README.md)
  - [现代 JavaScript 教程](https://zh.javascript.info/)
  - [MDN 官方文档](https://developer.mozilla.org/zh-CN/)
  - [阮一峰 - ES6](https://es6.ruanyifeng.com)
  - [HTML.md](../HTML.md)

[TOC]

<br><hr>

# 基本语法

## 循环迭代

- **for (.. in ..)** 用下标遍历对象

  ```JavaScript {.line-numbers}
  let a = ["12", 34, "avb"];
  for (let i in a)
    console.log(a[i])
  ```

- **for (.. of ..)** 直接遍历对象, 甚至生成器函数

  ```JavaScript {.line-numbers}
  let a = ["12", 34, "avb"];
  for (let i of a)
    console.log(i);
  ```

<br>

## 字符串

- **方法**

  |       方法        | 描述                                                                  |
  | :---------------: | :-------------------------------------------------------------------- |
  |    `charAt()`     | 返回指定位置的字符                                                    |
  |  `charCodeAt()`   | 返回指定位置的字符的 Unicode 编码                                     |
  |    `concat()`     | 字符串拼接, 返回拼接得到的新字符串                                    |
  |     `slice()`     | 提取字符串的片断，并在新的字符串中返回被提取的部分                    |
  |    `substr()`     | 从起始索引号提取字符串中指定数目的字符 (包前不包后)                   |
  |   `substring()`   | 提取字符串中两个指定的索引号之间的字符 (包前不包后)                   |
  |    `indexOf()`    | 返回某个指定的字符串值在字符串中首次出现的位置                        |
  |  `lastIndexOf()`  | 从后向前搜索字符串，并从起始位置（0）开始计算返回字符串最后出现的位置 |
  |  `toLowerCase()`  | 把字符串转换为小写                                                    |
  |  `toUpperCase()`  | 把字符串转换为大写                                                    |
  |     `match()`     | 查找找到一个或多个正则表达式的匹配                                    |
  |    `search()`     | 返回字符串中第一个匹配项的索引,如果没有找到匹配项, 则返回 -1          |
  |    `replace()`    | 在字符串中查找匹配的子串，并替换与正则表达式匹配的子串                |
  |     `split()`     | 把字符串分割为字符串数组 字符串转数组                                 |
  |     `trim()`      | 去除字符串两边的空白                                                  |
  | `localeCompare()` | 比较两个字符串的字符顺序                                              |
  | `formCharCode()`  | 接受一个指定的 Unicode 值，然后返回一个字符串 静态方法                |
  |    `valueOf()`    | 返回某个字符串对象的原始值                                            |

  > 参考：[String 对象方法总结](https://www.jianshu.com/p/1bc145627572)

<br>

## 表达式与运算符

<br>

## 类型转换

- 转为数字：`Number(xx)`, `parseInt(xx, 进制)`, `parseFloat(xx)`
- 转为字符串：`xx.toString()`, `String(xx)`, `xx + ''`
- 转为布尔：`Boolean(xx)`
- 转为对象：`new Number()`...

<br>

## 错误抛出

- 主要还是为了即使出错了也能保证程序的运行

  ```JavaScript {.line-numbers}
  try {
      ...    //异常的抛出
  } catch(e) {
      ...    //异常的捕获与处理
  } finally {
      ...    //结束处理
  }
  ```

<br>

## 函数

### 箭头函数

&emsp;&emsp; 箭头函数表达式的语法比函数表达式**更简洁**，并且没有自己的 `this`，`arguments`，`super` 或 `new.target`，而是指向了 **父作用域**。箭头函数表达式更适用于那些本来需要匿名函数的地方，并且它不能用作构造函数(new)。

**构造：**

- **如**：

  ```JavaScript {.line-numbers}
  let a = ["233", "54f", "23"];

  // 一般写法：
  let l = a.map(function(element) {
    return element.length
  })
  // 箭头函数：
  let l = a.map((len) => len.length);

  console.log(l); //输出 [3, 3, 2]
  ```

- 也能用上**三目运算符**：
  ```JavaScript {.line-numbers}
  let max = (a, b) => a > b ? a : b;
  //调用：
  let maxx = max(12, 33);//当然也有 Math.max();
  ```
- **递归：**
  ```JavaScript {.line-numbers}
  let fact = (x) => (x ? x * fact(x - 1) : 1);
  ```

> ! 箭头函数只适合干简单事啦，尽量不用来定义函数

<br>

### 自执行函数

- 即不用调用就能执行的函数，多为**匿名函数**

  ```JavaScript {.line-numbers}
  (() => {
    console.log("Hello");
  })();
  // 或：
  (function () {
    console.log("Hello");
  })();
  ```

- **结构**
  &emsp;&emsp;先用`( )`将函数主体括起来，末尾再加一个括号表示**给函数的参数传的值**

- **for 循环中的事件**
  &emsp;&emsp; JavaScript 在执行 for 循环语句时，负责给元素安装点击事件，但当用户点击元素触发事件时，for 循环语句早就执行完毕了。所以一般在事件函数中用**自执行函数**

- **如：**

  ```JavaScript {.line-numbers}
  for (let k = 0; k < ele.length; k++) {
    (function (k) {
      ele[k].addEventListener("click", function (e) {
        alert("index is: " + k + ", and this ele is: " + ele[k].innerHTML);
      });
    })(k);
  ```

<br>

> 参考：[浅谈自执行函数（立即调用的函数表达式）](https://www.jianshu.com/p/c64bfbcd34c3)

<br>

### 函数作用域

&emsp;&emsp; 所谓作用域就是：变量在声明它们的函数体以及这个函数体嵌套的任意函数体内都是有定义的。父对象的所有变量，对子对象都是可见的，反之则不成立。

- 在 javascript 中，`if`、`while`、`for` 等代码块不能形成独立的作用域。因此，javascript 中没有块级作用域，**只有函数作用域**。

但是，在 JS 中有一种特殊情况：

- 如果一个变量没有使用 **`var`** 声明，window 便拥有了该属性，因此这个变量的作用域不属于某一个函数体,而是 window 对象(全局)。

  > 即：没有 var 的变量可在函数外调用

<Br>

### call, apply, bind

本质上是 **借用函数**。例：

```JavaScript {.line-numbers}
const mie = {
    name: "mie",
    money: 12,
    getMoney(num) {
      this.money += num;
    },
  },
  fish = {
    name: "fish",
    money: 10,
  };

console.log(fish.money);
mie.getMoney.call(fish, 100);
console.log(fish.money);
```

**即：** `fun.[call | bind | apply](obj, [args])`。区别在于， bind 的参数必须是数组类型，bind 是返回函数但不立即执行

<br><hr>

# 对象

在 `JavaScript` 中 **万物皆可为对象**

## 对象和属性

### 创建对象

- **使用对象初始化器** :

  ```JavaScript {.line-numbers}
  let obj = {
    name: "haha",
    age: 14,
    color: "pink",
  }; // 创建对象,或：
  let oo = new Object();

  obj.like = "Java"; //也能创建后通过赋值来添加或改变值

  console.log(obj.name, "is", obj["age"], "old");
  // haha is 14 old
  ```

  > 有点类似于`json`语法，用点号或`[]`下标访问

- **构造函数来创建对象**

  ```JavaScript {.line-numbers}
  function Car(make, model, year, owner) {
    this.make = make;
    this.model = model;
    this.year = year;
    this.owner = owner;
  }
  function Person(name, age, sex) {
    this.name = name;
    this.age = age;
    this.sex = sex;
  }

  let rand = new Person("Rand McKinnon", 33, "M"),
    car1 = new Car("Eagle", "Talon TSi", 1993, rand);

  console.log(car1.owner.name); // Rand McKinnon
  ```

- **使用 Object.create( ) 方法**

  &emsp;&emsp; 对象也可以用 `Object.create()` 方法创建。该方法非常有用，因为它允许你为创建的对象选择一个原型对象，而不用定义构造函数。

  ```JavaScript {.line-numbers}
  let Animal = {
    type: "Invertebrates", // 属性默认值
    displayType: function () {
      console.log(this.type); // 用于显示type属性的方法
    }, // 对象中套函数
  };
  // 创建一种新的动物——Fishes
  let fish = Object.create(Animal);
  fish.type = "Fishes";
  fish.displayType(); // Output:Fishes
  ```

- **对象长度：**

  ```JavaScript {.line-numbers}
  let len = Object.keys(oo).length;
  ```

<br>

### for 遍历

- 纯对象是不能用 `for of` 遍历的(`myObj is not iterable`)，需要制定遍历的对象（值或键）

  ```JavaScript {.line-numbers}
  for (let i of Object.values(myObj)) // Object.keys(myObj)
    console.log(i);
  //
  for (let [key, val] of Object.entries(fish)) {
    console.log(val);
  }
  //
  Object.entries(fish).forEach(([key, val]) => {
    console.log(val);
  });
  ```

### this

&emsp;&emsp;在 `JavaScript` 中 `this` 不是固定不变的，它会随着执行环境的改变而改变。

- 在**对象方法**中， this 指向调用它所在方法的对象。
- **单独**使用 this，它指向全局(Global)对象。
- **函数**使用中，this 指向函数的所属者。
- **严格模式**下函数是没有绑定到 this 上，这时候 this 是 `undefined`
- 在 **HTML 事件**句柄中，this 指向了接收事件的 HTML 元素。
- apply 和 call 允许切换函数执行的上下文环境（context），即 this 绑定的对象，可以将 this 引用到任何对象。

- **如：**

  ```JavaScript {.line-numbers}
  let f = function () {
    console.log(this.x);
  };
  let x = 1;
  let obj = {
    ff: f,
    x: 2,
  };

  f(); // 单独执行, window 环境 // 1
  obj.ff(); // obj 环境执行  // 2

  ```

<br>

## 标准内置对象

### Array 数组

**函数方法：**

- `arr.splice(pos, len, ...[array])`：增删元素，无返回值
  &emsp;&emsp;在 `pos` 处删除 `len` 长的元素，并插入新元素(可选)
- `arr.slice(start, end)`：数组切片，返回 从 [`start`, `end`) 之间的元素的数组，无参数则复制整个数组
- `array.concat(array | value)` : 合并拼接数组
  ```JavaScript {.line-numbers}
  let num1 = [1, 2, 3],
    num2 = [4, 5, 6],
  let num = num1.concat(num2); // [1, 2, 3, 4 ,5 ,6]
  ```
- `array.join(value)` : 将一个数组（或一个类数组对象）的所有元素连接成一个字符串并返回这个字符串。
  ```JavaScript {.line-numbers}
  let numbers = [4, 2, 5, 1, 3];
  console.log(numbers.join("--"));
  //4--2--5--1--3
  ```
- **搜索：**
  - `arr.indexOf(value, pos)`：从 pos 开始搜索 value，找到则返回下标
  - `arr.includes(value | pos)` : 从`pos`开始判断一个数组是否包含一个指定的值，如果包含则返回 `true`，否则返回 `false`。
  - `arr.find(function(item, index, arr))`：
    找到时返回 `item`，否则返回 `undefined`
    ```JavaScript {.line-numbers}
    let users = [
      {id: 1, name: "John"},
      {id: 2, name: "Pete"},
      {id: 3, name: "Mary"}
    ];
    let user = users.find(item => item.id == 1);
    user.name // -> John
    ```
  - `arr.filter(function(item, index, arr))`：
    过滤器，返回符合条件的数组
    ```JavaScript {.line-numbers}
    let arr = [1, 2, 3, 4];
    let ans = arr.filter((item)=>{
        return item % 2;
    });
    ans //->[1 3]
    ```
- `array.pop()`、 `array.push()`：队尾增删
- `arr.shift()`、`arr.unshift()`：队首增删
- `array.sort(fun)` : 默认地按 **字符串** 的方式来排序

  ```JavaScript {.line-numbers}
  let numbers = [4, 2, 5, 1, 3];
  numbers.sort((a, b) => a - b);//所以排数字时要定义排序的函数
  numbers //-> [1 2 3 4 5]

  //也能是排序数组中的对象
  items.sort(function (a, b) {
    return (a.value - b.value)
  });
  ```

- **遍历数组：** 方法的**参数**都一样： `arr.fun(function(item, index, arr))` ：当前值、值的下标、数组本身

  - `forEach` :
    无返回值，通常只用于 只调用数组数据的情况
    ```JavaScript {.line-numbers}
    let a = [1, 2, 3];
    a.forEach((i) => {
      console.log(i);
    });
    // 1 2 3
    ```
  - `map`：
    处理器，返回处理后的新数组
    ```JavaScript {.line-numbers}
    let arr = [1, 2, 3, 4];
    let ans = arr.map((item)=>{
        return item * 2;
    });
    ans //-> [2 4 6 8]
    ```
  - `reduce`：
    归并器，多带一个参数：`arr.reduce(function(prev, curr, index, arr))`

>

- **等概率的随机洗牌：**
  ```JavaScript {.line-numbers}
  function shuffle(array) {
    for (let i = array.length - 1; i > 0; i--) {
      let j = Math.floor(Math.random() * (i + 1));
      [array[i], array[j]] = [array[j], array[i]];
    }
  }
  ```

> 参考：[MDN Array](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array#%E6%8F%8F%E8%BF%B0) 、 [数组方法](https://zh.javascript.info/array-methods)

<br>

### Date 对象

- **属性**

  ```JavaScript {.line-numbers}
  let date = new Date(year | monthIndex | day | hours | minutes | seconds);
  // 参数可选，否则返回当前的本地时间
  date.method();
  ```

- **函数方法**

  |        方法         | 描述                                        |
  | :-----------------: | :------------------------------------------ |
  |     `getDate()`     | 从 Date 对象返回一个月中的某一天 (1 ~ 31)。 |
  |     `getDay()`      | 从 Date 对象返回一周中的某一天 (0 ~ 6)。    |
  |   `getFullYear()`   | 从 Date 对象以四位数字返回年份。            |
  |    `getHours()`     | 返回 Date 对象的小时 (0 ~ 23)。             |
  | `getMilliseconds()` | 返回 Date 对象的毫秒(0 ~ 999)。             |
  |   `getMinutes()`    | 返回 Date 对象的分钟 (0 ~ 59)。             |
  |    `getMonth()`     | 从 Date 对象返回月份 (0 ~ 11)。             |
  |   `getSeconds()`    | 返回 Date 对象的秒数 (0 ~ 59)。             |
  |     `getTime()`     | 返回 1970 年 1 月 1 日至今的毫秒数。        |

  > 设置则将 get 改为 set ，时间前加上 UTC 代表 UTC 时

<br>

### Math 对象

Math 是一个内置对象，它拥有一些数学常数属性和数学函数方法。

- **属性**

  - `Math.E` : 欧拉常数，也是自然对数的底数，约等于 2.718。
  - `Math.LN2` ： 2 的自然对数，约等于 0.693。
  - `Math.PI` : 圆周率，约等于 3.14159。

- **函数方法**

  - `Math.floor(x)`: 返回 x 的向下取整后的值
  - `Math.hypot(x, y,..)`: 返回参数的平方和的平方根
  - `Math.random()` : 返回 0 到 1 内的随机数
    - 0 到最大值的随机数：
      ```JavaScript {.line-numbers}
      function getRandomInt(max) {
        return Math.floor(Math.random() * max);
      }
      ```
    - 包含范围在内的随机数：
      ```JavaScript {.line-numbers}
      function getRandomIntInclusive(min, max) {
      min = Math.ceil(min);
      max = Math.floor(max);
      return Math.floor(Math.random() * (max - min + 1)) + min; //含最大值，含最小值
      }
      ```
  - `Math.round(x)` : 返回 x 四舍五入后的值
  - `Math.trunc(x)` : 返回 x 的整数部分

<br>

### Map 对象

- **定义**

  &emsp;&emsp;一个 Map 的键可以是任意值，包括函数、对象或任意基本类型。且 Map 中的 key 是有序的。因此当迭代的时候以插入的顺序返回键值。

- **属性**

  ```JavaScript {.line-numbers}
  let mpa = new Map();
  mpa.set("key", "value");
  mpa.set("name", "haha");
  mpa.set("age", 14);
  console.log(mpa.size); // 3
  ```

- **遍历**

  ```JavaScript {.line-numbers}
  for (let [i, j] of mpa)
  console.log(i, ":", j);

  for (let key of mpa.keys())
  console.log(key);

  mpa.forEach((value, key) => {
    console.log(key, ":", value);
  });
  ```

- **方法**
  - `mpa.clear()` : 清除所有元素
  - `mpa.delete(key)` : 删除 key 并返回 bool 值
  - `mpa.has(key)` : 返回 bool 值
  - `mpa.get(key)` : 返回 key 下的 value
  - `mpa.entries()` : 返回一个新的包含 `[key, value]` 对的 `Iterator` 对象，返回的迭代器的迭代顺序与 Map 对象的**插入顺序**相同。

<br>

### Set 对象

- **定义**
  &emsp;&emsp;Set 对象是值的集合，你可以按照插入的顺序迭代它的元素。 Set 中的元素只会出现一次，即 Set 中的元素是唯一的。

- **属性**

  ```JavaScript {.line-numbers}
  let mySet = new Set();
  mySet.add(1); // Set [ 1 ]
  mySet.add(5); // Set [ 1, 5 ]
  mySet.add(5); // Set [ 1, 5 ]
  mySet.add("some text"); // Set [ 1, 5, "some text" ]
  ```

- **方法**
  - `set.add(value)` : 添加值
  - 其他的和 map 类似

<br>

### 正则表达式

-

> Ref: [MDN 中的正则](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/RegExp)

<br>

## 迭代器 iterator

&emsp;&emsp;所有的迭代器对象都有一个 `next()` 方法，每次调用都返回一个结果对象。结果对象有两个属性：一个是 **`value`**，表示下一个将要返回的值；另一个是 **`done`**，它是一个布尔类型的值，当没有更多可返回数据时返回 true。

- **可被迭代的对象**
  &emsp;&emsp; 目前所有的内置可迭代对象如下：String、Array、TypedArray、Map 、 Set 和 NodeList 对象

<br>

## arguments 对象

是一个对应于传递给函数的参数的**类数组**对象。

- **如：**

  ```JavaScript {.line-numbers}
  function add() {
    let sum = 0,
      len = arguments.length;
    for (let i = 0; i < len; i++) {
      sum += arguments[i];
    }
    return sum;
  }
  add(); // 0
  add(1); // 1
  add(1, 2, 3, 4); // 10
  ```

  > 其实就是将函数传入的参数列到 `arguments` 数组中，但又不同于 `Array`

<br>

# ES6

## 变量的解构赋值

- **数组：**
  只要位置、嵌套方式匹配即可，没有值则是 undefined

  ```JavaScript {.line-numbers}
  // 从
  const a = 1, b = 2, c = 3;
  // 变成
  const [a, b, c] = [1, 2, 3];

  const [a, ...arr] = [1, 2, 3, 4]
  // a -> 1; arr -> [2, 3, 4]
  ```

- **对象：**
  必须要同名才行

```JavaScript {.line-numbers}
const mie = {id: 233, name:"mie"},
   {id, name} = mie,
   {id: uid, name: uname} = mie, //别名
   {sin} = Math;
```

所以交换就成了：`[a b] = [b, a];`

<br><hr>

# API

## DOM

&emsp;&emsp;文档对象模型（DOM）是用来表达 HTML、XHTML 及 XML 文档中的对象或与其进行交互的约定，它是跨平台的，并且与编程语言无关。通过调用 DOM 树上对象的方法可以操纵这些对象。

**详见：** [DOM](DOM.md)

<br>

## BOM

&emsp;&emsp; **BOM**：**Browser Object Model** 是浏览器对象模型，浏览器对象模型提供了独立与内容的、可以与浏览器窗口进行互动的对象结构。 BOM 由多个对象构成，其中代表浏览器窗口的 window 对象是 BOM 的顶层对象，其他对象都是该对象的子对象。

<br>

### window 对象

&emsp;&emsp; 浏览器里面，window 对象指当前的浏览器窗口。它也是当前页面的**顶层对象**，即最高一层的对象，所有其他对象都是它的下属。一个变量如果未声明，那么默认就是顶层对象的属性。

**详见：**[BOM window](BOM_window.md)

<br>

## 浏览器事件

&emsp;&emsp; **事件** 是某事发生的信号。所有的 DOM 节点都生成这样的信号（但事件不仅限于 DOM）。
&emsp;&emsp; 为了对事件作出响应，我们可以分配一个 处理程序（handler）—— 一个在事件发生时运行的**函数**。
&emsp;&emsp; 处理程序是在发生用户行为（action）时运行 JavaScript 代码的一种方式。

**详见：**[Evens.md](Evens.md)

## 第三方 API
