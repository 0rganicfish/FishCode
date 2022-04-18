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
    string sscore = to_string(score);

public:
    Stu(){};
    Stu(int score_) : score(score_){};
    Stu(string id_, string name_, int score_) : People(id_, name_), score(score_){};

public:
    void set_score(int score_) { score = score_; }
    int get_score() const { return score; }
    void print_info()
    {
        cout << "id: " << this->id << endl
             << "name: " << this->name << endl
             << "score: " << this->sscore << endl;
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
        ans.id = this->id + " | " + a.id,
        ans.name = this->name + " | " + a.name,
        ans.sscore = this->sscore + " | " + a.sscore;
        return ans;
    }
};

int main()
{
    Stu mie("081001", "mie", 12),
        fish("081002", "fish", 14);
    fish++, ++mie;
    Stu t = mie + fish;
    t.print_info();
}
