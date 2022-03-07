<p style="font-size: 40px; color: #fff"><b>JavaScript</b></p>

- [README.md](../../README.md)
- [HTML.note](HTML.md)
  [TOC]

## 基本语法

### 输出

- 使用` window.alert()` 弹出警告框。
- 使用 `document.write()` 方法将内容写到 HTML 文档中。
- 使用 `innerHTML` 写入到 HTML 元素。
- 使用 `console.log()` 写入到浏览器的控制台。

<br>

### 循环迭代

#### for (.. in ..)

用下标遍历对象

```JavaScript {.line-numbers}
let a = ["12", 34, "avb"];
for (var i in a)
  console.log(a[i])
```

<br>

#### for (.. of ..)

直接遍历对象, 甚至生成器函数

```JavaScript {.line-numbers}
let a = ["12", 34, "avb"];
for (var i of a)
  console.log(i);
```

<br>

### 字符串

<br>

### 数组

<br>

### 表达式与运算符

<br>

### 类型转换

- 转为数字：`Number(xx)`, `parseInt(xx, 进制)`, `parseFloat(xx)`
- 转为字符串：`xx.toString()`, `String(xx)`, `xx + ''`
- 转为布尔：`Boolean(xx)`
- 转为对象：`new Number()`...

<br>

### 错误抛出

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

### 对象运算符

<br>

### 函数

#### 箭头函数

箭头函数表达式的语法比函数表达式**更简洁**，并且没有自己的 `this`，`arguments`，`super` 或 `new.target`。箭头函数表达式更适用于那些本来需要匿名函数的地方，并且它不能用作构造函数。

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

#### 自执行函数

> 参考：[浅谈自执行函数（立即调用的函数表达式）](https://www.jianshu.com/p/c64bfbcd34c3)

<br>

#### 方法与函数

```JavaScript {.line-numbers}
(function() {
    statements
})();
```

<br><hr>

## 对象

在 `JavaScript` 中 **万物皆可为对象**

### window 对象

- 在**浏览器**中的全局环境是 `window`

  > 参考：[window 对象](https://www.jianshu.com/p/7c796f4ff810)

<br>

### 对象和属性

#### 创建对象：

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

  对象也可以用 `Object.create()` 方法创建。该方法非常有用，因为它允许你为创建的对象选择一个原型对象，而不用定义构造函数。

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

#### for (.. of ..) 遍历

纯对象是不能用 `for of` 遍历的(`myObj is not iterable`)，需要制定遍历的对象（值或键）

```JavaScript {.line-numbers}
for (var i of Object.values(myObj)) // Object.keys(myObj)
  console.log(i);
```

<br>

#### this

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

## API

### DOM

令见：[DOM API](JavaScript_DOM.md)

#### EventTarget

`EventTarget` 是一个 DOM 接口，由可以接收事件、并且可以创建侦听器的对象实现。`Element`，`document` 和 `window` 是最常见的 event targets

### BOM
