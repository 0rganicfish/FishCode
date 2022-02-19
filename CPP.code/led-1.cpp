#include <bits/stdc++.h>
using namespace std;

int solve(int nums[])
{
    int n = sizeof(nums) / sizeof(int);
    int dp[n];
    for (int i = 0; i < n; ++i)
        dp[i] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[j] > nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp, dp + n);
}

int main()
{
    int n, nums[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << solve(nums);
    return 0;
}