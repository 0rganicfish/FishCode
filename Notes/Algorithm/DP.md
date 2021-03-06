# 动态规划 DP

[首页](Main.md)

[TOC]

### 普通 DP

##### 斐波那契数列

```C++ {.line-numbers}
int dp[50] = {0};
int fib(int n)   //递归法
{
    if (n <= 1) return dp[n] = 1;
    if (dp[n]) return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    int FB[50];
    int n;
    cin >> n;
    FB[0] = FB[1] = 1;
    for (int i = 2; i <= n; i++)    //递推法
        FB[i] = FB[i - 1] + FB[i - 2];

    cout << FB[n] << endl
         << fib(n);
}
```

##### 使用硬币的个数

```C++ {.line-numbers}
const int MAXM = 1000;
const int type = 6;
int money[MAXM] = {0};
int coin[type] = {1, 5, 10, 20, 50, 100};
void solve()
{
    int i, j;
    for (i = 1; i < MAXM; i++)
        money[i] = INT_MAX - 1;

    for (i = 0; i < type; i++)
        for (j = coin[i]; j < MAXM; j++)
            money[j] = min(money[j], money[j - coin[i]] + 1);
}
```

# 背包

## 01 背包

```C++ {.line-numbers}
void solve()
{
    for (i = 1; i <= num; i++)
        for (j = 1; j <= w; j++)
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
}

//一维数组优化（覆盖过程，防爆空间）
void solvee()
{
    for (i = 1; i <= num; i++)
        for (j = w; j >= 0; j--)
            if (j >= weight[i])
                DP[j] = max(DP[j], DP[j - weight[i]] + value[i]);
}
cout << DP[w];
```
