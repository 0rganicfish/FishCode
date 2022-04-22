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
    friend void prints(Stu &a);
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

void prints(Stu &a)
{
    cout << a.score << endl;
}

int Stu::cnt = 0;
int main()
{
    // Stu mie("081001", "mie", 12),
    //     fish("081002", "fish", 14);

    // fish++, ++mie;
    // Stu t = fish + 100;

    // Stu::min(mie, fish).print_info();

    // prints(mie);
    string s = "1234";
    string ss = string(s.rbegin() + 1, s.rend());
    cout << ss;
}
