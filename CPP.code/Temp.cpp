#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string er(int x)
{
    x = abs(x);
    string ans = "";
    while (x)
        ans = char(x % 2 + '0') + ans, x /= 2;
    return ans;
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        string ans = er(n);
        for (int i = ans.length(); i < 32; ++i)
            ans = (n > 0 ? '0' : '1') + ans;
        cout << ans << endl;
    }
}

/* B
ll ans = 0;
    for (ll i = 1; i <= 2022; ++i)
        ans += to_string(i).length();
    cout << ans;
*/

/* C (unfinished)
ll ans = 0;
ll yin(ll x)
{
    ll sum = 0;
    for (ll i = 1; 2 * i <= x; ++i)
        if (x % i == 0)
            sum += i;
    ++ans;
    if (sum == 1)
    {
        cout << ans;
        return 0;
    }
    else
        yin(sum);
}
*/
