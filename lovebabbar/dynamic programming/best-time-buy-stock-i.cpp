class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //         int n = prices.size();
        //         int min_val = prices[0];
        //         int maxi = INT_MIN;

        //         for(int i = 0; i < n; i++) {
        //             maxi = max(maxi, prices[i] - min_val);

        //             min_val = min(min_val, prices[i]);
        //         }
        //         return maxi >= 0 ? maxi : 0;
        int n = prices.size();
        int profit = 0;
        int mini = prices[0];

        for (int i = 1; i < n; i++)
        {
            int diff = prices[i] - mini;
            profit = max(diff, profit);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};