#include <bits/stdc++.h>
// #pragma GCC optimize(3)
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define FOR(n, m) for (int i = n; i <= m; ++i)
#define ROF(n, m) for (int i = n; i >= m; --i)
using namespace QAQ;

#include "Class.hpp"
using namespace Fish;

int main()
{
    Circle c[10];
    int n;
    cin >> n;

    FOR(0, n - 1)
        c[i].push(), c[i].calc();
    sort(c, c + n, cmp_area);

    FOR(0, n - 1)
        c[i].print();

    cin >> n;
    return 0;
}