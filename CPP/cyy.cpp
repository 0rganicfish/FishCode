#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2> //不同类型
inline const T2 big(const T1 a, const T2 b)
{
    return a > b ? a : b;
}

int main()
{
    cout << big<int>(6.1, 4);
    char c;
    c = toupper(c);
    return 0;
}
