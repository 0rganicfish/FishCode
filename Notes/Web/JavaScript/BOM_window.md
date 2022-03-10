<p style="font-size: 40px; color: #fff"><b>BOM_window对象</b></p>

- [JavaScript.note](JavaScript.md)
  [TOC]

# window 对象

## setTimeout

`setTimeout` 会先将回调函数放到等待队列中，等待区域内其他主程序执行完毕后，按时间顺序先进先出执行回调函数。本质上是作用域的问题。

**定义**：

```JavaScript {.line-numbers}
setTimeout(fun, delay, arg)
// arg 为每次 delay 后传给 fun 的参数
```

**例：**

- 拆分结构

  ```JavaScript {.line-numbers}
  function timer(i) {
      setTimeout( console.log(i), i*1000 );
  }
  for (var i=1; i<=5;i++) {
      timer(i);
  }
  ```

- `let`

  ```JavaScript {.line-numbers}
  for (let i = 1; i <= 5; i++) {
    setTimeout(() => {
      console.log(i);
    }, i * 1000);
  }
  ```

- 带第三参数

  ```JavaScript {.line-numbers}
  for (let i=1; i<=5; i++) {
    setTimeout(function timer() {
        console.log(i);
    }, i*1000, i );
  }
  ```

**返回值：**

`timeoutID`。是一个正整数，表示定时器的编号。这个值可以传递给 `clearTimeout()`来取消该定时器。

**取消定时：**

`clearTimeout(timeoutID)`。该 ID 值为 `setTimeout()` 的返回值


<br>

## 参考

- [window 对象](https://www.jianshu.com/p/7c796f4ff810)
- [图解：window 与 BOM 的关系](https://www.jianshu.com/p/f5409202a835)
