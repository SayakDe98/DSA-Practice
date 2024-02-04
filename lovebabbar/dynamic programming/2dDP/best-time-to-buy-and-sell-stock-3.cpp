class Solution
{
public:
    // my approach
    //     int solve(vector<int>& prices, int i, int buy, int progress) {
    //         if(i == prices.size() || progress == 2)
    //             return 0;

    //         int profit = 0;
    //         if(buy) {
    //             int buyStock = -prices[i] + solve(prices, i + 1, 0, progress);
    //             int ignoreStock = 0 + solve(prices, i + 1, 1, progress);
    //             profit = max(buyStock, ignoreStock);
    //         } else {
    //             int sellStock = prices[i] + solve(prices, i + 1, 1, progress + 1);
    //             int ignoreStock = 0 + solve(prices, i + 1, buy, progress);
    //             profit = max(sellStock, ignoreStock);
    //         }
    //         return profit;
    //     }

    // int solveMemo(vector<int>& prices, int i, int buy, int progress, vector<vector<vector<int>>>& dp) {
    //     if(i == prices.size() || progress == 2)
    //         return 0;
    //     if(dp[i][buy][progress] != -1)
    //         return dp[i][buy][progress];
    //     int profit = 0;
    //     if(buy) {
    //         int buyStock = -prices[i] + solveMemo(prices, i + 1, 0, progress, dp);
    //         int ignoreStock = 0 + solveMemo(prices, i + 1, 1, progress, dp);
    //         profit = max(buyStock, ignoreStock);
    //     } else {
    //         int sellStock = prices[i] + solveMemo(prices, i + 1, 1, progress + 1, dp);
    //         int ignoreStock = 0 + solveMemo(prices, i + 1, buy, progress, dp);
    //         profit = max(sellStock, ignoreStock);
    //     }
    //     return dp[i][buy][progress] = profit;
    // }

    //     int solveTab(vector<int>& prices) {
    //         int n = prices.size();
    //         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, 0)));

    //         for(int i = n - 1; i >= 0; i--) {
    //                     int profit = 0;
    //             for(int buy = 0; buy <= 1; buy++) {
    //                 for(int progress = 2; progress >= 1; progress--) {
    //                     if(buy) {
    //                         int buyStock = -prices[i] + dp[i + 1][0][progress];
    //                         int ignoreStock = 0 + dp[i + 1][1][progress];
    //                         profit = max(buyStock, ignoreStock);
    //                     } else {
    //                         int sellStock = prices[i] + dp[i + 1][1][progress + 1];
    //                         int ignoreStock = 0 + dp[i + 1][buy][progress];
    //                         profit = max(sellStock, ignoreStock);
    //                     }
    //                     dp[i][buy][progress] = profit;
    //                 }
    //             }
    //         }
    //         return dp[0][1][1];
    //     }

    //       int solveSpaceOpt(vector<int>& prices) {
    //         int n = prices.size();
    //         // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, 0)));
    //         vector<vector<int>> curr(2, vector<int>(4, 0));
    //         vector<vector<int>> next(2, vector<int>(4, 0));
    //         for(int i = n - 1; i >= 0; i--) {
    //                     int profit = 0;
    //             for(int buy = 0; buy <= 1; buy++) {
    //                 for(int progress = 2; progress >= 1; progress--) {
    //                     if(buy) {
    //                         int buyStock = -prices[i] + next[0][progress];
    //                         int ignoreStock = 0 + next[1][progress];
    //                         profit = max(buyStock, ignoreStock);
    //                     } else {
    //                         int sellStock = prices[i] + next[1][progress + 1];
    //                         int ignoreStock = 0 + next[buy][progress];
    //                         profit = max(sellStock, ignoreStock);
    //                     }
    //                     curr[buy][progress] = profit;
    //                 }

    //             }
    //             next = curr;
    //         }
    //         return next[1][1];
    //     }

    int solve(vector<int> &prices, int i, int buy, int limit)
    {
        if (i == prices.size() || limit == 0)
            return 0;

        int profit = 0;
        if (buy)
        {
            int buyStock = -prices[i] + solve(prices, i + 1, 0, limit);
            int ignoreStock = 0 + solve(prices, i + 1, 1, limit);
            profit = max(buyStock, ignoreStock);
        }
        else
        {
            int sellStock = prices[i] + solve(prices, i + 1, 1, limit - 1);
            int ignoreStock = 0 + solve(prices, i + 1, buy, limit);
            profit = max(sellStock, ignoreStock);
        }
        return profit;
    }

    int solveMemo(vector<int> &prices, int i, int buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || limit == 0)
            return 0;
        if (dp[i][buy][limit] != -1)
            return dp[i][buy][limit];
        int profit = 0;
        if (buy)
        {
            int buyStock = -prices[i] + solveMemo(prices, i + 1, 0, limit, dp);
            int ignoreStock = 0 + solveMemo(prices, i + 1, 1, limit, dp);
            profit = max(buyStock, ignoreStock);
        }
        else
        {
            int sellStock = prices[i] + solveMemo(prices, i + 1, 1, limit - 1, dp);
            int ignoreStock = 0 + solveMemo(prices, i + 1, buy, limit, dp);
            profit = max(sellStock, ignoreStock);
        }
        return dp[i][buy][limit] = profit;
    }

    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    if (buy)
                    {
                        int buyStock = -prices[i] + dp[i + 1][0][limit];
                        int ignoreStock = 0 + dp[i + 1][1][limit];
                        profit = max(buyStock, ignoreStock);
                    }
                    else
                    {
                        int sellStock = prices[i] + dp[i + 1][1][limit - 1];
                        int ignoreStock = 0 + dp[i + 1][buy][limit];
                        profit = max(sellStock, ignoreStock);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveSpaceOpt(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, 0)));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    if (buy)
                    {
                        int buyStock = -prices[i] + next[0][limit];
                        int ignoreStock = 0 + next[1][limit];
                        profit = max(buyStock, ignoreStock);
                    }
                    else
                    {
                        int sellStock = prices[i] + next[1][limit - 1];
                        int ignoreStock = 0 + next[buy][limit];
                        profit = max(sellStock, ignoreStock);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int> &prices)
    {
        // return solve(prices, 0, 1, 0);
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveMemo(prices, 0, 1, 0, dp);
        // return solveTab(prices);
        // return solveSpaceOpt(prices);

        // lovebabbar approach
        //  return solve(prices, 0, 1, 2);
        //  int n = prices.size();
        //  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        //  return solveMemo(prices, 0, 1, 2, dp);
        //  return solveTab(prices);
        return solveSpaceOpt(prices);
    }
};