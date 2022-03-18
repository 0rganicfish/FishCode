#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

int main()
{
    string str, s;
    cin >> str;
    s.resize(str.length());
    transform(str.begin(), str.end(), s.begin(), ::toupper);
    int g = 0, p = 0, l = 0, t = 0;
    for (auto i : s)
    {
        if (i == 'G')
            ++g;
        if (i == 'P')
            ++p;
        if (i == 'L')
            ++l;
        if (i == 'T')
            ++t;
    }
    while (g or p or l or t)
    {
        if (g)
            putchar('G'), --g;
        if (p)
            putchar('P'), --p;
        if (l)
            putchar('L'), --l;
        if (t)
            putchar('T'), --t;
    }
}

/*
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
*/