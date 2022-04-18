#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

int main()
{
}

//* 04-16_ICPC_Pre
// https://ac.nowcoder.com/acm/contest/32705#question
namespace ICPC_Pre
{
    // A 签到
    int main()
    {
        for (int k = 0; k < 2; ++k)
        {
            ll a, ans = 0, mie[] = {6, 3, 2, 1, 2};
            for (int i = 0; i < 5; ++i)
                cin >> a, ans += a * mie[i];
            cout << ans << " ";
        }
        return 0;
    }

    // B 幂次
    int main()
    {
        string s;
        cin >> s;
        ll up = 1, down, dd, sum = 0, len = s.length() - 1;
        down = dd = 1 << len;
        for (int i = len; i >= 0; --i)
            sum += up * dd * (s[i] - '0'), up *= 3, dd /= 2;

        cout << sum / down;
        if (sum %= down)
        {
            ll gcd = __gcd(sum, down);
            cout << " " << sum / gcd << "/" << down / gcd;
        }
        return 0;
    }

    // C- Wordle
    int main()
    {
        string ans;
        cin >> ans;
        for (int i = 1; i <= 7; ++i)
        {
            string a, t;
            cin >> a;
            for (int j = 0; j < 5; ++j)
            {
                char c = 'X';
                for (int k = 0; k < 5; ++k)
                    if (a[j] == ans[k])
                        if (j == k)
                        {
                            c = 'G';
                            break;
                        }
                        else
                            c = 'Y';
                t += c;
            }
            if (t == "GGGGG")
            {
                cout << "WINNER";
                return 0;
            }
            if (i == 7)
                cout << "LOSER";
            else
                cout << t << endl;
        }
        return 0;
    }
};

//* 04-15

namespace Apr_15
{

    //
    //
    //
    class People
    {
    private:
        string name;

    public:
        People(){};
        People(string name_) : name(name_){};

    public:
        void set_name(string name_) { name = name_; }
        string get_name() const { return name; }

    protected:
        string id;
        void set_id(string id_) { this->id = id_; }
        string get_id() const { return this->id; }
    };

    class Stu : public People
    {
    private:
        int score;

    public:
        Stu(){};
        Stu(int score_) : score(score_){};
        Stu(string name_, int score_) : People(name_), score(score_){};

    public:
        void set_score(int score_) { score = score_; }
        int get_score() const { return score; }
        void print_info()
        {
            cout << "name: " << this->get_name() << endl
                 << "score: " << this->get_score() << endl;
        }
    };

    class Address : public Stu
    {
    private:
        string county;

    public:
        Address(){};
        Address(string county_) : county(county_){};
        Address(string county_, string name_, int score_) : county(county_), Stu(name_, score_){};

    public:
        void set_county(string county_) { county = county_; }
        string get_county() const { return county; }
        void print_info()
        {
            cout << "county: " << this->get_county() << endl
                 << "name: " << this->get_name() << endl
                 << "score: " << this->get_score() << endl;
        }
    };

    int main()
    {
        string name, county;
        int score;
        cin >> county >> name >> score;

        Address mie(county, name, score);
        mie.Stu::print_info();
    }

    //
    //
    //
    class Point
    {
    private:
        double x, y;

    public:
        Point();
        Point(double x_, double y_);
        double distance();
        double distance(const Point &p);
        double getX() { return x; }
        double getY() { return y; }
        void setX(double x_);
        void setY(double y_);
    };
    /* 你的代码将被嵌入这里 */

    Point::Point(double x_, double y_) : x(x_), y(y_){};
    double Point::distance()
    {
        return sqrt((getX() * getX() + getY() * getY()));
    }

    class Circle : public Point
    {
    public:
        Circle(Point p, double R) : Point(p), rad(R) {}
        string judge(Point p)
        {
            double dist = sqrt((pow(p.getX() - x, 2) + pow(p.getY() - y, 2)));
            if (dist > rad)
                return "outside";
            else if (dist < rad)
                return "inside";
            else
                return "on";
        }

    private:
        double rad, x, y;
    };

    int main()
    {
        double x1, y1, x2, y2, r;
        cin >> x1 >> y1 >> x2 >> y2 >> r;
        Point p(x1, y1);
        Point ctr(x2, y2);
        Circle c(ctr, r);
        cout << setprecision(3) << p.distance() << " " << c.judge(p) << endl;
    }
};

//* 04-09
// 大墨鱼

//* 04-08
namespace Apr_08
{
#define PI acos(-1)
    int main()
    {
        double T, r, h;
        for (cin >> T; T--;)
        {
            cin >> r >> h;
            int num = h / (2 * r);
            double yuan = 3. / 4. * PI * r * r * num,
                   zhu = PI * r * r * h;
            printf("%.2f\n", zhu - yuan);
        }
        return 0;
    }
    //
    //
    // http://lx.lanqiao.cn/problem.page?gpid=T2730
    struct node
    {
        ll like, t0;
        bool f, ans;
        node()
        {
            memset(this, 0, sizeof(node));
        }
    };

    bool cmp(PLL a, PLL b)
    {
        return a.first < b.first;
    }

    int main()
    {
        ll N, T, L, ts, id;
        map<ll, node> tie;
        vector<PLL> tmp;

        cin >> N >> T >> L;
        for (ll i = 0; i < N; ++i)
        {
            cin >> ts >> id;
            tmp.push_back(make_pair(ts, id));
        }
        sort(all(tmp), cmp);

        for (ll i = 0; i < N; ++i)
        {
            ll id = tmp[i].second, ts = tmp[i].first;
            ++tie[id].like;

            if (!tie[id].f)
                tie[id].t0 = ts, tie[id].f = 1;

            if (tie[id].like >= L and ts - tie[id].t0 < T)
                tie[id].ans = 1;
        }
        for (map<ll, node>::iterator i = tie.begin(); i != tie.end(); i++)
            if (i->second.ans)
                cout << i->first << endl;
        return 0;
    }
    //
    //
    ll read()
    {
        char c;
        ll ans = 0, f = 1;
        while ((c = getchar()) and !isdigit(c))
            if (c == '-')
                f = -1;
        while (isdigit(c))
            ans = ans * 10 + c - '0', c = getchar();
        return f * ans;
    }

    void write(ll n)
    {
        if (n < 0)
            putchar('-'), n = -n;
        if (n > 9)
            write(n / 10);
        putchar(n % 10 + '0');
    }

    ll fpow(ll a, ll b, ll mod)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                (ans *= a) %= mod;
            (a *= a) %= mod, b >>= 1;
        }
        return ans % mod;
    }

    vector<int> yin(ll n)
    {
        vector<int> ans;
        for (int i = 1; i <= n / i; ++i)
            if (n % i == 0)
            {
                ans.push_back(i);
                if (n / i != i)
                    ans.push_back(n / i);
            }
        return ans;
    }

    set<ll> zhiyin(ll n)
    {
        set<ll> a;
        for (ll i = 2; i <= n; ++i)
            while (n != i)
                if (n % i == 0)
                    a.insert(i), n /= i;
                else
                    break;
        a.insert(n);
        return a;
    }

    bool perfect(ll n)
    {
        for (ll i = 2; i <= n / i; ++i)
            while (n % (i * i) == 0)
                n /= i * i;
        return n == 1;
    }
    //
    //
    const ll Max = 1e5 + 5;
    ll a[Max], f[Max] = {0};
    int main()
    {
        ll n, d = 0, maxx = 0;
        cin >> n;

        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);

        for (ll i = 0; i < n - 1; ++i)
            ++f[a[i + 1] - a[i]];
        for (ll i = 0; i < Max; ++i)
            if (f[i] > maxx)
                maxx = f[i], d = i;

        cout << (d ? (a[n - 1] - a[0]) / d + 1 : n);

        return 0;
    }
    //
    //
    int main()
    {
        ll n, ans = 0;
        cin >> n;
        for (ll i = 1; i <= n; ++i)
            for (ll t = i; t >= 0; t /= 10)
                if (t % 10 == 1 or t % 10 == 0 or t % 10 == 2 or t % 10 == 9)
                {
                    ans += i;
                    break;
                }
        cout << ans;
        return 0;
    }
    //
    //
    int main()
    {
        int n, x, num;
        queue<int> q;
        cin >> n;
        while (n--)
        {
            cin >> x;
            if (x == 1)
                cin >> num, q.push(num);
            if (x == 2)
                if (q.empty())
                    cout << "Invalid\n";
                else
                    cout << q.front() << endl, q.pop();
            else if (x == 3)
                cout << q.size() << endl;
        }
    }
    //
    //
    struct
    {
        double a, b, c, avg;
        string name;
    } stu[105];

    int main()
    {
        int T, n;
        while (cin >> T)
        {
            cin >> n;
            for (int i = 0; i < n; ++i)
                cin >> stu[i].name >> stu[i].a >> stu[i].b >> stu[i].c,
                    stu[i].avg = (stu[i].a + stu[i].b + stu[i].c) / 3.;
            for (int i = n - 1; i >= 0; --i)
                if (stu[i].avg >= 60)
                    cout << stu[i].name << " "
                         << stu[i].a << " "
                         << stu[i].b << " "
                         << stu[i].c << " ",
                        printf("%.2f\n", stu[i].avg);
        }
    }
};

//* 04-07

// 又摸鱼了

//* 04-06

// 摸鱼了

//* 04-05
namespace Apr_05
{
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
//
//
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

    //
    //
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
};

//* 04-04
namespace Apr_04
{
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
    //
    //
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
};

//* 04-03
namespace Apr_03
{
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
    //
    //

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
    //
    //
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
//
//
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
};

//* ll ago
namespace LL
{
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
//
//
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
};