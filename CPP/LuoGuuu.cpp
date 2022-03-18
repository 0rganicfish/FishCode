#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

int main()
{
    string str, s, t = "GPLT";
    cin >> str;
    s.resize(str.length());
    transform(str.begin(), str.end(), s.begin(), ::toupper);

    str = "";
    for (int j = 0; j < 4; ++j)
        for (auto i : s)
            if (i == t[j])
                str += i;

    s = "";
    while (!str.empty())
        for (int j = 0; j < 4; ++j)
        {
            int p = str.find_first_of(t[j]),
                np = str.find_first_not_of(t[j]);
            if (p != -1)
                s += t[j], str.erase(p, 1);
        }
    cout << s;
}