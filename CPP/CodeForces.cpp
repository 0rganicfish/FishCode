#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
typedef vector<int> vecint;

vecint vecin()
{
    vecint t;string n;
    cin >> n;
    while (!n.empty())
        t.push_back(n.back() - '0'), n.pop_back();
    reverse(t.begin(), t.end());
    return t;
}
signed main()
{
    vecint n(vecin()), m(vecin());
    sort(n.begin(), n.end());
    int nl = n.size(), ml = m.size();
    if (nl < ml) m = vecint(nl, 9);
    if (!binary_search(n.begin(), n.end(), m[0]))
    {
        auto it = lower_bound(n.begin(), n.end(), m[0]) - 1;
        cout << *it, n.erase(it);
        sort(n.rbegin(), n.rend());
        for (auto i : n)
            cout << i;
        return 0;
    }
    for (int i = 0;i < nl - 1; ++i)
    {
        if (!m[i]) m[i] = 10;
        auto it = upper_bound(n.begin(), n.end(), m[i]) - 1;
        cout << *it, n.erase(it);
    }
    cout << n.front();
}