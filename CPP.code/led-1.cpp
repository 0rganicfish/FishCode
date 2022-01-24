//功能：输入单词，统计单词出现次数并按照单词出现次数从多到少排序
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cmp(const pair<string, int> &x, const pair<string, int> &y)
{
    return x.second > y.second;
}

void sortMapByValue(map<string, int> &tMap, vector<pair<string, int>> &tVector)
{
    for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
        tVector.push_back(make_pair(curr->first, curr->second));

    sort(tVector.begin(), tVector.end(), cmp);
}
int main()
{
    map<string, int> tMap;
    string word;
    while (cin >> word)
    {
        pair<map<string, int>::iterator, bool> ret = tMap.insert(make_pair(word, 1));
        if (!ret.second)
            ++ret.first->second;
    }

    vector<pair<string, int>> tVector;
    sortMapByValue(tMap, tVector);
    for (int i = 0; i < tVector.size(); i++)
        cout << tVector[i].first << ": " << tVector[i].second << endl;

    system("pause");
    return 0;
}