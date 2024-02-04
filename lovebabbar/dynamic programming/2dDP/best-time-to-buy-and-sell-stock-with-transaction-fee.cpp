class Solution
{
private:
    int solve(vector<int> &prices, int i, int buy, int fee)
    {
        if (i == prices.size())
            return 0;
        if (buy)
        {
            int buyStock = -prices[i] + solve(prices, i + 1, 0, fee);
            int ignoreStock = 0 + solve(prices, i + 1, 1, fee);
            return max(buyStock, ignoreStock);
        }
        // else part where we sell or ignore stock
        int sellStock = +prices[i] - fee + solve(prices, i + 1, 1, fee);
        int ignoreStock = 0 + solve(prices, i + 1, buy, fee);
        return max(sellStock, ignoreStock);
    }

    int solveMemo(vector<int> &prices, int i, int buy, int fee, vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy)
        {
            int buyStock = -prices[i] + solveMemo(prices, i + 1, 0, fee, dp);
            int ignoreStock = 0 + solveMemo(prices, i + 1, 1, fee, dp);
            return dp[i][buy] = max(buyStock, ignoreStock);
        }
        // else part where we sell or ignore stock
        int sellStock = +prices[i] - fee + solveMemo(prices, i + 1, 1, fee, dp);
        int ignoreStock = 0 + solveMemo(prices, i + 1, buy, fee, dp);
        return dp[i][buy] = max(sellStock, ignoreStock);
    }
    int solveTab(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    int buyStock = -prices[i] + dp[i + 1][0];
                    int ignoreStock = 0 + dp[i + 1][1];
                    profit = max(buyStock, ignoreStock);
                }
                // else part where we sell or ignore stock
                else
                {
                    int sellStock = +prices[i] - fee + dp[i + 1][1];
                    int ignoreStock = 0 + dp[i + 1][buy];
                    profit = max(sellStock, ignoreStock);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSpaceOpt(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    int buyStock = -prices[i] + next[0];
                    int ignoreStock = 0 + next[1];
                    profit = max(buyStock, ignoreStock);
                }
                // else part where we sell or ignore stock
                else
                {
                    int sellStock = +prices[i] - fee + next[1];
                    int ignoreStock = 0 + next[buy];
                    profit = max(sellStock, ignoreStock);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        // return solve(prices, 0, 1, fee);
        // vector<vector<int>> dp(prices.size() + 1, vector<int> (2, -1));
        // return solveMemo(prices, 0, 1, fee, dp);
        // return solveTab(prices, fee);
        return solveSpaceOpt(prices, fee);
    }
};