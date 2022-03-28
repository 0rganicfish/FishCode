#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
using namespace QAQ;

string jin(int n, int radix)
{
    string ans;
    while (n)
    {
        int t = n % radix;
        ans += (isdigit(t) ? t + '0' : t - 10 + 'a');
        n /= radix;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << isdigit(14);
}