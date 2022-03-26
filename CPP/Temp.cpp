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

int main()
{
    string s;
    int m;
    map<string, int> guo;
    getline(cin, s);
    stringstream ss;
    ss << s;
    while (ss >> s >> m)
        guo[s] += m;
    return 0;
}
