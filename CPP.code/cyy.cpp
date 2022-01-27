#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>
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
    student rk1 = pq.top();
    cout << rk1.name << ' ' << rk1.score << endl;
    return 0;
}