#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;

string ToBin(string x)
{
    string ans;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    for (int i = x.size() - 1; i >= 0; --i)
    {
        int t = isdigit(x[i]) ? x[i] - '0' : x[i] - 'a' + 10;
        while (t)
            ans = char(t % 2 + '0') + ans, t >>= 1;
    }
    return ans;
}

int main()
{
    int T, n, t = 0;
    for (cin >> T; T--;)
        cin >> n, t ^= n;
    cout << t;
}