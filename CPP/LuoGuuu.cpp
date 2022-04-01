#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;

class F
{
private:
    int n;

public:
    F(int x = 1) : n(x) {}
    void in() { cin >> n; }
    void out() { cout << n * n << endl; }
    bool operator()(F x, F y) { return x.n < y.n; }
};

int main()
{
    int n = 23;
    cout << (n |= 2);
}
