#define MOD 1000000007
#include <bits/stdc++.h>
long long int solveRec(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    int ans = (n - 1) * (solveRec(n - 2) + solveRec(n - 1));
    return ans;
}

long long int solveMemo(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (((n - 1) % MOD) * ((solveMemo(n - 2, dp)) % MOD + solveMemo(n - 1, dp) % MOD)) % MOD;
    return dp[n];
}

long long int solveTab(int n)
{
    vector<int> dp(n + 1);

    dp[1] = 0;

    dp[2] = 1;

    for (long long int i = 3; i <= n; i++)
    {
        dp[i] = (((i - 1) % MOD) * ((dp[i - 2]) % MOD + dp[i - 1] % MOD)) % MOD;
    }
    return dp[n];
}

long long int solveSpaceOptimized(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;
    for (long long int i = 3; i <= n; i++)
    {
        long long int ans = (((i - 1) % MOD) * ((prev2 % MOD) + (prev1 % MOD))) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n)
{
    // Write your code here.
    // long long int ans = solveRec(n);

    // vector<int> dp(n + 1, -1);
    // long long int ans = solveMemo(n, dp);

    // long long int ans = solveTab(n);
    long long int ans = solveSpaceOptimized(n);
    return ans;
}