#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

namespace sds
{
#define vi vector<int>
    int binary(vi arr, int start, int end, int value)
    {
        int l = start, r = end - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (arr[m] == value)
                return m;
            else if (arr[m] < value)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }

    int length(vi arr, bool lis)
    {
        vi temp{arr[0]};
        int end = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            bool f = arr[i] > temp[end];
            if (!lis)
                f = arr[i] <= temp[end];

            if (f)
                temp.push_back(arr[i]), end++;
            else
            {
                int pos = binary(temp, 0, temp.size(), arr[i]);
                temp[pos] = arr[i];
            }
        }
        for (int i = 0; i < temp.size(); ++i)
            cout << temp[i] << " ";
        cout << endl;

        return end + 1;
    }

    // int Max(vi arr) { return max(length(arr, true), length(arr, false)); }
};

//* 06-30

namespace Jun_30
{
    //
    //
    class Point
    {
    private:
        double x, y;

    public:
        Point() { x = 0, y = 0; };
        Point(double xx, double yy) : x(xx), y(yy){};

        double xx() const { return x; };
        double yy() const { return y; };
    };

    class Rec : public Point
    {
    private:
        double height, width;

    public:
        Rec() {}
        Rec(const Point &a, const Point &b)
        {
            height = abs(a.yy() - b.yy());
            width = abs(a.xx() - b.xx());
        }

        double Area() const
        {
            return width * height;
        }
    };

    int main()
    {
        Point dot1(1.0, 2.0), dot2(4.0, 6.0);
        Rec rec(dot1, dot2);
        cout << fixed << setprecision(2) << rec.Area();
        return 0;
    }
};

//* 05-20

namespace May_20
{
    /* 请在这里填写答案 */

    class MyTime
    {
    private:
        int h, m, s;

    public:
        MyTime(int hh, int mm, int ss) : h(hh), m(mm), s(ss) {}
        MyTime() { h = 0, m = 0, s = 0; };

        friend istream &operator>>(istream &in, MyTime &a)
        {
            return in >> a.h >> a.m >> a.s;
        }
        friend ostream &operator<<(ostream &out, const MyTime &a)
        {
            return out << a.h << ":" << a.m << ":" << a.s << endl;
        }

        MyTime operator++()
        {
            s++;
            if (s == 60)
                m++, s = 0;
            if (m == 60)
                h++, m = 0;
            if (h == 24)
                h = 0;
            return *this;
        }
    };

    int main()
    {
        MyTime t1, t2(23, 59, 59), t3;
        cin >> t3;
        ++t1;
        cout << t1 << endl;
        ++t2;
        cout << t2 << endl;
        ++t3;
        cout << t3 << endl;
        return 0;
    }

};

//* 05-13
namespace Fri_13
{

    class Sch
    {
    public:
        ll num;

    private:
        ll year, month, day, days;
        ll hour, min, sec, times;
        ll total;
        int mon[13] = {366, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool run(const int year)
        {
            return ((year % 4 == 0 || year % 400 == 0) && year % 100);
        }

    public:
        Sch(int n, int y, int m, int d, int h, int mm, int s)
        {
            year = y, month = m, day = d, hour = h, min = mm, sec = s, num = n;
            run(y) ? (mon[0] = 366, mon[2] = 29) : (mon[0] = 365, mon[2] = 29);

            days = y * mon[0] + mon[m] * m + d;
            times = h * 3600 + m * 60 + s;
            total = days * 3600 * 24 + times;
        }
        Sch() {}

    public:
        friend ostream &operator<<(ostream &out, const Sch &a)
        {
            return out << "The urgent schedule is No." << a.num << ":"
                       << a.year << "/" << a.month << "/" << a.day << " "
                       << a.hour << ":" << a.min << ":" << a.sec << endl;
        }
        friend bool cmp(const Sch &a, const Sch &b);
    };

    bool cmp(const Sch &a, const Sch &b)
    {
        return a.total > b.total;
    }

    int main()
    {
        vector<Sch> a;
        while (1)
        {
            int y, m, d, h, mm, s, n;
            cin >> n;
            if (!n)
                break;
            scanf("%d/%d/%d %d:%d:%d", &y, &m, &d, &h, &mm, &s);
            Sch t(n, y, m, d, h, mm, s);
            a.push_back(t);
        }
        sort(all(a), cmp);
        cout << a.back();
    }
    //
    //
    class Time
    {
    private:
        int hours, minutes, seconds;

    public:
        Time(int h = 0, int m = 0, int s = 0);
        Time operator+(Time &);
        void DispTime();
    };

    /* 请在这里填写答案 */

    Time::Time(int h, int m, int s)
    {
        hours = h, minutes = m, seconds = s;
    }
    Time Time::operator+(Time &t)
    {
        Time tt;
        tt.seconds = t.seconds + seconds;
        tt.minutes += t.minutes + minutes + (tt.seconds / 60);
        tt.hours += t.hours + hours + (tt.minutes / 60);
        tt.hours %= 24, tt.seconds %= 60, tt.minutes %= 60;
        return tt;
    }
    void Time::DispTime()
    {
        cout << hours << "h:" << minutes << "m:" << seconds << "s\n";
    }

    int main()
    {
        Time tm1(8, 75, 50), tm2(0, 6, 16), tm3;
        tm3 = tm1 + tm2;
        tm3.DispTime();
        return 0;
    }
}

//* 04-29
namespace Apr_29
{
    int main()
    {
        float x, y, r;
        cin >> x >> y >> r;
        float ans = r * 2 * acos(-1);
        cout << "Point constructor called\nCircle constructor called\n"
             << fixed << setprecision(2) << ans << endl
             << "Circle destructor called\nPoint destructor called\n";
        return 0;
    }
    //
    //
    class Animal
    {
    protected:
        int age;

    public:
        Animal(int _age) : age(_age) {}
        int getAge() const { return age; }
    };
    class Dog : public Animal
    {
    private:
        string info;

    public:
        Dog(int _age, string _info) : Animal(_age), info(_info) {}
        void showInfo()
        {
            cout << "age:" << age << endl
                 << "color:" << info << endl;
        }
    };

    int main()
    {
        Animal ani(5);
        cout << "age of ani:" << ani.getAge() << endl;
        Dog dog(5, "black");
        cout << "info of dog:" << endl;
        dog.showInfo();
    }

    //
    //
    class Student
    {
    public:
        Student(int n, string nam, char s)
        {
            num = n;
            name = nam;
            sex = s;
        }
        ~Student() {}

    protected:
        int num;
        string name;
        char sex;
    };

    class Student1 : public Student
    {
    private:
        int age;
        string address;

    public:
        Student1(int _num, string _name, char _sex, int _age, string _address) : Student(_num, _name, _sex), age(_age), address(_address) {}

        void show()
        {
            cout << "num: " << num << endl
                 << "name: " << name << endl
                 << "sex: " << sex << endl
                 << "age: " << age << endl
                 << "address: " << address << endl
                 << endl;
        }
    };

    /* 请在这里添加派生类定义 */

    int main()
    {
        Student1 stud1(10010, "Wang-li", 'f', 19, "115 Beijing Road,Shanghai");
        Student1 stud2(10011, "Zhang-fun", 'm', 21, "213 Shanghai Road,Beijing");
        stud1.show();
        stud2.show();
        return 0;
    }
};

//* 04-25
namespace Apr_25 //主要更新了 class Stu；
{
    class People
    {
    public:
        People(){};
        People(string id_, string name_) : id(id_), name(name_){};

    protected:
        string id, name;
    };

    class Stu : public People
    {
    private:
        int score;

    public: //构造析构区
        Stu(){};
        Stu(int score_) : score(score_){};
        Stu(string id_, string name_, int score_) : People(id_, name_), score(score_){};

    public: //普通的public区
        void set_score(int score_) { score = score_; }
        int Score() const { return score; }
        static Stu min(const Stu a, const Stu b)
        {
            return a < b ? a : b;
        }

    public: //重载区
        bool operator<(const Stu &a) const
        {
            return score < a.score;
        }
        Stu operator++() // 前缀自增：++mie;
        {
            score++;
            return *this;
        }
        Stu operator++(int) // 后缀自增：mie++:
        {
            return ++*this;
        }
        Stu operator+(const Stu a) const // 对象之间相加 --> this + a
        {
            return Stu(name + " | " + a.name,
                       id + " | " + a.id,
                       score + a.score);
        }
        Stu operator+(const int x) const //不改变原来值的尽量加const修饰
        {
            return Stu(score + x);
        }
        Stu operator+=(const Stu a) //与对象之间的 +=
        {
            return *this = a + *this;
        }
        Stu operator+=(const int x)
        {
            return *this = Stu(name, id, score + x);
        }
        friend Stu operator+(const int x, const Stu stu)
        {
            return Stu(x + stu.score);
        }

        friend ostream &operator<<(ostream &out, const Stu &a)
        {
            return out << "id: " << a.id << endl
                       << "name: " << a.name << endl
                       << "score: " << a.score << endl
                       << endl;
        }
        friend istream &operator>>(istream &in, Stu &a)
        {
            return in >> a.id >> a.name >> a.score;
        }
    };

    class Tea : public People
    {
    private:
        int salary;

    public:
        Tea() {}
        Tea(int _salary) : salary(_salary) {}
        Tea(string _id, string _name, int _salary) : People(_id, _name), salary(_salary) {}

    public:
        friend ostream &operator<<(ostream &out, const Tea &a)
        {
            return out << "id: " << a.id << endl
                       << "name: " << a.name << endl
                       << "salary: " << a.salary << endl
                       << endl;
        }
        friend istream &operator>>(istream &in, Tea &a)
        {
            return in >> a.id >> a.name >> a.salary;
        }
    };

    int main()
    {
        Stu mie("081001", "mie", 12),
            fish("081002", "fish", 14);
        fish++, ++mie;
        mie += 3;

        cout << "The min is :\n"
             << Stu::min(mie, fish);

        Tea sea("022001", "sea", 2022);
        cout << sea;
    }
};

//* 04-22
namespace Apr_22
{
    class Complex
    {
    private:
        double x, y;

    public:
        Complex(double _x, double _y) : x(_x), y(_y) {}
        Complex() { x = y = 0; }

    public:
        Complex operator-()
        {
            return Complex(-x, -y);
        }
        Complex operator+(const Complex &a)
        {
            return Complex(a.x + x, a.y + y);
        }
        friend istream &operator>>(istream &in, Complex &a)
        {
            return in >> a.x >> a.y;
        }
        friend ostream &operator<<(ostream &out, const Complex &a)
        {
            return out << "(" << a.x << ", " << a.y << ")" << endl;
        }
    };

    int main()
    {
        Complex a, b;
        cin >> a >> b;
        cout << a + b << a + (-b) << b;
    }
    //
    //
    //
    class Donator
    {
    private:
        string name;
        float money; //单位：元
    public:
        void setName(string _name);
        void setMoney(float _money);
        string getName() { return name; }
        float getMoney() { return money; }

        /* 你编写的代码将被嵌入这里*/
        static float totalMoney;
        static void printTotal()
        {
            cout << "total:" << totalMoney << endl;
        }

        friend string getMaxName(const Donator a[], const int n)
        {
            float maxx = 0;
            string ans;
            for (int i = 0; i < n; ++i)
                if (a[i].money > maxx)
                    maxx = a[i].money, ans = a[i].name;
            return ans;
        }
    };
    void Donator::setMoney(float _money)
    {
        money = _money, totalMoney += _money;
    }
    void Donator::setName(string _name)
    {
        name = _name;
    }
    float Donator::totalMoney = 0;

    //读取n个捐款人的姓名和捐款额
    void read(Donator dt[], int n)
    {
        string name;
        float money;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> money;
            dt[i].setName(name);
            dt[i].setMoney(money);
        }
    }

    int main()
    {
        int n;
        cin >> n;                   //输入本批次将参与的捐款人数
        cin >> Donator::totalMoney; //输入目前已有的捐款总额
        Donator::printTotal();
        Donator d[n];
        read(d, n);
        Donator::printTotal();
        cout << getMaxName(d, n) << endl; //输出本批次中捐款最高者姓名
        return 0;
    }
};

//* 04-20

namespace Apr_20
{
    int main()
    {
        class Print
        {
        private:
            ostream &out;
            char end;

        public:
            Print(ostream &o = cout, char e = ' ') : out(o), end(e) {}
            void operator()(const string &s) const { out << s << end; }
        };
        string s = "mie mie";
        Print Out(cout, '\t');
        for (int i = 0; i < 5; ++i)
            Out(s);
        //
        //
        class Lambda
        {
        private:
            char c;

        public:
            Lambda(char cc) : c(cc) {}
            bool operator()(const char &a) const { return a == c; }
        };
        string s = "abandon";
        char c = 'a';
        cout << count_if(all(s), Lambda(c));
    }
    //
    // 什么测试点。。
#define x first
#define y second
    struct node
    {
        string name;
        int height, weight, id;
        static bool cmp(const node &a, const node &b)
        {
            return a.height < b.height;
        }
    };
    int main()
    {
        map<int, vector<node>> su;
        int T;
        for (cin >> T; T--;)
        {
            node t;
            cin >> t.id >> t.name >> t.height >> t.weight;
            su[t.id].push_back(t);
        }
        for (auto i : su)
            sort(all(i.y), node::cmp);
        for (auto i : su)
            cout << setfill('0') << setw(6) << i.x << " "
                 << i.y.front().name << " "
                 << i.y.front().height << " "
                 << i.y.front().weight << endl;
    }
};

//* 04-19
namespace Apr_19
{
    class People
    {
    public:
        People(){};
        People(string id_, string name_) : id(id_), name(name_){};

    public:
        void set_name(string name_) { name = name_; }
        void set_id(string id_) { this->id = id_; }
        string get_name() const { return name; }
        string get_id() const { return this->id; }

    protected:
        string id, name;
    };

    class Stu : public People
    {
    private:
        int score;
        Stu stu()
        {
            Stu t(this->id, this->name, this->score);
            return t;
        }

    public:
        Stu() { ++cnt; };
        Stu(int score_) : score(score_) { ++cnt; };
        Stu(string id_, string name_, int score_) : People(id_, name_), score(score_) { ++cnt; };

    public:
        static int cnt;
        void set_score(int score_) { score = score_; }
        int get_score() const { return score; }
        void print_info()
        {
            cout << "id: " << this->id << endl
                 << "name: " << this->name << endl
                 << "score: " << this->score << endl;
        }
        static Stu min(Stu &a, Stu &b)
        {
            return a < b ? a : b;
        }
        friend void print_stu(Stu &a);

    public:
        Stu operator++() // 前缀自增：++mie;
        {
            score++;
            return *this;
        }
        Stu operator++(int) // 后缀自增：mie++:
        {
            ++*this;
            return *this;
        }
        Stu operator+(Stu &a) // 对象之间相加 --> this + a
        {
            a.id = this->id + " | " + a.id,
            a.name = this->name + " | " + a.name,
            a.score = this->score + a.score;
            return a;
        }
        Stu operator+(int x)
        {
            Stu ans = stu();
            ans.score += x;
            return ans;
        }
        friend Stu operator+(int x, Stu &stu)
        {
            stu.score += x;
            return stu;
        }

        bool operator<(Stu &a)
        {
            return this->score < a.score;
        }

        friend ostream &operator<<(ostream &out, Stu &a)
        {
            out << "id: " << a.id << endl
                << "name: " << a.name << endl
                << "score: " << a.score << endl;
            return out;
        }
        friend istream &operator>>(istream &in, Stu &a)
        {
            in >> a.id >> a.name >> a.score;
            return in;
        }
    };

    int Stu::cnt = 0;
    int main()
    {
        Stu mie, fish;
        ifstream fin("input.txt");
        ofstream fout("output.txt");
        fin >> mie >> fish;
        fout << mie << fish;

        Stu::min(mie, fish).print_info();

        Stu mie("081001", "mie", 12),
            fish("081002", "fish", 14);
        cout << Stu::cnt << endl;

        fish++, ++mie;
        Stu t = fish + 100;
        t.print_info();

        Stu::min(mie, fish).print_info();
        cout << mie;
    }
};

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
//
//
//
namespace fish
{
#define FOR(n, m) for (int i = n; i <= m; ++i)
    /**
     * Copyright (C) Fish
     *
     * xxx some some some
     *
     * @file Class.hpp
     * @author Fish
     * @version 0.0.1
     * @date 2022/20/22
     * @brief This file ... just is a file
     */

    /** @brief Fish's class */

    /**
     * @brief 这是一个 circle 类.
     */
    class Circle
    {
    private:
        double rad, area;

    public:
        double get_rad() { return rad; };
        double get_area() { return area; };
        void push();
        void calc();
        void print();
    };

    /** @brief 输入半径 */
    void Circle::push()
    {
        scanf("%lf", &rad);
    }

    /**
     * @brief 计算 圆 的面积
     * @param none
     * @return no return
     */
    void Circle::calc()
    {
        area = rad * rad * PI;
    }

    /** @brief 输出 圆 的半径及面积 */
    void Circle::print()
    {
        printf("Radius: %.2f, area: %.2f.\n", rad, area);
    }

    /** @brief sort 中的 cmp，以 area 小到大排序 */
    bool cmp_area(Circle x, Circle y)
    {
        return x.get_area() < y.get_area();
    }

    int main()
    {
        Circle c[10];
        int n;
        cin >> n;

        FOR(0, n - 1)
        c[i].push(), c[i].calc();
        sort(c, c + n, cmp_area);

        FOR(0, n - 1)
        c[i].print();

        cin >> n;
        return 0;
    }
};