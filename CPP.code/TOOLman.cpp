#include <bits/stdc++.h>
using namespace std;

bool is_prefix(string temp, string str)
{
    if (temp.length() > str.length())
        return 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] != temp[i])
            return 0;
    return 1;
}

string lexicographically(string input, string str)
{
    string temp = input;
    sort(input.begin(), input.end());
    if (is_prefix(input, str))
        return temp;
    return "-1";
}

int main()
{
    int n, m, l;
    string s, ans;
    cin >> m;
    while (m--)
    {
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
        {
            string hui = string(s.begin(), s.begin() + i);
            hui += string(hui.rbegin(), hui.rend());
            if ((ans = lexicographically(hui, s)) != "-1") {cout << ans << endl; break;}
        }
    }

    return 0;
}
