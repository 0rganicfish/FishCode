#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

int main()
{
    ll n, m, mod = 1e9 + 7, ans = 1;
    cin >> n;
    while (n--)
    {
        cin >> m;
        (ans *= m) %= mod;
    }
    cout << ans;
}