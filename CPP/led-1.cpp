#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxx = LONG_LONG_MAX, ans = 1;
ll a[10000000] = {1, 1};
int main()
{
    int i = 1;
    cout << maxx << endl;
    for (; ans <= maxx; ++i)
        ans *= i;
    cout << i << "! = " << ans;
}