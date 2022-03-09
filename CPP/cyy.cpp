#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define Paint pair<int, int>

queue<Paint> q;
int dxy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[32][32] = {false};
int mpa[32][32] = {0};
int n, i, j, k;

signed main()
{
    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
        {
            cin >> mpa[i][j];
            if ((i == 1 or j == 1 or i == n or j == n) and !mpa[i][j])
                mpa[i][j] = -1;
        }

    cout << endl;

    for (i = 2; i < n; ++i)
        for (j = 2; j < n; ++j)
        {
            if (mpa[i][j] == -1)
                for (k = 0; k < 4; ++k)
                {
                    int xx = i + dxy[k][0], yy = j + dxy[k][1];
                    if (mpa[xx][yy] == 0)
                    {
                        mpa[xx][yy] = -1;
                        break;
                    }
                }
            else if (!mpa[i][j])
                mpa[i][j] = 2;
        }
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            cout << mpa[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            if (mpa[i][j] == -1)
                cout << "0 ";
            else
                cout << mpa[i][j] << " ";
        cout << endl;
    }
    return 0;
}