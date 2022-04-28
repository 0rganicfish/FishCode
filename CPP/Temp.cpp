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

class People
{
public:
    People(){};
    People(string id_, string name_) : id(id_), name(name_){};

protected:
    string id, name;
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
