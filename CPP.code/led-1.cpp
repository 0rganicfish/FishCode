#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;

int main()
{
    queue<Pair> q;
    Pair x, y;
    int n, t;
    cin >> n;
    for (int i = 1; i <= (1 << n); i++)
        cin >> t, q.push(make_pair(t, i));
    while (q.size() > 2)
    {
        x = q.front(), q.pop();
        y = q.front(), q.pop();
        x.first > y.first ? q.push(x) : q.push(y);
    }
    x = q.front(), q.pop();
    y = q.front(), q.pop();
    cout << (x.first > y.first ? y.second : x.second);
    return 0;
}