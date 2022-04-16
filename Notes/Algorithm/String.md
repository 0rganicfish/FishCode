# 数据结构 string

- [首页](Main.md)
- [string 容器详解](https://blog.csdn.net/wzh1378008099/article/details/105687998)

[TOC]

## 语法

### string

1. 函数：

   ```C++ {.line-numbers}
   数字转string     string s = to_string(数字，整数和小数都行);
   string转数字     int a = stoi(s);    double b = stod(s);
   ```

2. 不用写循环遍历的大小写转换：

   ```C++ {.line-numbers}
   transform(str.begin(), str.end(), str1.begin(), ::tolower);
   //要保证 str1的长度 ≥ str的， 所以在转换前加一句：
       str1.resize(s.length());
   ```

3. 不用带转译的纯文本格式

   ```C++ {.line-numbers}
   string s = R"(content)";
   // content 的内容不需用带转译符号
   ```

4. STL 函数

   ```C++ {.line-numbers}
   替换     c.replace(a, b, "xxx")  a：替换的初始位置，b：替换的长度
   查找     b.find(c, a) ：从位置a开始，在b中找c      b.rfind 为从后往前找
       str.find_first_of(str1) ：找第一次出现的位置    找不到就返回 -1
       find 需要子串和父串全部匹配，find_first_of 只需匹配一个字符就可以
   删除     c.erase(a, b)  a：删除的初始位置，b：删除的个数；仅有a的话，则删除位置a后面的字符
   截取     string s = c.substr(a, b);  a：截取的初始位置，b：截取的长度
   插入     c.insert(a, "xxx") a：在位置a之前插入
   翻转顺序  reverse(s.begin() + a, s.end() - b); 指定位置翻转,从a到b
   赋值     str.assign(str1.begin()+1, str1.end()-1); 将区间内str1的元素赋值给 str
   ```

### cctype

- 返回 `bool`

  ```C++ {.line-numbers}
  //只能用在单个字符
  isalnum(c) //-->是否为字母或者数字
  isalpha(c) //-->是否为字母
  isblank(c) //-->是否为空格或者 tab
  isdigit(c) //-->是否为数字
  ispunct(c) //-->是否为符号
  isupper(c) //-->是否为大写字母
  isspace(c) //-->是否为空格
  ```

### sprintf

- ~~不如 `string`~~

  ```C++ {.line-numbers}
  sprintf(ans, "%d+%d=%d", x, y, x + y);// →同时还把 + = 也存进去了
  //所以就有了， 读取数字长度：
  int wei(int x)
  {
    char s[100];
    sprintf(s, "%d", x);
    return strlen(s);
  }
  int len = log(x) / log(10) + 1;
  int len = to_string(x).length();
  ```

### 但在 C++11 之前， 没有 to_string ：

- `#include <sstream>`

  ```C++ {.line-numbers}
  string Itos(int x)  //int Stoi(string x)
  {
      string t; stringstream ss;  // stringstream ss; int t;
      ss << x, ss >> t, ss.clear();   //ss << x, ss >> t, ss.clear();
      return t;
  }
  ```

- 但还可以用模板：

  ```C++ {.line.numbers}
  template <class out_type, class in_value>
  out_type transf(const in_value &t)
  {
      stringstream stream; out_type result;
      stream << t, stream >> result, stream.sync();
      return result;
  }
  //to use:
      string s = transf<string>(x);
      int n = transf<int>(s);
  ```

---

## 别に

### 找连续的“0”的个数

- 跳过连续的“0”

  ```C++ {.line-numbers}
  string s;
  int p, c = 0;
  cin >> s;
  while ((p = s.find('0', p)) != s.npos)
      c++, p = s.find('1', p);
  cout << c;

  //所以还有：
  for (int i = 0; i < n; i++)
      if (x[i] == '0')
      {
          cn++;
          while (x[i] == '0' && i < n) //跳过连续的0
              i++;
      }
  ```

### 去重

- ~~标记重捕法~~/doge

  ```C++ {.line-numbers}
  string uniquee(string c)
  {
      string ch;
      bool s[100] = {false};
      for (int i = 0; i < c.length(); i++)
          if (s[c[i] - ' '] == false)
              ch += c[i], s[c[i] - ' '] = true;
      return ch;
  }
  ```

### 找最长的字符串：

- 不用数组啦

  ```C++ {.line-numbers}
  string s, ans;
  int n, maxn = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      cin >> s;
      if (s.length() > maxn)
          maxn = s.length(), ans = s;
  }
  cout << "The longest is: " << ans;
  ```

### 比较快地输入 string（不含空格）

- 借用了 `char`数组

  ```C++ {.line-numbers}
  const int Max = 1e6 + 5;
  char ctr[Max];
  scanf("%s", ctr);
  string s = string(ctr);
  ```

###
