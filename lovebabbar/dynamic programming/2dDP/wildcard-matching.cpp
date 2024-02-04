class Solution
{
public:
    bool solve(string s, string p, int i, int j)
    {
        if (i < 0 and j < 0)
            return true; // valid pattern
        if (i >= 0 and j < 0)
            return false; // invalid pattern
        if (i < 0 and j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        bool match = (s[i] == p[j]) || (p[j] == '?');
        if (match)
            return solve(s, p, i - 1, j - 1);
        else if (p[j] == '*')
        {
            return (solve(s, p, i - 1, j) or solve(s, p, i, j - 1));
        }
        else
        {
            return false;
        }
    }

    bool solveMemo(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    { // without & for string s and pattern p we got TLE
        if (i < 0 and j < 0)
            return true; // valid pattern
        if (i >= 0 and j < 0)
            return false; // invalid pattern
        if (i < 0 and j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool match = (s[i] == p[j]) || (p[j] == '?');
        if (match)
            return dp[i][j] = solveMemo(s, p, i - 1, j - 1, dp);
        else if (p[j] == '*')
        {
            return dp[i][j] = (solveMemo(s, p, i - 1, j, dp) or solveMemo(s, p, i, j - 1, dp));
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    bool solveMemo2(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    { // without & for string s and pattern p we got TLE
        if (i == 0 and j == 0)
            return true; // valid pattern
        if (i > 0 and j == 0)
            return false; // invalid pattern
        if (i == 0 and j > 0)
        {
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool match = (s[i - 1] == p[j - 1]) || (p[j - 1] == '?');
        if (match)
            return dp[i][j] = solveMemo2(s, p, i - 1, j - 1, dp);
        else if (p[j - 1] == '*')
        {
            return dp[i][j] = (solveMemo2(s, p, i - 1, j, dp) or solveMemo2(s, p, i, j - 1, dp));
        }
        else
        {
            return dp[i][j] = false;
        }
    }

    bool solveTab(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // initializing with 0(false)
        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                bool match = (s[i - 1] == p[j - 1]) || (p[j - 1] == '?');
                if (match)
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = (dp[i - 1][j] or dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }

    bool solveSpaceOpt(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));//initializing with 0(false)
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        prev[0] = true;

        for (int j = 1; j <= m; j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                bool match = (s[i - 1] == p[j - 1]) || (p[j - 1] == '?');
                if (match)
                    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                {
                    curr[j] = (prev[j] or curr[j - 1]);
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }

    bool isMatch(string s, string p)
    { // where s is the string we need to match with pattern p
        // return solve(s, p, s.length() - 1, p.length() - 1);
        // int n = s.length();
        // int m = p.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveMemo(s, p, n, m, dp);
        // For clarfiying how to use tabulation:
        // vector<vector<int>> dp2(n + 1, vector<int>(m + 1, -1));
        // return solveMemo2(s, p, n, m, dp2);
        // tabulation:
        // return solveTab(s, p);
        return solveSpaceOpt(s, p);
    }
};