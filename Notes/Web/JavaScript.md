<p style="font-size: 40px; color: #fff"><b>JavaScript</b></p>

- [README.md](../../README.md)
- [HTML.note](HTML.md)
- [BOM window 对象](JavaScript_BOM_window.md)
- [DOM API](JavaScript_DOM.md)
  [TOC]

# 基本语法

## 输出

- 使用` window.alert()` 弹出警告框。
- 使用 `document.write()` 方法将内容写到 HTML 文档中。
- 使用 `innerHTML` 写入到 HTML 元素。
- 使用 `console.log()` 写入到浏览器的控制台。

<br>

## 循环迭代

### for (.. in ..)

用下标遍历对象

```JavaScript {.line-numbers}
let a = ["12", 34, "avb"];
for (var i in a)
  console.log(a[i])
```

### for (.. of ..)

直接遍历对象, 甚至生成器函数

```JavaScript {.line-numbers}
let a = ["12", 34, "avb"];
for (var i of a)
  console.log(i);
```

<br>

## 字符串

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

## Array 数组

### 函数方法

- `array.concat(array | value)` : 合并拼接数组

  ```JavaScript {.line-numbers}
  var num1 = [1, 2, 3],
    num2 = [4, 5, 6],
  var num = num1.concat(num2); // [1, 2, 3, 4 ,5 ,6]
  ```

- `array.forEach(fun)` : 遍历数组

  ```JavaScript {.line-numbers}
  var a = [1, 2, 3];
  a.forEach((i) => {
    console.log(i);
  });
  // fun 多用箭头或匿名函数
  ```

- `array.join(value)` : 将一个数组（或一个类数组对象）的所有元素连接成一个字符串并返回这个字符串。

  ```JavaScript {.line-numbers}
  var numbers = [4, 2, 5, 1, 3];
  console.log(numbers.join("--"));
  //4--2--5--1--3
  ```

- `array.includes(value | index)` : 从`index`开始判断一个数组是否包含一个指定的值，如果包含则返回 true，否则返回 false。
- `array.pop()`, `array.push()` : 队尾增删

- `array.sort(fun)` : 排序

  ```JavaScript {.line-numbers}
  var numbers = [4, 2, 5, 1, 3];
  numbers.sort((a, b) => a - b);
  console.log(numbers);
  //也能是排序数组中的对象
  items.sort(function (a, b) {
    return (a.value - b.value)
  });
  ```

> 参考：[MDN Array](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array#%E6%8F%8F%E8%BF%B0)

<br>

## 表达式与运算符

### 对象运算符

<br>

## 类型转换

- 转为数字：`Number(xx)`, `parseInt(xx, 进制)`, `parseFloat(xx)`
- 转为字符串：`xx.toString()`, `String(xx)`, `xx + ''`
- 转为布尔：`Boolean(xx)`
- 转为对象：`new Number()`...

<br>

## 错误抛出

主要还是为了即使出错了也能保证程序的运行

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

&emsp;&emsp; 箭头函数表达式的语法比函数表达式**更简洁**，并且没有自己的 `this`，`arguments`，`super` 或 `new.target`。箭头函数表达式更适用于那些本来需要匿名函数的地方，并且它不能用作构造函数。

**构造：**

- **如**：

  ```JavaScript {.line-numbers}
  var a = ["233", "54f", "23"];

  // 一般写法：
  var l = a.map(function(element) {
    return element.length
  })
  // 箭头函数：
  var l = a.map((len) => len.length);

  console.log(l); //输出 [3, 3, 2]
  ```

- 也能用上**三目运算符**：

  ```JavaScript {.line-numbers}
  let max = (a, b) => a > b ? a : b;
  //调用：
  var maxx = max(12, 33);//当然也有 Math.max();
  ```

- **递归：**

  ```JavaScript {.line-numbers}
  var fact = (x) => (x ? x * fact(x - 1) : 1);
  ```

- **而且**：箭头函数没有局部 `this` 的绑定

  和一般的函数不同，箭头函数不会绑定 this。 或者说箭头函数不会改变 this 本来的绑定。

<br>

### 自执行函数

即不用调用就能执行的函数，多为**匿名函数**

```JavaScript {.line-numbers}
(() => {
  console.log("Hello");
})();
// 或：
(function () {
  console.log("Hello");
})();
```

**结构**：先用`( )`将函数主体括起来，末尾再加一个括号表示**给函数的参数传的值**

**for 循环中的事件**
&emsp;&emsp; JavaScript 在执行 for 循环语句时，负责给元素安装点击事件，但当用户点击元素触发事件时，for 循环语句早就执行完毕了。所以一般在事件函数中用**自执行函数**

- 如：

  ```JavaScript {.line-numbers}
  for (var k = 0; k < ele.length; k++) {
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

### arguments 对象

是一个对应于传递给函数的参数的**类数组**对象。

**如：**

```JavaScript {.line-numbers}
function add() {
  var sum = 0,
    len = arguments.length;
  for (var i = 0; i < len; i++) {
    sum += arguments[i];
  }
  return sum;
}
add(); // 0
add(1); // 1
add(1, 2, 3, 4); // 10
```

> 其实就是将函数传入的参数列到 `arguments` 数组中，但又不同于 `Array`

<br><hr>

# 对象

在 `JavaScript` 中 **万物皆可为对象**

## 对象和属性

### 创建对象

- **使用对象初始化器** :

  ```JavaScript {.line-numbers}
  var obj = {
    name: "haha",
    age: 14,
    color: "pink",
  }; // 创建对象,或：
  var oo = new Object();

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

  var rand = new Person("Rand McKinnon", 33, "M"),
    car1 = new Car("Eagle", "Talon TSi", 1993, rand);

  console.log(car1.owner.name); // Rand McKinnon
  ```

- **使用 Object.create( ) 方法**

  &emsp;&emsp; 对象也可以用 `Object.create()` 方法创建。该方法非常有用，因为它允许你为创建的对象选择一个原型对象，而不用定义构造函数。

  ```JavaScript {.line-numbers}
  var Animal = {
    type: "Invertebrates", // 属性默认值
    displayType: function () {
      console.log(this.type); // 用于显示type属性的方法
    }, // 对象中套函数
  };
  // 创建一种新的动物——Fishes
  var fish = Object.create(Animal);
  fish.type = "Fishes";
  fish.displayType(); // Output:Fishes
  ```

<br>

### for (.. of ..) 遍历

&emsp;&emsp; 纯对象是不能用 `for of` 遍历的(`myObj is not iterable`)，需要制定遍历的对象（值或键）

```JavaScript {.line-numbers}
for (var i of Object.values(myObj)) // Object.keys(myObj)
  console.log(i);
```

<br>

### this

```JavaScript {.line-numbers}
var f = function () {
  console.log(this.x);
};
var x = 1;
var obj = {
  ff: f,
  x: 2,
};

f(); // 单独执行, window 环境 // 1
obj.ff(); // obj 环境执行  // 2

```

<br><hr>

# API

## DOM

令见：[DOM API](JavaScript_DOM.md)

<br><hr>

## BOM

&emsp;&emsp; **BOM**：**Browser Object Model** 是浏览器对象模型，浏览器对象模型提供了独立与内容的、可以与浏览器窗口进行互动的对象结构。

&emsp;&emsp; BOM 由多个对象构成，其中代表浏览器窗口的 window 对象是 BOM 的顶层对象，其他对象都是该对象的子对象。

<br>

### window 对象

&emsp;&emsp; 浏览器里面，window 对象指当前的浏览器窗口。它也是当前页面的**顶层对象**，即最高一层的对象，所有其他对象都是它的下属。一个变量如果未声明，那么默认就是顶层对象的属性。

详见：[window 对象](JavaScript_BOM_window.md)
