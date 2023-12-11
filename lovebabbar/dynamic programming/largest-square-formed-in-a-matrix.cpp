//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> mat, int &maxi)
    {
        if (n >= mat.size() || m >= mat[0].size())
        {
            return 0;
        }

        int right = solve(n, m + 1, mat, maxi);
        int bottom = solve(n + 1, m, mat, maxi);
        int diag = solve(n + 1, m + 1, mat, maxi);

        if (mat[n][m] == 1)
        {
            int ans = 1 + min(right, min(bottom, diag));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }

    int solveMemo(int i, int j, vector<vector<int>> &mat, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = solveMemo(i, j + 1, mat, maxi, dp);
        int bottom = solveMemo(i + 1, j, mat, maxi, dp);
        int diag = solveMemo(i + 1, j + 1, mat, maxi, dp);

        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(bottom, diag));
            maxi = max(maxi, ans);
            dp[i][j] = ans;
        }
        else
        {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int solveTab(vector<vector<int>> &mat, int &maxi)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for (int i = mat.size() - 1; i >= 0; i--)
        {
            for (int j = mat[0].size() - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int bottom = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];

                if (mat[i][j] == 1)
                {
                    int ans = 1 + min(right, min(bottom, diag));
                    maxi = max(maxi, ans);
                    dp[i][j] = ans;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    int solveSpaceoptimised(vector<vector<int>> &mat, int &maxi)
    {
        int row = mat.size();
        int col = mat[0].size();
        // vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        vector<int> curr(col + 1);
        vector<int> next(col + 1);
        for (int i = mat.size() - 1; i >= 0; i--)
        {
            for (int j = mat[0].size() - 1; j >= 0; j--)
            {
                int right = curr[j + 1];
                int bottom = next[j];
                int diag = next[j + 1];

                if (mat[i][j] == 1)
                {
                    int ans = 1 + min(right, min(bottom, diag));
                    maxi = max(maxi, ans);
                    curr[j] = ans;
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }

    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxi = 0;
        // solve(0, 0, mat, maxi);
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // solveMemo(0, 0, mat, maxi, dp);
        // return maxi;
        // solveTab(mat, maxi);
        // return maxi;
        solveSpaceoptimised(mat, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends