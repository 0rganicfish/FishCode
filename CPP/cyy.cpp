#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

signed main()
{
    int m;
    cin >> m;
    cout << (m == 2 ? "NO" : ((m - 2) % 2) ? "NO" : "YES");
    return 0;
}