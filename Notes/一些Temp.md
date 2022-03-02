# 只是一些没地方放的 Temp 码

- [README](../README.md)
  [TOC]

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

## JavaScript

### UP 的新动态

```JavaScript {.line-numbers}
var upname = document.getElementsByClassName("user-name"),
  len = upname.length;
console.log("共有", len, "位 up 主更新了动态。分别是：");
for (var i = 0; i < len; ++i) {
  console.log(upname[i].innerText);
}
// 没去重
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

## Python
