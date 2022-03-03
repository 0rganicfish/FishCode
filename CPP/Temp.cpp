#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define Max(a, b) (a > b) ? a : b
#pragma GCC optimize(3)

bool hui(int x)
{
    int y = x * 10, num = 0;
    while (y /= 10)
        num = num * 10 + y % 10;
    if (num == x)
        return 1;
    return 0;
}

int main()
{
    cout << hui(233532);
}