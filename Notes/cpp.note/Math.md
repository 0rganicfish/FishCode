<p style="font-size: 40px; color: #fff"><b>数学</b></p>

[首页](../cpp.main.md)
[TOC]

<br><br>

## 基础数学

### 其他

1. `exp(a)` 是指 $ e^a $ , 精度比自定义 $ e = 2.71828182\dots $ 再 pow 要高
2. $\pi$ 定义：$ \pi = \arccos(-1) $ : `#define PI acos(-1) `

### 位运算

1. 偶数的二进制的最后一位是 0， 也就是 `if(n % 2)`等同于 `if(n & 1)`
2. `a << b` 相当于 a 乘以 2 的 b 次方， 比一般的乘法要快
3. `a >> b` 相当于 a 除以 2 的 b 次方并取整，`a >> 1` 也就是除以 2
4. 相同数之间取 异或 `^` 得 0

### 取模公式

1. $ (A + B) \bmod C = (A \bmod C + B \bmod C)\bmod C $
2. $ (A \times B) \bmod C = ((A \bmod C) \times (B \bmod C))\bmod C $
3. $ A^B\;\bmod C = (A \bmod C)^B\;\bmod C $

### 快速幂

- 比一般的 `pow` 快，且 $ x \bmod 0 = x $

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
    return ans % mod;
  }
  ```

### 快速乘

- 利用了 `unsigned long long` 的自动溢出，且保证了它们溢出后的差值基本不变。且 $ O(1) $ ！

  ```C++ {.line-numbers}
  ll ksc(ll x, ll y, ll mod)
  {
      ll z = (long double)x / mod * y;
      ll res = (ull)x * y - (ull)z * mod;
      return (res + mod) % mod;
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

### 因数与质因数

- $ O(\sqrt{n}) $ 下的因数分解

  ```C++ {.line-numbers}
  vector<ll> a;
  for (ll i = 1; i <= n / i; ++i)
      if (n % i == 0)
      {
          a.push_back(i);
          if (n / i != i)
              a.push_back(n / i);
      }
  ```

- $ O(\sqrt[4]{n}) $ 下的 $ Pollard \ Pho $ 质因数分解

  ```C++ {.line-numbers}
  vector<ll> a;
  for (ll i = 2; i <= n; ++i)
      while (n != i)
          if (n % i == 0)
              a.push_back(i), n /= i;
          else
              break;
  a.push_back(n);
  ```

### 进制转换

- C++ 下的 `iostream` 流特性：

  ```C++ {.line-numbers}
  int n;
  cin >> hex >> n;          //输入 16 进制数，可含字母
  cout << dec << n << endl; //输出 10 进制数
  cout << oct << n << endl; //输出 8 进制数
  ```

  > 但转二进制要另外写......

- 十进制转 xx 进制

  ```C++ {.line-numbers}
  string jin(int n, const int x)
  {
      string ans(8, '0');
      for (int i = 8; n; n /= x)
      {
          int t = n % x;
          ans[--i] = (t >= 0 and t <= 9 ? t + '0' : t - 10 + 'a');
      }
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
  int hex(string x)
  {
      transform(all(x), x.begin(), ::tolower);
      int ans = 0, l = x.length();
      for (ll i = 0, n = 1; i < l; i++, n *= 16)
          ans += n * (isdigit(x[i]) ? x[i] - '0' : x[i] - 'a' + 10);
      return ans;
  }
  ```

### 回文数（数学方法）

- 会比 `to_string` 快得多

  ```C++ {.line-numbers}
  bool hui(ll x)
  {
      ll y = x * 10, num = 0;
      while (y /= 10)
          num = num * 10 + y % 10;
      if (num == x)
          return 1;
      return 0;
  }
  ```

### 完全平方数

- 主要是判断与被开方数相等
- 原理：

  - 观察到：$ 1=1，4=1+3，9=1+3+5，16=1+3+5+7 $
  - 以此类推，可以从 $n$ 开始 不断减去一个从 1 开始不断增大的**奇数**，若最终减成了 0，说明是完全平方数，否则不是。

- 字面解： $ O(\sqrt{n}) $

  ```C++ {.line-numbers}
  bool PerfectSquare(ll n)
  {
      for (ll t = 1; n > 0; t += 2)
          n -= t;
      return !n;
  }
  ```

- **优化后：** $ O(\sqrt[4]{n}) $ ，最坏也有 $ O(\sqrt{n}) $

  ```C++ {.line-numbers}
  bool Perfect(ll n)
  {
      for (ll i = 2; i <= n / i; ++i)
          while (n % (i * i) == 0)
              n /= i * i;
      return n == 1;
  }
  ```

### 求质数与质数筛

- 估算范围内质数的数量：**$ n=\frac{x}{\ln x} $**

- 判断质数

  ```C++ {.line-numbers}
  bool isprime(ll n)
  {
      if (n < 2 or n & 1 == 0)
          return false;
      for (ll i = 3; i <= n / i; i += 2)
          if (n % i == 0)
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
  int N = 1e7 + 5, L = N / log(N) + 100;
  ll *f = new ll[N], *primes = new ll[L];
  void ola(int n)
  {
      for (int i = 2, cnt = 0; i <= n; i++)
      {
          if (!f[i])  primes[cnt++] = i;
          for (int j = 0; primes[j] <= n / i; j++) //要确保质数的第i倍是小于等于n的。
          {
              f[primes[j] * i] = 1;
              if (i % primes[j] == 0)  break;
          }
      }
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

- 组合 $ C_m^n $

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

- 排列 $ A_m^n $

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

<br><br>

## 高阶数学（数论）

### 蔡勒公式 - 日期

- 用于判断某年的某一日是星期几
- 公式： $ week=(y+ \left [ \frac{y}{4}\right ] + \left [ \frac{c}{4} \right ] - 2c +
  \left[\frac{26 \times (m+1)}{10} \right ] + d -1) \bmod 7 $
- 符号意义：
  - $ week $ ：以周日为第一天
  - $ c $ ：世纪
  - $ \left [ x \right] $ ：对 $ x $ 取整
- 且：在 **蔡勒公式** 中，某年的 1、2 月要看作 **上一年** 的 13、14 月来计算。比如 2003 年 1 月 1 日要看作 2002 年的 13 月 1 日来计算
- 码：
  ```C++ {.line-numbers}
  string week[7] = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};
  string DayOfTheWeek(int year, int month, int day)
  {
      if (month <= 2)
          month += 12, year -= 1;
      int c = year / 100;
      year %= 100;
      int w = (year + year / 4 + c / 4 - 2 * c + (26 * (month + 1) / 10) + day - 1) % 7;
      return week[(w + 7) % 7];
  }
  ```

<br>

### Miller-Robin 的素数判断

- 利用随机化算法判断一个数是合数还是可能是素数（毫秒级判断大数）。~~（玄学）~~

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
