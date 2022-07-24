#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
using namespace QAQ;

#define vi vector<int>

int lds(vi arr)
{
    vi lds;
    int i, j, n = arr.size();

    for (i = 0; i < n; i++)
        lds.push_back(1);

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;

    return *max_element(all(lds));
}

int lis(vi arr)
{
    vi lis;
    int i, j, n = arr.size();

    for (i = 0; i < n; i++)
        lis.push_back(1);
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j] + 1);

    return *max_element(all(lis));
}

vi generator(int n)
{
    vi temp, arr;
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
        temp.push_back(i);

    do
    {
        int len = max(lis(arr), lds(arr));
        if (len < ans)
            ans = len, arr = temp;
    } while (next_permutation(all(temp)));

    cout << ans << endl;
    return arr;
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vi temp = generator(n);
        for (int i = 0; i < temp.size(); ++i)
            cout << temp[i] << " ";
        cout << endl;
    }
    return 0;
}