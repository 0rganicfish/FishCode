#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

class Sch
{
public:
    ll num;

private:
    ll year, month, day, days;
    ll hour, min, sec, times;
    ll total;
    int mon[13] = {366, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool run(const int year)
    {
        return ((year % 4 == 0 || year % 400 == 0) && year % 100);
    }

public:
    Sch(int n, int y, int m, int d, int h, int mm, int s)
    {
        year = y, month = m, day = d, hour = h, min = mm, sec = s, num = n;
        run(y) ? (mon[0] = 366, mon[2] = 29) : (mon[0] = 365, mon[2] = 29);

        days = y * mon[0] + mon[m] * m + d;
        times = h * 3600 + m * 60 + s;
        total = days * 3600 * 24 + times;
    }
    Sch() {}

public:
    friend ostream &operator<<(ostream &out, const Sch &a)
    {
        return out << "The urgent schedule is No." << a.num << ":"
                   << a.year << "/" << a.month << "/" << a.day << " "
                   << a.hour << ":" << a.min << ":" << a.sec << endl;
    }
    friend bool cmp(const Sch &a, const Sch &b);
};

bool cmp(const Sch &a, const Sch &b)
{
    return a.total > b.total;
}

int main()
{
    vector<Sch> a;
    while (1)
    {
        int y, m, d, h, mm, s, n;
        cin >> n;
        if (!n)
            break;
        scanf("%d/%d/%d %d:%d:%d", &y, &m, &d, &h, &mm, &s);
        Sch t(n, y, m, d, h, mm, s);
        a.push_back(t);
    }
    sort(all(a), cmp);
    cout << a.back();
}