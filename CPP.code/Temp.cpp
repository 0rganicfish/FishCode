#include <bits/stdc++.h>
using namespace std;
    typedef pair<int, int> Pair;

    struct cmp
    {
        bool operator()(const Pair &a, const Pair &b)
        {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        } // 先按first小到大排序，first相等时按second小到大排序
    };

    ostream &operator<<(ostream &out, const Pair &O)
    {
        return out << "(" << O.first << ", " << O.second << ")" << endl;
    }  // 重载输出符 <<

    int main()
    {
        priority_queue<Pair, vector<Pair>, cmp> q;
        int n, a, b;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a >> b, q.push(make_pair(a, b));

        while (!q.empty())  // 队列没有迭代器
            cout << q.top(), q.pop();
    }