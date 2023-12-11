#include <bits/stdc++.h>
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    int incl = 0;
    if (weight[index] <= capacity)
    {
        incl = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }
    int excl = 0 + solve(weight, value, index - 1, capacity);
    int ans = max(incl, excl);
    return ans;
}

int solveTopDown(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int incl = 0;
    if (weight[index] <= capacity)
    {
        incl = solveTopDown(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }
    int excl = solveTopDown(weight, value, index - 1, capacity, dp) + 0;

    dp[index][capacity] = max(incl, excl);
    return dp[index][capacity];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // Step 1 Initialize dp
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Step 2: Analyse base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    // solve rest
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int incl = 0;
            if (weight[index] <= w)
            {
                incl = dp[index - 1][w - weight[index]] + value[index];
            }
            int excl = dp[index - 1][w] + 0;
            dp[index][w] = max(incl, excl);
        }
    }
    return dp[n - 1][capacity];
}

int solveSpaceOpt(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int incl = 0;

            if (weight[index] <= w)
            {
                incl = prev[w - weight[index]] + value[index];
            }
            int excl = prev[w] + 0;
            curr[w] = max(incl, excl);
        }
        prev = curr;
    }
    return prev[capacity];
}

int solveWithMoreSpaceOptimisation(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int incl = 0;

            if (weight[index] <= w)
            {
                incl = curr[w - weight[index]] + value[index];
            }
            int excl = curr[w] + 0;
            curr[w] = max(incl, excl);
        }
    }
    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    // recursive solution
    // return solve(weight, value, n - 1, maxWeight);

    // top down approch
    //  vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
    //  return solveTopDown(weight, value, n - 1, maxWeight, dp);

    // bottom up approach
    //  return solveTab(weight, value, n , maxWeight);

    // space optimised approach
    //  return solveSpaceOpt(weight, value, n, maxWeight);

    // more space optimisation
    return solveWithMoreSpaceOptimisation(weight, value, n, maxWeight);
}