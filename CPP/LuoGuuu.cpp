#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define FOR(n, m) for (int i = n; i <= m; ++i)
#define ROF(n, m) for (int i = n; i >= m; --i)
using namespace QAQ;

const int mod = 1e9 + 7;
int main()
{
    ll n, k, ans = 0, t = 1;
    cin >> n >> k;
    while (n)
    {
        if (n & 1)
            (ans += t) %= mod;
        (t *= k) %= mod, n >>= 1;
    }
    cout << ans;
}