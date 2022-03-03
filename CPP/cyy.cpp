#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#pragma GCC optimize(3)
static auto _ = []()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    return 0;
}();

void write(int n)
{
    if (n < 0)
        putchar('-'), n = -n;
    if (n > 9)
        write(n / 10);
    putchar(n % 10 + '0');
}

int read()
{
    int x = 0, f = 1;
    char c;
    while ((c = getchar()) and !isdigit(c))
        if (c == '-')
            f = -1;
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}

bool hui(int x)
{
    int y = x * 10, num = 0;
    while (y /= 10)
        num = num * 10 + y % 10;
    if (num == x)
        return 1;
    return 0;
}

int fpow(int a, int x, int mod)
{
    int ans = 1;
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
    for (int i = 1; i <= 30; ++i)
    {
        int now = rand() % (x - 2) + 2;
        if ((int)(fpow(now, x - 1, x)) != 1)
            return false;
    }
    return true;
}
signed main()
{
    int n, m;
    n = read(), m = read();
    n % 2 ? n : ++n;
    for (int i = n; i <= m; i += 2)
        if (hui(i) and Miller_Rabbin(i))
            write(i), putchar('\n');
    return 0;
}