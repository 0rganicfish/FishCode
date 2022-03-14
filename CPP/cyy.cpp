#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[25];
long long ans;

bool isprime(int a)
{
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}

void dfs(int m, int sum, int startx)
{
    if (m == k)
    {
        if (isprime(sum))
            ans++;
        cout << sum << " " << startx << endl;
        return;
    }
    for (int i = startx; i < n; i++)
    {
        cout << "shang: " << sum << " m: " << m << endl;
        dfs(m + 1, sum + a[i], i + 1);
        // xxx
        cout << "xia: " << sum << " m: " << m << endl;
    }
    cout << "over!";
    return;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}