<h1 align="center"><b>ES6</b></h1><br>

[TOC]

- 外链：
  - [阮一峰 ES6](https://es6.ruanyifeng.com)

<br>

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

<br>

## Promise 对象

所谓 `Promise`，简单说就是一个容器，里面保存着某个未来才会结束的事件（通常是一个异步操作）的结果。**也就是** 有了 Promise 对象，就可以将异步操作以**同步**操作的流程表达出来，避免了层层嵌套的回调函数

### 特点

- **对象的状态不受外界影响。** `Promise` 对象代表一个异步操作，有三种状态：`pending`（进行中）、`fulfilled`（已成功）和 `rejected`（已失败）
  &emsp; 只有异步操作的结果可以决定当前是哪一种状态，任何其他操作都无法改变这个状态。这也是 `Promise` 这个名字的由来，它的英语意思就是“承诺”，表示其他手段无法改变
- **一旦状态改变，就不会再变，任何时候都可以得到这个结果。** `Promise` 对象的状态改变，只有两种可能：从 `pending` 变为 `fulfilled` 和从 `pending` 变为 `rejected`。只要这两种情况发生，状态就凝固了，不会再变了，会一直保持这个结果，这时就称为 `resolved`（已定型）
  &emsp; 如果改变已经发生了，你再对 `Promise` 对象添加回调函数，也会立即得到这个结果。这与事件（`Event`）完全不同，事件的特点是，如果你错过了它，再去监听，是得不到结果的

### 用法

- **基本：**
  ```js {.line-numbers}
  function loadXX(url) {
    return new Promise((resolve, reject) => {
      if (/*耗时的异步操作成功*/){
        resolve(value);
      }else{
        reject(err);
      }
    });
  }
  //
  loadXX(url)
    .then((res) => {
      // doing...
    })
    .catch((err) => {
      // doing err...
    });
  ```
- **`then`：** 在 `then` 里的 `return` 将作为下一个 `then` 的参数
- **`catch`：** 处理 `reject` 或是 `Promise` 过程中的异常
- **`race`：** `Promise.race()` 方法同样是将多个 `Promise` 实例组成的**数组**，包装成一个新的 `Promise` 实例
  ```js {.line-numbers}
  const p = Promise.race([p1, p2, p3]);
  ```
  上面代码中，只要 `p1`、`p2`、`p3` 之中有一个的状态变为 `reject` 那就 `catch`。如：
  &emsp;&emsp; 如果 5 秒之内 fetch 方法无法返回结果，变量 getFish 的状态就会变为 rejected，从而触发 catch 方法指定的回调函数：
  ```js {.line-numbers}
  const getFish = Promise.race([
    fetch('/fish.json').then((res) => res.json()),
    new Promise((resolve, reject) => {
      setTimeout(() => reject(new Error('timeout')), 5000);
    }),
  ]);
  //
  getFish.then(console.log).catch(console.error);
  ```
- **`any`：** 与 `race` 不同的是，只有所有的变为 `reject` 才 `catch`

<br>

## 异步 async 函数

`async` 函数返回一个 `Promise` 对象，可以使用 `then` 方法添加回调函数。当函数执行的时候，一旦遇到 `await` 就会先返回，只有 `async` 函数内部的异步操作执行完，才会执行 `then` 方法指定的回调函数。

- **例如：**
  ```js {.line-numbers}
  async function timeout(ms) {
    await new Promise((resolve) => {
      setTimeout(resolve, ms);
    });
  }
  async function asyncPrint(value, ms) {
    await timeout(ms);
    console.log(value);
  }
  asyncPrint('hello world', 500);
  ```
- 在 `async` 里抛出的错误，会被接收的 `catch` 捕获
- **错误处理：** 使用 `try...catch`
  ```js {.line-numbers}
  async function fish() {
    try {
      const ans = await getFish();
    } catch (err) {
      console.error(err);
    }
  }
  ```
- 当要进行多次 `await`，且彼此没有关联，可以同时触发：
  ```js {.line-numbers}
  let [foo, bar] = await Promise.all([getFoo(), getBar()]);
  ```
- 而 `async` 的 **异步性：**
  ```js {.line-numbers}
  (async () => {
    const a = await getApi(1, 2000); //运行后2秒得到a
    const b = await getApi(22, 5000); //在得到a的5秒后才得到b
    setTimeout(() => {
      console.log(a + b); //得到b的1秒后才有a+b
    }, 1000);
  })();
  ```

<br>

## Generator 迭代函数

## Class 类
