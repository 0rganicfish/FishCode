#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

int main()
{
    map<string, int> quan;
    set<string> fri;
    string t;
    int T, N, f = 0;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> t, quan.insert(make_pair(t, N));
    }
    cin >> N;
    while (N--)
    {
        cin >> t;
        if ((quan.find(t) == quan.end() or quan[t] == 1) and fri.find(t) == fri.end())
        {
            if (f)
                cout << " ";
            cout << t, f = 1;
        }
        fri.insert(t);
    }
    if (!f)
        cout << "No one is handsome";
}