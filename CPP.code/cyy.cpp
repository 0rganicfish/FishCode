#include <bits/stdc++.h>
using namespace std;
typedef vector<int> intvec;

int main()
{

    int a[5] = {1, 3, 7, 9, 2};
    cout << binary_search(a, a + 5, lower_bound(a, a + 5, 5) - a);
}