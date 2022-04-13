#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

class te
{
private:
    int num;

public:
    void scan() { cin >> this->num; }
    void print() const { cout << this->num << endl; }
};

int main()
{
    te t1;
    t1.scan(), t1.print();
}