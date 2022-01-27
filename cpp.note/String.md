# C++ string

[首页](main.md)

_[**string 容器详解**](https://blog.csdn.net/wzh1378008099/article/details/105687998)_

1. **↑** 也就是说， string 也能用 STL 里的 pop，push 和迭代器 `—>`把 string 理解为 vector 的动态数组就好

2. `string c = " asdd " ;` 相当于 `char c[ ] = " asdd " ;`

3. 回车结束输入字符

   ```C++ {.line-numbers}
   char b[100];  或者是 string b;
   scanf("%s",&b);     cin >> b;
   for (int i = 0; b[i] != '\0'; i++) //i < b.length()
   ...对b的处理
   ```

4. **C++中读取** **`string`** **对象**

   1.标准输入读取：`cin << string`

   - 忽略开头所有的空白字符（空格、换行、制表符等）；
   - 读取字符直至再次遇到**空白字符**，读取终止；

     2.读取整行文本：`getline(cin, string)`

   - 不忽略开头的空白字符；
   - 读取字符直至遇到**换行符**，如果第一个字符是换行符，则返回空 string；

   —>也就是说，先`cin >> n;`再 `getline (cin, s);` 会导致直接跳过输入 s ，所以应该在输入 s 之前加一句`getchar()`；

5. **`<string>`** 头文件函数

   ```C++ {.line-numbers}
   数字转string     string s = to_string(数字，整数和小数都行);
   string转数字     int a = stoi(s);    double b = stod(s);
   ```

   ```C++ {.line-numbers}
   不用写循环遍历的大小写转换：
   transform(str.begin(), str.end(), str1.begin(), ::tolower);
   要保证 str1的长度 ≥ str的， 所以在转换前加一句：str1.resize(s.length());
   ```

   ```C++ {.line-numbers}
   1. 替换     c.replace(a, b, "xxx")  a：替换的初始位置，b：替换的长度
   2. 查找     b.find(c, a) ：从位置a开始，在b中找c      b.rfind 为从后往前找
          str.find_first_of(str1) ：找第一次出现的位置    找不到就返回 -1
          find 需要子串和父串全部匹配，find_first_of 只需匹配一个字符就可以
   3. 删除     c.erase(a, b)  a：删除的初始位置，b：删除的个数；仅有a的话，则删除位置a后面的字符
   4. 截取     string s = c.substr(a, b);  a：截取的初始位置，b：截取的长度
   5. 插入     c.insert(a, "xxx") a：在位置a之前插入
   6. 翻转顺序  reverse(s.begin() + a, s.end() - b); 指定位置翻转,从a到b
   7. 赋值     str.assign(str1.begin()+1, str1.end()-1); 将区间内str1的元素赋值给 str
   ```

6. 排序 `sort(s.begin(), s.end());`

7. ~~去重~~ ：标记重捕法/doge

   ```C++ {.line-numbers}
   string uniquee(string c)
   {
       string ch;
       bool s[100] = {false};
       for (int i = 0; i < c.length(); i++)
       {
           if (s[c[i] - ' '] == false)
               ch += c[i];
           s[c[i] - ' '] = true;
       }
       return ch;
   }
   ```

8. 找最长的字符串：

   ```C++ {.line-numbers}
    string s[10000];
    int n, max = 0, p, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i].length() > max)
            max = s[i].length(), p = i;
       }
    cout << "The longest is: " << s[p];
   ```

9. **sprintf**

   ```C++ {.line-numbers}
   char s[100][10] = {'\0'};
   for (int i = 1; i <= n; i++)
       sprintf(s[i], "%d", i);  --> 将数字转为字符串存在s[100]中
           也有多变量的： sprintf(ans, "%d+%d=%d", x, y, x + y); →同时还把+ = 也存进去了
       然后再用 atoi还原：int a = atoi(s);

   所以就有了， 读取数字长度：
   int wei(int x)　　　　　// int len = to_string(x).length();
   {                     // int len = log(x)/log(10) + 1;
       char s[100];
       sprintf(s, "%d", x);
       return strlen(s);
   }

   还有，分离数字到数组里：
       int a = 234454555, i, j;
       char c[20];
       int shu[20];
       sprintf(c, "%d", a);
       for (i = 0; i < strlen(c); i++)
           shu[i] = c[i] - '0';
       for (j = 0; j < i; j++)
           cout << shu[j];
   ```

10. 但在 C++11 之前， 没有 to_string ：

    ```C++ {.line-numbers}
    #include <sstream>
    string Itos(int x)  //int Stoi(string x)
    {
        string t; stringstream ss;  // stringstream ss; int t;
        ss << x, ss >> t, ss.clear();   //ss << x, ss >> t, ss.clear();
        return t;
    }
    ```

    但还可以用模板：

    ```C++ {.line.numbers}
    template <class out_type, class in_value>
    out_type transf(const in_value &t)
    {
        stringstream stream; out_type result;
        stream << t, stream >> result, stream.sync();
        return result;
    }
    to use:
        string s = transf<string>(x);
        int n = transf<int>(s);
    ```

11. **#include < cctype>** —>其实算是 bool 类型的 —>多用于 if 判断的

    ```C++ {.line-numbers}
    只能用在单个字符
    isalnum(c) -->是否为字母或者数字
    isalpha(c) -->是否为字母
    isblank(c) -->是否为空格或者 tab
    isdigit(c) -->是否为数字
    ispunct(c) -->是否为符号
    isupper(c) -->是否为大写字母
    isspace(c) -->是否为空格
    ```

12. atoi 整数； atof 小数

13. 找连续的“0”的个数 —>跳过连续的“0”

    ```C++ {.line-numbers}
    string s;
    int p, c = 0;
    cin >> s;
    while ((p = s.find('0', p)) != s.npos)
    c++, p = s.find('1', p);
    cout << c;

    所以还有：
     for (int i = 0; i < n; i++)
         if (x[i] == '0')
         {
             cn++;
             while (x[i] == '0' && i < n) //跳过连续的0
                 i++;
         }
    ```

14. 比较快地输入 string（不含空格）

    ```C++ {.line-numbers}
    const int Max = 1e6 + 5;
    char ctr[Max];
        string s;
        scanf("%s", ctr);
        s = string(ctr);
    ```

15.
