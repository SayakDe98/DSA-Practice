class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        if (a.length() == i)
            return b.length() - j;
        if (b.length() == j)
            return a.length() - i;

        int ans = 0;

        // match case
        if (a[i] == b[j])
            ans = solve(a, b, i + 1, j + 1);
        // insert, delete, replace cases
        else
        {
            // insert
            int insertOp = 1 + solve(a, b, i, j + 1);
            // delete
            int deleteOp = 1 + solve(a, b, i + 1, j);
            // replace
            int replaceOp = 1 + solve(a, b, i + 1, j + 1);
            ans = min(insertOp, min(deleteOp, replaceOp));
        }
        return ans;
    }
    int solveMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {

        if (a.length() == i)
            return b.length() - j;
        if (b.length() == j)
            return a.length() - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;

        // match case
        if (a[i] == b[j])
            ans = solveMemo(a, b, i + 1, j + 1, dp);
        // insert, delete, replace cases
        else
        {
            // insert
            int insertOp = 1 + solveMemo(a, b, i, j + 1, dp);
            // delete
            int deleteOp = 1 + solveMemo(a, b, i + 1, j, dp);
            // replace
            int replaceOp = 1 + solveMemo(a, b, i + 1, j + 1, dp);
            ans = min(insertOp, min(deleteOp, replaceOp));
        }
        return dp[i][j] = ans;
    }
    int solveTab(string a, string b)
    {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        for (int j = 0; j < b.length(); j++)
        {
            dp[a.length()][j] = b.length() - j;
        }
        for (int i = 0; i < a.length(); i++)
        {
            dp[i][b.length()] = a.length() - i;
        }
        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;

                // match case
                if (a[i] == b[j])
                    ans = dp[i + 1][j + 1];
                // insert, delete, replace cases
                else
                {
                    // insert
                    int insertOp = 1 + dp[i][j + 1];
                    // delete
                    int deleteOp = 1 + dp[i + 1][j];
                    // replace
                    int replaceOp = 1 + dp[i + 1][j + 1];
                    ans = min(insertOp, min(deleteOp, replaceOp));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSpaceOpt(string a, string b)
    {
        // vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);
        for (int j = 0; j < b.length(); j++)
        {
            next[j] = b.length() - j;
        }
        // for(int i = 0; i < a.length(); i++) {
        //     dp[i][b.length()] = a.length() - i;
        // }
        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                curr[b.length()] = a.length() - i;

                int ans = 0;
                // match case
                if (a[i] == b[j])
                    ans = next[j + 1];
                // insert, delete, replace cases
                else
                {
                    // insert
                    int insertOp = 1 + curr[j + 1];
                    // delete
                    int deleteOp = 1 + next[j];
                    // replace
                    int replaceOp = 1 + next[j + 1];
                    ans = min(insertOp, min(deleteOp, replaceOp));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2)
    {
        // return solve(word1, word2, 0, 0);
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMemo(word1, word2, 0, 0, dp);
        // return solveTab(word1, word2);
        if (!word1.length())
            return word2.length();
        if (!word2.length())
            return word1.length();
        return solveSpaceOpt(word1, word2);
    }
};