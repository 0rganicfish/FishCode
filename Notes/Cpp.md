<p style="font-size: 40px; color: #fff"><b>C / C++</b></p>

- **[README.md](../README.md)**
- **[算 法](Algorithm/Main.md)**

[TOC]

<br><br>

## 一些小语法

### 命名规范

**[编程语言中常用的变量命名缩写](https://blog.csdn.net/qq_37851620/article/details/94731227)**

### 缓冲区

**[C++ cin 详解及清空输入缓冲区](https://blog.csdn.net/selina8921/article/details/79067941)**

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

### 结构体

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

### Class 类

#### 构造类

- 与结构体类似，但是默认是以 `Private` 构造的。偏向 **数据结构** 的是结构体，偏向 **对象** 的是类
- **构造函数**：是指在定义类的时候就运行了。带参数时即给变量赋值。用法：
  ```C++ {.line-numbers}
  class mie
  {
  private:
      int aha;
  public:
      mie(int x) { this->aha = x; }
      mie(int x) : aha(x) {} //或
      void print() { cout << this->aha << endl; }
  };
  // 用法：
  mie m(12); m.print(); // 12
  ```
- **析构函数** 是在删除对象时(或运行结束)时运行，有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
- **拷贝构造函数** 即为在初定义时赋值。与定义后再赋值不同，那时需要 **重载** 等于号才能赋值。

  ```C++ {.line-numbers}
  class mie
  {
  public:
      int num;
      mie(int x) : num(x){};
      mie(const mie &m) { this->num = m.num; }
  };
  // 用：
  mie m(123);  mie mm = m;
  ```

  > Ref：[拷贝构造函数\_知乎](https://zhuanlan.zhihu.com/p/157833251)

- **友元** 加上 `friend` 就可以有权访问 **任何** 成员。且能防止什么都放到 `public` 里，还能节省开支

#### 继承

<br><br>

## C 語言中に

1.  数组长度：

    ```C++ {.line-numbers}
    int len = sizeof(b)/sizeof(int);
    ```

2.  `memset` 批量赋值只能是 `char` 用，`int` 只能给 -1 或 0， 而：

    ```C++ {.line-numbers}
    memset(a, 127, sizeof(a))   //赋值无穷大
    memset(a, 128, sizeof(a))   //赋值无穷小
    ```

3.  `ctime`

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

4.  符号优先级
    <img src="img/cpp_priority.png" width="70%">
