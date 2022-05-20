#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

int main()
{
    // // Generate data
    // const unsigned arraySize = 32768;
    // int data[arraySize];

    // for (unsigned c = 0; c < arraySize; ++c)
    //     data[c] = std::rand() % 256;

    // // !!! With this, the next loop runs faster.
    // // std::sort(data, data + arraySize);

    // // Test
    // clock_t start = clock();
    // long long sum = 0;
    // for (unsigned i = 0; i < 100000; ++i)
    // {
    //     for (unsigned c = 0; c < arraySize; ++c)
    //     { // Primary loop
    //         int t = (data[c] - 128) >> 31;
    //         sum += ~t & data[c];
    //     }
    // }

    // double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    // std::cout << elapsedTime << '\n';
    // std::cout << "sum = " << sum << '\n';

    int m = 121;
    int t = (m - 128) >> 31;
    cout << (~t & m);
}
