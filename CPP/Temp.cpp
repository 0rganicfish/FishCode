#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
string re(string x)
{
    x.push_back(x.front());
    return string(x, 1);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << binary_search(a, a + 5, 9);
}