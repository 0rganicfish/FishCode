a[1]*b[1-1] + b[1]*a[1-1]

a[2]\*b[2-1]

1618708103 s

```C++ {.line-numbers}
vector<int> er;
string jin(string x)
{
    string ans;
    reverse(all(x))
    for (int i = x.length() - 1; i >= 0; i--)
    {
        int t = isdigit(x[i]) ? x[i] - '0' : x[i] - 'A' + 10;
        while (t)
            er.push_back(t & 1), t >>= 1;
        for (int i = 0; i < er.size() % 4; ++i)
            er.push_back(0);
    }
    for (int i = 0; i < er.size() % 3; ++i)
        er.push_back(0);
    for (int i = 0; i < er.size(); i += 3)
    {
        int t = 0, n = 1;
        for (int j = 0; j < 3; ++j, n *= 2)
            t += er[i + j] * n;
        ans += (t + '0');
    }
    reverse(all(ans));
    return ans;

```