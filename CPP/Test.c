#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
typedef unsigned long long ll;

#include <stdio.h>   // printf
#include <stdint.h>  // uint64_t
#include <math.h>    // log10, ceil, acos...
#include <malloc.h>  // malloc
#include <Windows.h> // 毫秒级计时
const ll BIGINT_MAX = 1e18;

typedef struct
{
    uint64_t *num; // 数字数组
    uint64_t len;  // num 的有效长度
} BigInt;

BigInt factorial(int n)
{
    BigInt ans = {NULL, 1};
    ans.num = malloc(sizeof(uint64_t) * (size_t)ceil(((n + 0.5) * log10(n + 1) - n / log(10) + log10(2 * acos(-1) + 1)) / 8));
    ans.num[0] = 1; // 初始阶乘为1
    int idx;        // 定义放外面用以兼容那些操蛋的不支持 C99 的编译器
    int idx2;
    uint64_t muls = 1;
    int carry; // 进位
    for (idx = 2; idx <= n; ++idx)
    {
        if (muls * idx < BIGINT_MAX)
        {
            muls *= idx;
        }
        else
        { // 再乘就要溢出 BIGINT_MAX 了，直接计算乘法
            carry = 0;
            for (idx2 = 0; idx2 < ans.len; ++idx2)
            {
                ans.num[idx2] = ans.num[idx2] * muls + carry; // 竖式乘法带进位
                carry = ans.num[idx2] / BIGINT_MAX;
                ans.num[idx2] = ans.num[idx2] % BIGINT_MAX;
            }
            ans.num[ans.len] = carry;
            ans.len += (carry > 0); // 相当于 if (carry > 0)    ++ ans.len;
            muls = idx;             // 乘完记得复位 muls
        }
    }
    if (muls != 1)
    { // 说明还有数没乘，补上
        carry = 0;
        for (idx2 = 0; idx2 < ans.len; ++idx2)
        {
            ans.num[idx2] = ans.num[idx2] * muls + carry; // 竖式乘法带进位
            carry = ans.num[idx2] / BIGINT_MAX;
            ans.num[idx2] = ans.num[idx2] % BIGINT_MAX;
        }
        ans.num[ans.len] = carry;
        ans.len += (carry > 0); // 相当于 if (carry > 0)    ++ ans.len;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    DWORD startTime = GetTickCount();
    BigInt ans = factorial(n);
    DWORD endTime = GetTickCount();

    printf("%d! = %zu", n, ans.num[ans.len - 1]); // 打印输出结果
    for (int idx = ans.len - 2; idx >= 0; --idx)
        printf("%08zu", ans.num[idx]);
    printf("\n\n%d! cost: %d ms\n", n, endTime - startTime);

    free(ans.num);
    getchar();
    return 0;
}