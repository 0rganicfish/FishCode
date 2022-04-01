#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool run(int x)
{
    if (x % 400 == 0 or (x % 4 == 0 and x % 100))
        return 1;
    return 0;
}

int main()
{
    ll ans = 0, day = (52 + 12) * 20 + 47;
    for (int i = 2000; i < 2020; ++i)
    {
        m[2] = run(i) ? 29 : 28;
        for (int j = 1; j <= 12; ++j)
            day += m[j];
    }
    m[2] = 29;
    for (int i = 1; i < 10; ++i)
        day += m[i];
    cout << day;
}
// (i + 3) % 7 == 0