# 搜索

[首页](../cpp.main.md)

[TOC]

#### 二分搜索

- 数组要放在全局

  ```C++ {.line-numbers}
  bool mids(int n, int x)   //n为数组的长度， x为要找的数
  {
      int rit = n, lef = 0, mid;
      while (rit > lef)
      {
          mid = (rit + lef) / 2;
          if (a[mid] == x)
              return true;
          if (x > a[mid])
              lef = mid + 1; // 往后半部分搜
          else
              rit = mid;  //前半部分搜
      }
      return false;
  }
  ```

#### 深搜

- 数字全排列

  ```C++ {.line-numbers}
  int a[10];
  bool used[10];
  int n; //要全局

  void dfs(int x)
  {
      if (x == n) // 到了边界
      {
          for (int i = 1; i <= n; i++)
              cout << a[i] << " ";
          cout << endl;
          return; //回溯，到used[i] = false;
      }
      for (int i = 1; i <= n; i++)
          if (used[i] == false)
          {
              a[x + 1] = i;       //放进去
              used[i] = true; //标记已经放的位置
              dfs(x + 1);
              used[i] = false; //回退，撤销标记
          }
  }
  int main()
  {
      cin >> n;
      dfs(0);
      return 0;
  }
  ```

- 选数，求质数和

  ```C++ {.line-numbers}
  void dfs(int m, int sum, int startx)
  //k：边界，m：判断是否到了边界，sum：一个值，startx：用于排列组合地选的 地址
  {
      if (m == k)
      {
          if (isprime(sum))
              ans++;
          return;//这个退出是指 退出一层递归，回到上一次调用函数的那行码的下一行，再无事地走下去
      }   //因为到边界了，所以要退出
      for (int i = startx; i < n; i++)
          dfs(m + 1, sum + a[i], i + 1);
      //其实等价于：(m = m + 1, sum = sum + a[i], startx = i + 1)这样的
      return;
  }
  ```

#### 广搜
