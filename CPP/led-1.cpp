#include <bits/stdc++.h>
#define endl "\n"
#define ll unsigned long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
using namespace QAQ;

#define vecint vector<int>
vecint multi(vecint x, int y) // x > 0, y > 0, x高精 y低精
{
    vecint ans;
    int t = 0;
    for (int i = 0; i < x.size() or t; ++i)
        t += x[i] * y, ans.push_back(t % 10), t /= 10;
    return ans;
}

ll fpow(ll a, ll x, ll mod) // x高精
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

int main()
{
    cout << 1e100000;
}

// int main()
// {
//     int T, n;
//     cin >> T;
//     while (T--)
//     {
//         int a[30] = {0}, b[30] = {0};
//         ll ans = 0;
//         cin >> n;

//         for (int i = 1; i <= n; ++i)
//             cin >> a[i], b[i] = a[i];
//         sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);

//         for (int i = 1; i <= n; ++i)
//             a[i] -= b[i - 1];
//         sort(a + 1, a + n + 1);

//         for (int i = 1; i <= n; ++i)
//             a[i] += a[i - 1];
//         for (int i = 1; i <= n; ++i)
//             ans += a[i];
//         cout << ans << endl;
//     }
// }

// ll jin(int n, const int x)
// {
//     string ans;
//     for (int i = 8; n; n /= x)
//     {
//         int t = n % x;
//         ans = char(t + '0') + ans;
//     }
//     return count_if(all(ans), [](char c)
//                     { return c == '1'; });
// }

// int main()
// {
//     int T, n, x, y;
//     cin >> T;
//     while (T--)
//     {
//         cin >> n >> x >> y;
//         int xx = jin(n, x), yy = jin(n, y);
//         if (xx > yy)
//             putchar('>');
//         else if (xx < yy)
//             putchar('<');
//         else
//             putchar('=');
//         putchar('\n');
//     }
// }

// ll fpow(ll a, ll x, ll mod)
// {
//     ll ans = 1;
//     while (x)
//     {
//         if (x & 1)
//             (ans *= a) %= mod;
//         (a *= a) %= mod, x >>= 1;
//     }
//     return ans % mod;
// }

// int main()
// {
//     ll a, b, c, d, mod;
//     cin >> a >> b >> c >> d >> mod;
//     a %= mod, b %= mod, c *= d, a *= b, a %= mod;
//     ll ans = 1;
//     while (c)
//     {
//         if (c & 1)
//             (ans *= a) %= mod;
//         (a *= a) %= mod, c >>= 1;
//     }
//     cout << ans % mod;
//     return 0;
// }