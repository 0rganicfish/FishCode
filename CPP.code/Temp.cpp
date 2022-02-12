#include <bits/stdc++.h>
using namespace std;
long long FB[1000005];
int main()
{
    int n;
    cin >> n;
    FB[0] = FB[1] = 1;
    for (int i = 2; i <= n; ++i) //递推法
        FB[i] = FB[i - 1] % 1000000007 + FB[i - 2] % 1000000007;
    cout << FB[n - 1] % 1000000007 << endl;
}