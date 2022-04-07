#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PII pair<int, int>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace QAQ;

int main()
{
    
}

//* 04-06

// 摸鱼了

//* 04-05

int main()
{
    string s;
    cin >> s;
    for (auto i : s)
        if (i >= 'u')
            putchar('u');
        else if (i >= 'o' and i < 'u')
            putchar('o');
        else if (i >= 'i' and i < 'o')
            putchar('i');
        else if (i >= 'e' and i < 'i')
            putchar('e');
        else
            putchar('a');
} // aeiou

#define PSD pair<string, double>
bool cmp(const PSD &a, const PSD &b)
{
    return a.second == b.second ? a.first > b.first : a.second < b.second;
}

int main()
{
    double n, m;
    vector<PSD> npy;
    string ans, name, inp;
    cin >> n >> m >> ans;
    for (int i = 0; i < m; ++i)
    {
        cin >> name >> inp;
        double sum = 0;
        for (int j = 0; j < n; ++j)
            if (inp[j] == ans[j])
                ++sum;
        npy.push_back(make_pair(name, sum / n * 100.));
    }
    sort(all(npy), cmp);
    cout << npy.back().first << endl
         << fixed << setprecision(2) << npy.back().second;
}

int main()
{
    string a, b, c, s;
    cin >> a >> b >> b >> c >> a >> c;
    int t;
    for (cin >> t; t--;)
    {
        cin >> s;
        if (s == a)
            cout << b;
        else if (s == b)
            cout << c;
        else if (s == c)
            cout << a;
        else
            cout << "Fake";
        cout << endl;
    }
}

//* 04-04

const ll Max = 1e3, len = Max / log(Max) + 100;
vector<ll> primer(len, 0);
vector<bool> P(Max, 0);

void ola(int x)
{
    for (ll i = 2, cnt = 0; i <= x; ++i)
    {
        if (!P[i])
            primer[cnt++] = i;
        for (ll j = 0; primer[j] <= x / i; ++j)
        {
            P[primer[j] * i] = 1;
            if (i % primer[j] == 0)
                break;
        }
    }
}

bool PerfectSquare(ll n)
{
    for (ll t = 1; n > 0; t += 2)
        n -= t;
    return !n;
}

int N = 1e7 + 5, L = N / log(N) + 100;
ll *f = new ll[N], *primes = new ll[L];
void ola(int n)
{
    for (int i = 2, cnt = 0; i <= n; i++)
    {
        if (!f[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) //要确保质数的第i倍是小于等于n的。
        {
            f[primes[j] * i] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}

bool isprime(ll n)
{
    if (n < 2 or n & 1 == 0)
        return false;
    for (ll i = 3; i <= n / i; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

bool full(ll n)
{
    for (ll i = 2; i <= n / i; ++i)
        while (n % (i * i) == 0)
            n /= i * i;
    return n == 1;
}

ll ksc(ll x, ll y, ll mod)
{
    ll z = (long double)x / mod * y;
    ll res = (ull)x * y - (ull)z * mod;
    return (res + mod) % mod;
}

int main()
{
    cout << ksc(12345, 123456, 1e12);
}

//* 04-03

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        int a[30] = {0}, b[30] = {0};
        ll ans = 0;
        cin >> n;

        for (int i = 1; i <= n; ++i)
            cin >> a[i], b[i] = a[i];
        sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);

        for (int i = 1; i <= n; ++i)
            a[i] -= b[i - 1];
        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; ++i)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; ++i)
            ans += a[i];
        cout << ans << endl;
    }
}

ll jin(int n, const int x)
{
    string ans;
    for (int i = 8; n; n /= x)
    {
        int t = n % x;
        ans = char(t + '0') + ans;
    }
    return count_if(all(ans), [](char c)
                    { return c == '1'; });
}

int main()
{
    int T, n, x, y;
    cin >> T;
    while (T--)
    {
        cin >> n >> x >> y;
        int xx = jin(n, x), yy = jin(n, y);
        if (xx > yy)
            putchar('>');
        else if (xx < yy)
            putchar('<');
        else
            putchar('=');
        putchar('\n');
    }
}

ll fpow(ll a, ll x, ll mod)
{
    ll ans = 1;
    while (x)
    {
        if (x & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod, x >>= 1;
    }
    return ans % mod;
}

int main()
{
    ll a, b, c, d, mod;
    cin >> a >> b >> c >> d >> mod;
    a %= mod, b %= mod, c *= d, a *= b, a %= mod;
    ll ans = 1;
    while (c)
    {
        if (c & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod, c >>= 1;
    }
    cout << ans % mod;
    return 0;
}

#define vecint vector<int>
vecint multi(vecint x, int y) // x > 0, y > 0, x高精 y低精
{
    vecint ans;
    int t = 0;
    for (int i = 0; i < x.size() or t; ++i)
        t += x[i] * y, ans.push_back(t % 10), t /= 10;
    return ans;
}

ll fpow(ll a, ll x, ll mod) // x高精
{
    ll ans = 1;
    while (x)
    {
        if (x & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod, x >>= 1;
    }
    return ans % mod;
}

int main()
{
    cout << 1e100000;
}

//* ll ago

map<string, int> s = {{"Ox", 1}, {"Tiger", 2}, {"Rabbit", 3}, {"Dragon", 4}, {"Snake", 5}, {"Horse", 6}, {"Goat", 7}, {"Monkey", 8}, {"Rooster", 9}, {"Dog", 10}, {"Pig", 11}, {"Rat", 12}};
string words[8];
map<string, int> peo;
int T;

int main()
{
    peo["Bessie"] = 1;
    cin >> T;
    getchar();
    while (T--)
    {
        for (int i = 0; i < 8; ++i)
            cin >> words[i];
        int f = words[3] == "next" ? 1 : -1;
        string year = words[4], name1 = words[0], name2 = words[7];
        int t = s[year] * f + peo[name2];

        peo.insert(make_pair(name1, 1));
    }
    // https://www.acwing.com/solution/content/100312/
    return 0;
}

#define Paint pair<int, int>
queue<Paint> q;
int n, m, x, y;
int mpa[500][500];
bool vis[500][500] = {false};

void fang(int xx, int yy)
{
    int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
    int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
    for (int i = 0; i < 8; ++i)
    {
        int xi = dx[i] + xx, yj = dy[i] + yy;
        if (xi < 1 or xi > n or yj < 1 or yj > m or vis[xi][yj])
            continue;
        vis[xi][yj] = true, mpa[xi][yj] = mpa[xx][yy] + 1;
        q.push(make_pair(xi, yj));
    }
}

signed main()
{

    cin >> n >> m >> x >> y;
    memset(mpa, -1, sizeof(mpa));
    mpa[x][y] = 0, vis[x][y] = true, q.push(make_pair(x, y));

    while (!q.empty())
    {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        fang(xx, yy);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%-5d", mpa[i][j]);
        puts("");
    }
}