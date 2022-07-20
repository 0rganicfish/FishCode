#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

int main()
{
    double T, r, x, y, d;

    cin >> T;
    while (T--)
    {
        cin >> r >> x >> y >> d;
        double lx, ly, rx, ry;

        if (abs(x - d) < 2 * r)
            lx = x - d, ly = sqrt(r * r - pow(x - d, 2));
        else
        {
            if (abs(y) <= r)
                ly = y, lx = sqrt(r * r - y * y);
            else
                ly = r, lx = 0;
        }

        if (abs(x + d) < 2 * r)
            rx = x + d, ry = sqrt(r * r - pow(x + d, 2));
        else
        {
            if (abs(y) <= r)
                ry = y, rx = sqrt(r * r - y * y);
            else
                ry = r, rx = 0;
        }
        printf("(%f, %f)  (%f, %f)\n", lx, ly, rx, ry);

        double cosA = (lx * rx + ly * ry) / (sqrt(lx * lx + ly * ly) * sqrt(rx * rx + ry * ry));
        printf("%.12f\n", acos(cosA) * r);
    }
}