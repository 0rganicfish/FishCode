#include <bits/stdc++.h>
using namespace std;

template <class out_type, class in_value>
out_type transf(const in_value &t)
{
    stringstream stream;
    out_type result;
    stream << t, stream >> result, stream.sync();
    return result;
}

int main()
{
    string s = "532";
    int a[transf<int>(s)] = {};
    int *p1 = new int[10]();
    *p1 = 3;
    cout << p1[0];
}