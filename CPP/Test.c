#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;
#define Min(a, b) (a > b) ? b : a
#define Max(a, b) (a > b) ? a : b
#define Swap(a, b) (a = (a) ^ (b), b = (a) ^ (b), a = (a) ^ (b))
int arr[100], n, i, j;
void sort()
{
    for (i = 0; i < n - 1; i++)
    {
        int minn = i;
        for (j = i + 1; j < n; j++)
            if (arr[minn] > arr[j])
                minn = j;
        if (i != minn)
            Swap(arr[i], arr[minn]);
        for (j = 0; j < n; j++)
        {
            if (j)
                putchar(' ');
            printf("%d", arr[j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if (n == 1) { printf("%d", arr[0]); return 0; }
    sort();
}