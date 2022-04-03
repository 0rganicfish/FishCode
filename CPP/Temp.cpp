#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;

string week[7] = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};
string DayOfTheWeek(int year, int month, int day)
{
    if (month <= 2)
        month += 12, year -= 1;
    int c = year / 100;
    year %= 100;
    int w = (year + year / 4 + c / 4 - 2 * c + (26 * (month + 1) / 10) + day - 1) % 7;
    return week[(w + 7) % 7];
}

int main()
{
    cout << DayOfTheWeek(2022, 4, 1);
}
