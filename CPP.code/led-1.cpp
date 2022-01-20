#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    if (n < 2 or n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int mod = 12400;
    for (int i = 2; i <= mod / 2; i++)
        if (mod % i == 0 and isprime(i))
            cout << i << " ";
}