#include <bits/stdc++.h>
#include<vector>
int solveRec(vector<int> &nums, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[n];
    }
    int incl = solveRec(nums, n - 2) + nums[n];
    int excl = solveRec(nums, n - 1) + 0;
    return max(incl, excl);
}

int solveTopDown(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int incl = solveTopDown(nums, n - 2, dp) + nums[n];
    int excl = solveTopDown(nums, n - 1, dp) + 0;
    dp[n] = max(incl, excl);
    return dp[n];
}

int solveBottomUp(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}

int spaceOptimizedTabulation(vector<int> &nums)
{
    int prev2 = 0;
    int prev1 = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    // int ans = solveRec(nums, n - 1);
    // vector<int> dp(n, -1);
    // int ans = solveTopDown(nums, n - 1, dp);
    // int ans = solveBottomUp(nums);
    int ans = spaceOptimizedTabulation(nums);
    return ans;
}