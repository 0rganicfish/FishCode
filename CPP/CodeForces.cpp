#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

string er(int n)
{
    string ans;
    while (n)
        ans = char(n % 2) + ans, n /= 2;
    return ans;
}

signed main()
{
    int a[] = {6, 6, 6, 7};
    string s = "1234";
    // s.begin();
    // cout << *(lower_bound(a, a + 4, 6));
    // sort(s.begin(), s.end());
    // sort(a, a + 4);
    s.insert(s.end(), 3, '9');
    cout << s;
}