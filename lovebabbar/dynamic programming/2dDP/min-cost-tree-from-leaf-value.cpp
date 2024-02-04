class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int k = left; k < right; k++)
        {
            ans = min(ans, maxi[{left, k}] * maxi[{k + 1, right}] + solve(arr, maxi, left, k) + solve(arr, maxi, k + 1, right));
        }
        return ans;
    }
    int solveMemo(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        if (left == right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int k = left; k < right; k++)
        {
            ans = min(ans, maxi[{left, k}] * maxi[{k + 1, right}] + solveMemo(arr, maxi, left, k, dp) + solveMemo(arr, maxi, k + 1, right, dp));
        }
        return dp[left][right] = ans;
    }

    int solveTab(vector<int> &arr, map<pair<int, int>, int> &maxi, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = left; right <= n; right++)
            {
                if (left == right)
                {
                    continue;
                }
                int ans = INT_MAX;
                for (int k = left; k < right; k++)
                {
                    ans = min(ans, maxi[{left, k}] * maxi[{k + 1, right}] + dp[left][k] + dp[k + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n];
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        // map<pair<int, int>, int> maxi;
        // for(int i = 0; i < arr.size(); i++) {
        //     maxi[{i, i}] = arr[i];
        //     for(int j = i + 1; j < arr.size(); j++) {
        //         maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        //     }
        // }
        // return solve(arr, maxi, 0, arr.size() - 1);
        // Recursion memoization
        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // map<pair<int, int>, int> maxi;
        // for(int i = 0; i < arr.size(); i++) {
        //     maxi[{i, i}] = arr[i];
        //     for(int j = i + 1; j < arr.size(); j++) {
        //         maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        //     }
        // }
        // return solveMemo(arr, maxi, 0, arr.size() - 1, dp);
        // Tabulation
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        return solveTab(arr, maxi, n - 1);
    }
};