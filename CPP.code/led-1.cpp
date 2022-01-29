#include <bits/stdc++.h>
using namespace std;

inline int Pow(int x, int n)
{
    int ans = x;
    while (--n)
        ans *= x;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int m = pow(10, n - 1);
    for (int i = m; i < 10 * m; i++)
    {
        int sum = 0, t = i;
        while (t)
            sum += Pow(t % 10, n), t /= 10;
        if (sum == i)
            printf("%d\n", i);
    }
    return 0;
}
