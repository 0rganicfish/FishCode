#include <bits/stdc++.h>
using namespace std;

int a[100020];
int ans[100020][2];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        int as = 0, cnt = 0;
        for (int i = 1, j = 1; i <= n; i = ++j)
        {
            while (j < n && a[j] <= a[j + 1])
                ++j;
            if (a[j] - a[i] > as)
                as = a[j] - a[i], cnt = 1, ans[1][0] = i, ans[1][1] = j;
            else if (a[j] - a[i] == as)
                ans[++cnt][0] = i, ans[cnt][1] = j;
        }
        for (int i = 1; i <= cnt; ++i)
            printf("%d %d ", ans[i][0], ans[i][1]);
        printf("\n");
    }
    return 0;
}