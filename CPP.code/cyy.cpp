#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int score;
};
struct cmp
{
    bool operator()(const student &a, const student &b) const
    {
        return a.score < b.score || (a.score == b.score && a.name > b.name);
    }
};
ostream &operator<<(ostream &out, const student &O)
{
    return out << O.name << " " << O.score << endl;
}

priority_queue<student, vector<student>, cmp> pq;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        pq.push({name, score});
    }
    cout << pq.top();
    return 0;
}