#include <bits/stdc++.h>
using namespace std;
void Perm(int list[], int k, int m)
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
            cout << list[i] << " ";
        cout << endl;
    }
    else
        for (int i = k; i <= m; i++)
        {
            swap(list[i], list[k]);
            Perm(list, k + 1, m);
            swap(list[i], list[k]);
        }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Perm(a, 0, 4);
        
}