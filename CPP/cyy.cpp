#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

template <typename T>
deque<T> uniquee(T s)
{
    set<T> q;
    deque<T> ans;
    for (T i : s)
        q.insert(i);
    for (T i : q)
        ans.push_front(i);
    return ans;
}

signed main()
{
    string s;
    cin >> s;

    return 0;
}