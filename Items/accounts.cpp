#include <bits/stdc++.h>
using namespace std;

struct accounts
{
    string ac_c, ps_c, ac_s, pa_s; // c-->check, s-->scan
} a[20];

void scan(accounts ac, accounts ps) { cin >> ac >> ps; }
void print(accounts ac,accounts ps) { cout << ac << " " << ps << endl; }

int main()
{
    int num, i, j;
    cin >> num;
    for (i = 0; i < num; i++)
        scan(a[i].ac_c, a[i].ps_c);
    for (i = 0; i < num; i++)
        print(a[i].ac_c, a[i].ps_c);
}