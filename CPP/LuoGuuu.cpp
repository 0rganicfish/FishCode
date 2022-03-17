#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
using namespace QAQ;

int A[3], B[3], t, i;
char c;
int main()
{
    while (cin >> c)
    {
        t = c - '0';
        for (i = 0; i < 3; i++)
            B[(i + t) % 3] = A[i] + A[(i + t) % 3];
        ++B[t % 3];
        for (i = 0; i < 3; i++)
            A[i] = B[i] % 1000000007;
    }
    cout << A[0];
}