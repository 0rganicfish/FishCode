#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6 + 5;
int a[Max];
int main()
{
    int n, mod;
    cin >> n >> mod;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int k = mod; k; --k)
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if ((a[i] + a[j]) % mod == k)
                {
                    cout << k;
                    return 0;
                }
}
