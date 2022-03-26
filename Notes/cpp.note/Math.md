<p style="font-size: 40px; color: #fff"><b>数学</b></p>

[首页](../cpp.main.md)
[TOC]

<br><br>

## 基础数学

### 其他

1. `exp(a)` 是指 $e^{a}$ , 精度比自定义 $e = 2.71828182\dots $ 再 pow 要高
2. $\pi$ 定义：$ \pi = \arccos(-1) $ : `#define PI acos(-1) `

### 位运算

1. 偶数的二进制的最后一位是 0， 也就是 `if(n % 2)`等同于 `if(n & 1)`
2. `a << b` 相当于 a 乘以 2 的 b 次方， 比一般的乘法要快
3. `a >> b` 相当于 a 除以 2 的 b 次方并取整，`a >> 1` 也就是除以 2

### 取模公式

1. $ (A + B) \% C = (A \% C + B \% C)\% C $
2. $ (A \times B) \% C = ((A \% C) \times (B \% C))\% C $

### 快速幂

- 比一般的 `pow` 快

  ```C++ {.line-numbers}
  typedef long long ll;
  ll qpow(ll a, ll b)
  {
      ll ans = 1;
      while (b)
      {
          if (b & 1) ans *= a;
          a *= a, b >>= 1;
      }
      return ans;
  }
  ```

### 最大公约数

- 最小公倍数为 `a * b / 返回值 a`
- 在 C++中：函数 `int c = __gcd(a, b)`;

  ```C++ {.line-numbers}
  int gcd(int a, int b)
  {
      while (a != b)
         (a > b) ? (a -= b) : (b -= a);
      return a;
  }
  ```

### 进制转换

- 十进制转 xx 进制

  ```C++ {.line-numbers}
  string jin(int n, int radix)
  {
      string ans = "";
      while (n != 0)
      {
          int t = n % radix;
          if (t >= 0 && t <= 9)
              ans += t + '0';
          else
              ans += t - 10 + 'a';
          n /= radix;
      }
      reverse(ans.begin(), ans.end());
      return ans;
  }
  ```

- 十进制转二进制：

  ```C++ {.line-numbers}
    vector<int> a;
    while (n)
        a.push_back(n & 1), n >>= 1;
    reverse(all(a));
  ```

- 十六进制转十进制：

  ```C++ {.line-numbers}
  int hex(string x, int f)
  {
      transform(x.begin(), x.end(), x.begin(), ::tolower);
      int ans = 0, l = x.length();
      for (double i = 0, j = l - 1; i < l; i++, j--)
          if (isdigit(x[i]))
              ans += pow(16., j) *(x[i] - '0');
      else
              ans += pow(16., j)* (x[i] - 'a' + 10);
      if (f == -1) ans = -ans;
      return ans;
  }
  ```

### 回文数（数学方法）

- 会比 `to_string` 快得多

  ```C++ {.line-numbers}
  bool hui(int x)
  {
      int y = x * 10, num = 0;
      while (y /= 10)
          num = num * 10 + y % 10;
      if (num == x)
          return 1;
      return 0;
  }
  ```

### 求质数与质数筛

- 估算范围内质数的数量：**$n=\frac{x}{\ln x}$**
- 判断质数

  ```C++ {.line-numbers}
  bool isprime(int n)
  {
    if (n < 2 or !n & 1)
        return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (!n % i)
            return false;
    return true;
  }
  ```

- 倍数筛：

  ```C++ {.line-numbers}
  int a[10000];
  int primer(int n)
  {
    bool p[n] = {false}; //本来全是true的
    int k = 0;
    for (int i = 2; i <= n; i++)
        if (!p[i])
        {
            a[k++] = i;
            for (int j = i * i; j <= n; j += i)
                p[j] = true;  //其实为了方便反了过来
        }
    return k;  //k为最后一个质数的位置
  }
  ```

- 欧拉筛

  ```C++ {.line-numbers}
  int a[10000];
  int primer_ola(int n)
  {
      int i, j, k = 0;
      bool p[n];
      for (i = 0; i < n; i++)
          p[i] = true;
      for (i = 2; i <= n; i++)
      {
          if (p[i])
              a[k++] = i; //如果是质数
          for (j = 0; j < k && i * a[j] <= n; j++)
          {
              p[i * a[j]] = false; //把每一个求出来的质数的倍数都标记
              if (i % a[j] == 0)
                  break; //跳过已经被标记的
          }
      }
      return k;
  }
  ```

### mod 与 阶乘

- 令 a 为 mod 的最大质因数，那大于等于 a 的数的阶乘都能被 mod 整除
  即：`a！% mod == 0`

### 高精度

- 必备：

  ```C++ {.line-numbers}
  typedef long long ll;
  typedef vector<int> vecint;

  vecint vecin(ll n)  //数字转vector
  {
      vecint t;
      while (n)
          t.push_back(n % 10), n /= 10;
      return t;
  }

  void coutvec(vecint t)  //输出
  {
      while (!t.empty())
          cout << t.back(), t.pop_back();
  }

  // 定义 in main:
  int a;
  cin >> a;
  vecint x(numpush(a));
  coutvec(x);
  ```

- 加法

  ```C++ {.line-numbers}
  vecint add(vecint x, vecint y) // x >= 0, y >= 0
  {
      if (x.size() < y.size())
          return add(y, x);
      vecint ans;
      int t = 0;
      for (int i = 0; i < x.size(); ++i)
      {
          t += x[i];
          if (i < y.size())
              t += y[i];
          ans.push_back(t % 10), t /= 10;
      }
      if (t)
          ans.push_back(t);
      return ans;
  }
  ```

- 乘法

  ```C++ {.line-numbers}
  vecint multi(vecint x, int y) // x > 0, y > 0, x高精 y低精
  {
      vecint ans;
      int t = 0;
      for (int i = 0; i < x.size() or t; ++i)
          t += x[i] * y, ans.push_back(t % 10), t /= 10;
      return ans;
  }
  ```

### 全排列

- 算法实现

  ```C++ {.line-numbers}
  void Perm(int list[], int k, int m)
  {
      if (k == m)
      {
          for (int i = 0; i <= m; i++)
              cout << list[i] << " ";
          cout << endl;
      }
      else
          for (int i = k; i <= m; i++)
          {
              swap(list[i], list[k]);
              Perm(list, k + 1, m);
              swap(list[i], list[k]);
          }
  }
  int main()
  {
      int a[] = {1, 2, 3, 4, 5};
      Perm(a, 0, 4);
  }
  ```

- STL 实现：

  ```C++ {.line-numbers}
  do
  {
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
  } while(next_permutation(a, a + 5));
  ```

### 排列组合

- 组合 $C_{m}^{n}$

  ```C++ {.line-numbers}
  ll C(int n, int m)
  {
      ll ans = 1;
      n = min(n, m - n);
      for (int i = m, j = n; j; i--, j--)
          ans = ans * i / j;
      return ans;
  }
  ```

- 排列 $A_{m}^{n}$

  ```C++ {.line-numbers}
  ll A(int n, int m)
  {
      ll ans = 1;
      n = min(n, m - n);
      for (int i = m; i > n; i--)
          ans *= i;
      return ans;
  }
  ```

## 高阶数学（数论）

### Miller-Robin 的素数判断

- 利用随机化算法判断一个数是合数还是可能是素数（毫秒级判断大数）。（玄学）

  ```C++ {.line-numbers}
    ll fpow(ll a, ll x, ll mod)
    {
        ll ans = 1;
        while (x)
        {
            if (x & 1)
                (ans *= a) %= mod;
            (a *= a) %= mod, x >>= 1;
        }
        return ans;
    }

  bool Miller_Rabbin(int x)
  {
      if (x == 1) return false;
      if (x == 2) return true;
      for (int i = 1; i <= 30; ++i)
      {
          int now = rand() % (x - 2) + 2;
          if ((int)(fpow(now, x - 1, x)) != 1)
              return false;
      }
      return true;
  }
  ```
