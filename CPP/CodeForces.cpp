#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int f[15000] = {0}, a[105];
signed main()
{
    int n, ans = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            f[a[i] + a[j]] = 1, f[abs(a[i] - a[j])] = 1;

    for (int i = 0; i <= sum; ++i)
        if (f[i])
            ++ans;
    cout << ans + n;
}