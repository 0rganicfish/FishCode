#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ll unsigned long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
using namespace QAQ;

bool cmp(string b, string c)
{
    return b + c < c + b;
}

int main()
{
    int n, T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(all(a), cmp);
        for (int i = 0; i < a.size();++i)
            cout << a[i];
        cout << endl;
    }
}