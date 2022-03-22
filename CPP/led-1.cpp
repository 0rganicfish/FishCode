#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ll unsigned long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
using namespace QAQ;

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

int main()
{
    ll a, b, c, d, mod;
    cin >> a >> b >> c >> d >> mod;
    a %= mod, b %= mod, c *= d, a *= b, a %= mod;
    ll ans = 1;
    while (c)
    {
        if (c & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod, c >>= 1;
    }
    cout << ans % mod;
    return 0;
}