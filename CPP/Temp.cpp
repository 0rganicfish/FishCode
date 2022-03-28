#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ll unsigned long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define FOR(n, m) for (int i = n; i <= m; ++i)
#define ROF(n, m) for (int i = n; i >= m; --i)
using namespace QAQ;

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
int main()
{
    cout << jin(14, 16);
    return 0;
}
