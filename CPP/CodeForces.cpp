#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
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