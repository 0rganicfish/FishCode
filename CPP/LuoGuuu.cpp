#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
using namespace QAQ;

#include "Class.hpp"

int main()
{
    Box box1[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> box1[i].a, box1[i].calc();
    sort(box1, box1 + n, cmp_ans);
    for (int i = 0; i < n; ++i)
        box1[i].print();
    return 0;
}