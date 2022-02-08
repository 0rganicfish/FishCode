#include <bits/stdc++.h>
using namespace std;

int KMP(string txt, string a)
{
    int n = txt.length(), m = a.length();
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (txt[i] != a[j])
            i = j + 1;
        else if (j == m - 1 and txt[i] == a[j])
            return n - i;
    }
    return -1;
}

int main()
{
    string txt, a;
    txt = "aaabaa", a = "aab";
    cout << KMP(txt, a);
}// aavbaab