#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

map<string, int> s = {{"Ox", 1}, {"Tiger", 2}, {"Rabbit", 3}, {"Dragon", 4}, {"Snake", 5}, {"Horse", 6}, {"Goat", 7}, {"Monkey", 8}, {"Rooster", 9}, {"Dog", 10}, {"Pig", 11}, {"Rat", 12}};
string words[8];
map<string, int> peo;
int T;

int main()
{
    peo["Bessie"] = 1;
    cin >> T;
    getchar();
    while (T--)
    {
        for (int i = 0; i < 8; ++i)
            cin >> words[i];
        int f = words[3] == "next" ? 1 : -1;
        string year = words[4], name1 = words[0], name2 = words[7];
        int t = s[year] * f + peo[name2];

        peo.insert(make_pair(name1, 1));
    }
    // https://www.acwing.com/solution/content/100312/
    return 0;
}