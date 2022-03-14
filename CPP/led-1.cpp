#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool v[10000];
int n, m, i, j, sum = 0, k;

bool isprime(int n)
{
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int a[25];
long long ans;
void dfs(int m, int sum, int startx)
{
    if (m == k)
    {
        if (isprime(sum))
            ans++;
        return;
    }
    for (int i = startx; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);
    return;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
