<p style="font-size: 35px; color: #fff"><b>只是一些没地方放的 Temp 码</b></p><br>

- [README](../README.md)

[TOC]

<br>

## C++

### 欢迎各位滚动屏的莅临指导

```C++ {.line-numbers}
void welcome()
{
    string cont = "Welcome all leaders to guide us!   ";
    int len = cont.length();
    while (true)
    {
        Sleep(200);
        system("cls");
        cout << cont;
        cont = cont.substr(1, len) + cont[0];
    }
}
```

<br>

## JavaScript

### 隐藏表单的参数

```html {.line-numbers}
<div>
  <form id="fish">
    <label>
      Name: <input type="text" name="name" /><br />
      E-Mail: <input id="email" type="email" name="email" /><br />
    </label>
    <input type="submit" /><br />
  </form>
  <script>
    ;(() => {
      let form = document.getElementById("fish")
      form.action = "fish.php"
      form.method = "post"
    })()
  </script>
</div>
```

### UP 的新动态

```JavaScript {.line-numbers}
var upname = document.getElementsByClassName("bili-dyn-title"),
  up = new Set()

upname.forEach((element) => {
	up.add(element.innerText)
})

console.log("共有", up.size, "位 up 主更新了动态。分别是：")
up.forEach((element) => {
	console.log(element)
})
```

### 时间暂停！

```JavaScript {.line-numbers}
var sleep = function (time) {
  var startTime = new Date().getTime() + parseInt(time, 10);
  while (new Date().getTime() < startTime) {}
};
// 单位：毫秒
```

### 获取 URL 的 ? 参数

```JavaScript {.line-numbers}
function getTab(key) {
    var reg = new RegExp("(^|&)" + key + "=([^&]*)(&|$)");
    var r = location.search.substr(1).match(reg);
    if (r != null)
        return unescape(r[2]);
    return null;
```

<br>

## Python
