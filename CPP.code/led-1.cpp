//功能：输入单词，统计单词出现次数并按照单词出现次数从多到少排序
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> PAIR;
bool cmp_by_value(const PAIR &lhs, const PAIR &rhs)
{
    return lhs.second < rhs.second;
}

int main()
{
    map<string, int> name_score;
    // 输入map数据 ......
    vector<PAIR> ns_vec(name_score.begin(), name_score.end());
    sort(ns_vec.begin(), ns_vec.end(), cmp_by_value);

    for (int i = 0; i != ns_vec.size(); ++i)
        cout << ns_vec[i].first << " " << ns_vec[i].second << endl;
    return 0;
}