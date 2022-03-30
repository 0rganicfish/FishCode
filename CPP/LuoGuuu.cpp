#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;

int hex(string x)
{
    transform(all(x), x.begin(), ::tolower);
    int ans = 0, l = x.length();
    for (ll i = 0, n = 1; i < l; i++, n *= 16)
        ans += n * (isdigit(x[i]) ? x[i] - '0' : x[i] - 'a' + 10);
    return ans;
}
int main()
{
    string a = "34";
    a = char(1 + '0') + a;
    cout << a;
}