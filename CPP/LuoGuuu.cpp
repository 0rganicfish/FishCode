#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;

const ll Max = 1e3, len = Max / log(Max) + 100;
vector<ll> primer(len, 0);
vector<bool> P(Max, 0);

void ola(int x)
{
    for (ll i = 2, cnt = 0; i <= x; ++i)
    {
        if (!P[i])
            primer[cnt++] = i;
        for (ll j = 0; primer[j] <= x / i; ++j)
        {
            P[primer[j] * i] = 1;
            if (i % primer[j] == 0)
                break;
        }
    }
}

int main()
{
    ola(Max);
    ll T;
    for (cin >> T; T--;)
    {
        int n, i;
        cin >> n;
        for (i = 0; i <= len; ++i)
            if (primer[i] > n)
                break;
        cout << i << endl;
    }
}
