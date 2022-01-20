#include <bits/stdc++.h>
using namespace std;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool run(int x)
{
    if ((x % 4 == 0 and x % 100) or x % 400 == 0)
        return true;
    return false;
}
bool hui(string s)
{
    for (int i = 0, l = s.length(); i < l; i++)
        if (s[i] != s[l - i - 1])
            return false;
    return true;
}
string addyear(int x)
{
    int y = x / 10000, m = x / 100 % 100, d = x % 100;
    if (run(y))
        month[2] = 29;
    else
        month[2] = 28;
    if (++d > month[m])
        m++, d = 1;
    if (m > 12)
        m = 1, y++;
    string ans = to_string(y * 10000 + m * 100 + d);
    if (y < 10)
        ans = "000" + ans;
    else if (y >= 10 and y < 100)
        ans = "00" + ans;
    else if (y >= 100 and y < 1000)
        ans = "0" + ans;
    return ans;
}

int main()
{
    int n, m;
    string t;
    cin >> n >> m;
    for (int i = n; i <= m; t = addyear(i), i = stoi(t))
        if (hui(t))
            cout << t << endl;
}