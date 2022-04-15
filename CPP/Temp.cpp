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

    Stu operator+(const Stu &a)
    {
        Stu ans;
        ans.score = this->score + a.score;
        return ans;
    }
};

int main()
{
    Stu mie("mie", 12), fish("fish", 14);
    Stu t = mie + fish;
    t.print_info();
}
