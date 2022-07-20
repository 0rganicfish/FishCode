#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
using namespace QAQ;

int main()
{
    double T, x, y, r, d;
    cin >> T;
    while (T--)
    {
        cin >> r >> x >> y >> d;
        int Ry = y >= r ? r : y,
            Ly = y <= -r ? -r : y,
            rx = x + d, lx = x - d;

        if (x + d >= r)
            if (x - d >= r)
                lx = rx = r;
            else
                rx = r, lx = x - d;
        else if (abs(x - d) >= r)
            if (x + d >= -r)
                rx = x + d, lx = -r;
            else
                lx = rx = -r;

        double ry = sqrt(r * r - rx * rx),
               ly = sqrt(r * r - lx * lx);
        printf("%d %d \n%f %f\n", rx, lx, ry, Ry);

        double ans = r * (acos((ry - Ry) / r) + acos((ly - Ly) / r));

        printf("%.12f\n", ans);
    }

    return 0;
}
