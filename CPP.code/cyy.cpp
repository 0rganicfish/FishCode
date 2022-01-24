#include <bits/stdc++.h>
using namespace std;
typedef vector<int> intvec;

int main()
{
    intvec bai;
    for (int i = 1; i <= 100; i++)
        bai.push_back(i);
    for (auto i : bai)
        cout << i << " ";
}