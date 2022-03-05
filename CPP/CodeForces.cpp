#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

ll fib[1001] = {1, 1};

signed main()
{
    int n;
    string ans = "";
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return 0;
}