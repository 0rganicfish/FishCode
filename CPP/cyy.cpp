#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

int a[1100][1100];
int dp[100][100] = {0};
int main()
{
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    cout << a[n][n];
    return 0;
}