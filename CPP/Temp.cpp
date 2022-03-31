#include <bits/stdc++.h>
#define endl "\n"
#define ll unsigned long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
using namespace QAQ;

const int Max = 1005;
ll a[Max][Max] = {0}, dp[Max][Max];

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 2; i <= n; ++i)
        while (n != i)
            if (n % i == 0)
                a.push_back(i), n /= i;
            else
                break;
    a.push_back(n);
    for (auto i : a)
        cout << i << " ";

    return 0;
}
