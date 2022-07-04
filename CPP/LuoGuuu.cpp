#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define utf8 system("chcp 65001");
using namespace QAQ;

int main()
{
    int x = 10, &y = x;
    int *p = &y;
    y++, ++x;
    cout << *p + y;
    return 0;
}
