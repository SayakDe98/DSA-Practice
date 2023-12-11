#include <bits/stdc++.h>
int solve(vector<int> &num, int tar)
{
    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }

    // try all numbers so use loop
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i]);
    }
    return ans;
}

int solveMem(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return 1;
    }

    if (tar < 0)
    {
        return 0;
    }

    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        sum += solveMem(num, tar - num[i], dp);
    }
    dp[tar] = sum;
    return dp[tar];
}

int solveBottomUp(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    // traversing from target = 1 to target = tar
    for (int i = 1; i <= tar; i++)
    {
        // traversing for every num value
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // solve recursive
    // return solve(num, tar);

    // solve top down
    //  vector<int> dp(tar + 1, -1);
    //  return solveMem(num, tar, dp);

    // solve bottom up
    return solveBottomUp(num, tar);
}