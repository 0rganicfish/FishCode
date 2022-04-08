<p style="font-size: 40px; color: #fff"><b>C / C++</b></p>

- **[README.md](../README.md)**
- **[数据结构]()**
  - **[String](cpp.note/String.md)**
  - **[STL](cpp.note/STL.md)**
  - **[树、图](cpp.note/Tree-Graph.md)**
- **[排序](cpp.note/Sort.md)**
- **[数学](cpp.note/Math.md)**
- **[搜索](cpp.note/Search.md)**
- **[动态规划 DP](cpp.note/DP.md)**
- **[喵啊](cpp.note/miao.md)**

---

[TOC]

<br><br>

## 一些算法、语法

### 命名规范

**[编程语言中常用的变量命名缩写](https://blog.csdn.net/qq_37851620/article/details/94731227)**

### 缓冲区

**[C++ cin 详解及清空输入缓冲区](https://blog.csdn.net/selina8921/article/details/79067941)**

### 快读快写：

```C++ {.line-numbers}
template <typename T>
void write(T n)
{
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
template <typename T>
void read(T &x)
{
    x = 0; T f = 1; char c;
    while ((c = getchar()) and !isdigit(c))
        if (c == '-') f = -1;
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    x *= f;
}
```

### 头模板

```C++ {.line-numbers}
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;
```

### stringstream

- **[C++ stringstream 介绍](https://www.cnblogs.com/wuchanming/p/3906176.html)**

- `getline` 与 `ss`
  ```C++ {.line-numbers}
      string s; int m; map<string, int> guo;
      getline(cin, s);
      stringstream ss;
      ss << s;
      while (ss >> s >> m)
          guo[s] += m;
  ```

### 模板 template

- **[C++模板 template 用法总结](https://blog.csdn.net/qq_35637562/article/details/55194097)**

  ```C++ {.line-numbers}
  template <class T>  //单个类型
  T big(T x, T y)
  {
      return x > y ? x : y;
  }
  template <class T1, class T2>  //不同类型
  inline const T2 Max(const T1 a, const T2 b)
  {
      return a > b ? a : b;
  }
  ```

  ```C++ {.line-numbers}
  template <class out_type, class in_value>
  out_type transf(const in_value &t)
  {
    stringstream stream; out_type result;
    stream << t, stream >> result, stream.sync();
    return result;
  }
  int main()
  {
    string s = "532";
    double t = transf<double>(s); // <>里的是要转换的类型名，()里的是被转换的变量名
  }
  ```

### 复杂度

复杂度限制：

- 在函数(非递归)中，一维数组大小不超过 1e5.
- 在全局变量中，一维数组大小不超过 1e8，二维数组大小不超过 1e4
- 对于 1s 的时间限制，需要保证程序的所有语句的总执行次数不超过 1e8.
  <img src="img/cpp_1.png" width="70%">

一般 ACM 或者笔试题的时间限制是 1 秒或 2 秒。
在这种情况下，C++代码中的操作次数控制在 $10^7∼10^8$ 为最佳。

下面给出在不同数据范围下，代码的时间复杂度和算法该如何选择：

- $n \le 30$, 指数级别, dfs+剪枝，状态压缩 dp
- $n \le 100  \to  O(n^3)$，floyd，dp，高斯消元
- $n \le 1000  \to  O(n^2), O(n^2logn)$ ，dp，二分，朴素版 Dijkstra、朴素版 Prim、Bellman-Ford
- $n \le 10^4  \to  O(n \times \sqrt n)$，块状链表、分块、莫队
- $n \le 10^5  \to  O(nlogn)$ $\to$ 各种 sort，线段树、树状数组、set/map、heap、拓扑排序、dijkstra+heap、prim+heap、Kruskal、spfa、求凸包、求半平面交、二分、CDQ 分治、整体二分、后缀数组、树链剖分、动态树
- $n \le 10^6  \to  O(n)$, 以及常数较小的 $O(nlogn)$ 算法 $ \to $ 单调队列、 hash、双指针扫描、并查集，kmp、AC 自动机，常数比较小的 $O(nlogn)$ 的做法：sort、树状数组、heap、dijkstra、spfa
- $n \le 10^7  \to  O(n)$，双指针扫描、kmp、AC 自动机、线性筛素数
- $n \le 10^9  \to  O(\sqrt n)$，判断质数
- $n \le 10^{18}  \to  O(logn)$，最大公约数，快速幂，数位 DP
- $n \le 10^{1000}  \to  O((logn)^2)$，高精度加减乘除
- $n \le 10^{100000}  \to  O(logk \times loglogk)$，k 表示位数，高精度加减、FFT/NTT
-

### 结构体

- 结构体数组：用一维数组**代替**多维数组

  ```C++ {.line-numbers}
  struct pan
  {
      double x, y, z;   //相当于定义了一个三维数组
  } a[51];

  for (i = 0; i < n; i++)
          cin >> a[i].x >> a[i].y >> a[i].z;  //输入

  bool cmp(pan x, pan y){
      return x.z < y.z;    //以pan中的z小到大排序
  }
  sort(a , a + n, cmp);    //排序, cmp：排序规则
  ```

- 初始化结构体：

  ```C++ {.line-numbers}
  struct node
  {
    ll a, b, c;
    node()
    {
      memset(this, 0, sizeof(node));
    }
  };
  ```

### 前缀和 / 区间和

- 一维：
  ```C++ {.line-numbers}
  for (i = 1; i <= n; i++){
          cin >> a[i];
          sum[i] = sum[i - 1] + a[i];
      }
  ```
- 差分：如给数组 `[l, r]` 之间加上 c

  ```C++{.line-numbers}
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
      scanf("%d", &a[i]);
      b[i] = a[i] - a[i - 1]; //构建差分数组
  }
  int l, r, c;
  while (m--)
  {
      scanf("%d%d%d", &l, &r, &c);
      b[l] += c, b[r + 1] -= c;
  }
  for (int i = 1; i <= n; i++)
  {
      b[i] += b[i - 1]; //求前缀和运算
      printf("%d ", b[i]);
  }
  ```

- 二维：

  - 求表
    <img src="img/cpp_2.png" width="70%">

    ```C++ {.line-numbers}
    for (i = 1; i <= n; i++)  //打表
            for (j = 1; j <= m; j++) {
                cin >> mpa[i][j];
                sum[i][j] = mpa[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
    ```

  - 还原：
    <img src="img/cpp_3.png" width="70%">

    ```C++ {.line-numbers}
    cin >> x1 >> y1 >> x2 >> y2;   //求表
    cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    ```

<br>

---

<br>

## 嘈杂的

1.  `long long`: 9e19, `unsigned long long` : 1e21

2.  `scanf("%4d%4d",&a,&b);`输入 12345678 将把 1234 赋予 a，而把 5678 赋予 b

3.  数组长度：

    ```C++ {.line-numbers}
    int len = sizeof(b)/sizeof(int);
    ```

4.  让循环里的 if 只判断一次：

    ```C++ {.line-numbers}
    bool f = 1;
    for( ... )
      if (xxx && f)
        xxx, f = 0;
    ```

5.  随机数生成 `int num = rand() % 50 + 1; //产生一个1-50之间的数` 带 `<stdlib.h>`头

6.  `const void *a` 因此，void \* 类型指针，这个类型指针指向了实实在在的存放数据的地址，但是该地址存放的数据的 **数据类型** 我们暂时不知道。

7.  **`double`** 的位数高达 **`-1.79E+308 ~ +1.79E+308`**

8.  二维数组作图的边界问题

    ```C++ {.line-numbers}
    //像是轰炸范围:
    //            起始位置              末位置（边界）
    //               ↓                     ↓
    for (i = max(y1 - f, 0); i <= min(y1 + f, y); i++)
                for (j = max(x1 - f, 0); j <= min(x1 + f, x); j++)
    ```

9.  与其用 else if 一个个地判断，还不如用数组来打表 / 枚举

    ```C++ {.line-numbers}
    像是 int day[] = {31,28,31,30,31,30,31,31,30,31,30,31);
    void函数 →  if(是闰年)  day[1] = 29;
    ```

10. 知道递推公式，f (n) = f ( n+1 ) + f ( n+2 )，可以直接套 —> 不是模拟，可以暴力但爆，手动推一下递推公式

    ```C++ {.line-numbers}
    for (int i = 0; i <= size; i++)    //↑也就是说，只注重结果而不是过程
        {
            if (i > 1)
                arr[i] = arr[i - 2] + arr[i - 1]; //递推算法
            printf("factorial[%d]=%d\n", i, arr[i]);
        }
    ```

11. C++11 `for` 的新特性：

    ```C++ {.line-numbers}
    int a[10] = {0};
    for (int &c : a)   //要改变值时要加 & ，不然只是 只读 模式
        c++;
    for (int i : a)
        cout << a[i] << " ";

    string s;
    for (char c : s)
        cout << c;
    ```

12. 梯形数字： 要想一下，多个 for 循环是 **嵌套关系** 还是 **并列关系**

    ```C++ {.line-numbers}
    for (t = 1, j = 1; j <= n; j++)           //         01
        {                                     //       0203
            for (k = 0; k < n - j; k++)       //     040506
                printf("  ");                 //   07080910
            for (; k < n; k++, t++)
                printf("%02d", t);
            printf("\n");
        }
    ```

13. 否命题原理 ：**`if (c != 'a' && c != 'b')`** 两个不等于用 and，等于用 or

14. 相同情况循环了 n 次的周期，那只要将结果乘以 n 再加上周期以外的就行

15. 定义无穷大：`int a = INT_MAX;`

16. 找最大值不一定要排序数组，用一下比较

    ```C++ {.line-numbers}
    int maxx = INT_MIN;
    for(...)
    {
        ...
        maxx = max(maxx, a[i]);
    }
    // 或者直接
    maxx = *max_element(a, a + n); // STL
    ```

17. 让函数 return 数组：

    ```C++ {.line-numbers}
    int *xxx(int a[])
    {
        ......
        return a;
    }
    int main()
    {
        int a[10];
        int *b = xxx(a);
    // -->指针也就是数组
    }
    ```

18. `memset` 批量赋值只能是 `char` 用，`int` 只能给 -1 或 0， 而：

    ```C++ {.line-numbers}
    memset(a, 127, sizeof(a))   //赋值无穷大
    memset(a, 128, sizeof(a))   //赋值无穷小
    ```

19. `ctime`

    - 时间戳获取与转换

      ```C++ {.line-numbers}
      time_t t = time(0);
      // cin >> t; //当然，也能输入时间戳（秒）
      char tmp[32] = {}, form[] = "%Y-%m-%d %H:%M:%S";
      strftime(tmp, sizeof(tmp), form, localtime(&t));
      cout << tmp << endl;
      ```

    - 当前时间
      ```C++ {.line-numbers}
          time_t t = time(&t);
          string s = ctime(&t);
          cout << s << endl;
      ```

20. 符号优先级

<table><caption>C++运算符优先级表</caption><tbody><tr><th>优先级</th><th>运算符</th><th>说明</th><th>结合性</th></tr><tr><td>1</td><td>::</td><td>范围解析</td><td rowspan="6">自左向右</td></tr><tr><td rowspan="5">2</td><td>++&nbsp;&nbsp;--</td><td>后缀自增/后缀自减</td></tr><tr><td>()</td><td>括号</td></tr><tr><td>[]</td><td>数组下标</td></tr><tr><td>.</td><td>成员选择（对象）</td></tr><tr><td>?&gt;</td><td>成员选择（指针）</td></tr><tr><td rowspan="9">3</td><td>++&nbsp;&nbsp;--</td><td>前缀自增/前缀自减</td><td rowspan="9">自右向左</td></tr><tr><td>+&nbsp;&nbsp;?</td><td>加/减</td></tr><tr><td>!&nbsp;&nbsp;~</td><td>逻辑非/按位取反</td></tr><tr><td>(type)</td><td>强制类型转换</td></tr><tr><td>*</td><td>取指针指向的值</td></tr><tr><td>&amp;</td><td>某某的地址</td></tr><tr><td>sizeof</td><td>某某的大小</td></tr><tr><td>new,new[]</td><td>动态内存分配/动态数组内存分配</td></tr><tr><td>delete,delete[]</td><td>动态内存释放/动态数组内存释放</td></tr><tr><td>4</td><td>.*&nbsp;&nbsp;-&gt;*</td><td>成员对象选择/成员指针选择</td><td rowspan="12">自左向右</td></tr><tr><td>5</td><td>*&nbsp;&nbsp;/&nbsp;&nbsp; %</td><td>乘法/除法/取余</td></tr><tr><td>6</td><td>+&nbsp;&nbsp;?</td><td>加号/减号</td></tr><tr><td>7</td><td>&lt;&lt;&nbsp;&nbsp;&gt;&gt;</td><td>位左移/位右移</td></tr><tr><td rowspan="2">8</td><td>&lt;&nbsp;&nbsp;&lt;=</td><td>小于/小于等于</td></tr><tr><td>&gt;&nbsp;&nbsp;&gt;=</td><td>大于/大于等于</td></tr><tr><td>9</td><td>==&nbsp;&nbsp;!=</td><td>等于/不等于</td></tr><tr><td>10</td><td>&amp;</td><td>按位与</td></tr><tr><td>11</td><td>^</td><td>按位异或</td></tr><tr><td>12</td><td>|</td><td>按位或</td></tr><tr><td>13</td><td>&amp;&amp;</td><td>与运算</td></tr><tr><td>14</td><td>||</td><td>或运算</td></tr><tr><td>15</td><td>?:</td><td>三目运算符</td><td rowspan="7">自右向左</td></tr><tr><td rowspan="5">16</td><td>=</td><td>赋值</td></tr><tr><td>+=&nbsp;&nbsp;?=</td><td>相加后赋值/相减后赋值</td></tr><tr><td>*=&nbsp;&nbsp;/=&nbsp;&nbsp; %=</td><td>相乘后赋值/相除后赋值/取余后赋值</td></tr><tr><td>&lt;&lt;=&nbsp;&nbsp;&gt;&gt;=</td><td>位左移赋值/位右移赋值</td></tr><tr><td>&amp;=&nbsp;&nbsp;^=&nbsp;&nbsp;|=</td><td>位与运算后赋值/位异或运算后赋值/位或运算后赋值</td></tr><tr><td>17</td><td>throw</td><td>抛出异常</td></tr><tr><td>18</td><td>,</td><td>逗号</td><td>自左向右</td></tr></tbody></table><br>

21. 1
