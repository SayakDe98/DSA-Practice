class Solution
{
private:
    int solve(vector<int> &v, int i, int j)
    {
        if (i + 1 == j)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
        }
        return ans;
    }
    int solveMemo(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solveMemo(v, i, k, dp) + solveMemo(v, k, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveTab(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][n - 1];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        // return solve(values, 0, values.size() - 1);
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        // return solveMemo(values, 0, values.size() - 1, dp);
        return solveTab(values);
    }
};