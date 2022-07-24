#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

#define vi vector<int>

 

int main()
{
    int n = 9;
    vi a{2, 7, 1, 5, 6, 4, 3, 8, 9}, f(n, 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);

    for (int ele : f)
        cout << ele << " ";
    cout << endl
         << *max_element(all(f));
    return 0;
}