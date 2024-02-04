class Solution
{
private:
    int solve(int index, int endIndex, vector<int> &slices, int slicesICanEat)
    {
        if (slicesICanEat == 0 || index > endIndex)
        {
            return 0;
        }

        int eatCurrentSlice = slices[index] + solve(index + 2, endIndex, slices, slicesICanEat - 1);
        int dontEatCurrentSlice = 0 + solve(index + 1, endIndex, slices, slicesICanEat);
        return max(eatCurrentSlice, dontEatCurrentSlice);
    }
    int solveMemo(int index, int endIndex, vector<int> &slices, int slicesICanEat, vector<vector<int>> &dp)
    {
        if (slicesICanEat == 0 || index > endIndex)
        {
            return 0;
        }
        if (dp[index][slicesICanEat] != -1)
        {
            return dp[index][slicesICanEat];
        }
        int eatCurrentSlice = slices[index] + solveMemo(index + 2, endIndex, slices, slicesICanEat - 1, dp);
        int dontEatCurrentSlice = 0 + solveMemo(index + 1, endIndex, slices, slicesICanEat, dp);
        return dp[index][slicesICanEat] = max(eatCurrentSlice, dontEatCurrentSlice);
    }
    int solveTab(vector<int> &slices)
    {
        int k = slices.size();

        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int currentSlice = k - 2; currentSlice >= 0; currentSlice--)
        {
            for (int slicesICanEat = 1; slicesICanEat <= k / 3; slicesICanEat++)
            {
                int eatCurrentSlice = slices[currentSlice] + dp1[currentSlice + 2][slicesICanEat - 1];
                int dontEatCurrentSlice = 0 + dp1[currentSlice + 1][slicesICanEat];
                dp1[currentSlice][slicesICanEat] = max(eatCurrentSlice, dontEatCurrentSlice);
            }
        }
        int case1 = dp1[0][k / 3];

        for (int currentSlice = k - 1; currentSlice >= 1; currentSlice--)
        {
            for (int slicesICanEat = 1; slicesICanEat <= k / 3; slicesICanEat++)
            {
                int eatCurrentSlice = slices[currentSlice] + dp2[currentSlice + 2][slicesICanEat - 1];
                int dontEatCurrentSlice = 0 + dp2[currentSlice + 1][slicesICanEat];

                dp2[currentSlice][slicesICanEat] = max(eatCurrentSlice, dontEatCurrentSlice);
            }
        }
        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }

    int solveSpaceOpt(vector<int> &slices)
    {
        int k = slices.size();

        vector<int> prev1(k + 2, 0);
        vector<int> curr1(k + 2, 0);
        vector<int> next1(k + 2, 0);

        for (int currentSlice = k - 2; currentSlice >= 0; currentSlice--)
        {
            for (int slicesICanEat = 1; slicesICanEat <= k / 3; slicesICanEat++)
            {
                int eatCurrentSlice = slices[currentSlice] + next1[slicesICanEat - 1];
                int dontEatCurrentSlice = 0 + curr1[slicesICanEat];
                prev1[slicesICanEat] = max(eatCurrentSlice, dontEatCurrentSlice);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k / 3];

        vector<int> prev2(k + 2, 0);
        vector<int> curr2(k + 2, 0);
        vector<int> next2(k + 2, 0);

        for (int currentSlice = k - 1; currentSlice >= 1; currentSlice--)
        {
            for (int slicesICanEat = 1; slicesICanEat <= k / 3; slicesICanEat++)
            {
                int eatCurrentSlice = slices[currentSlice] + next2[slicesICanEat - 1];
                int dontEatCurrentSlice = 0 + curr2[slicesICanEat];

                prev2[slicesICanEat] = max(eatCurrentSlice, dontEatCurrentSlice);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = prev2[k / 3];

        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        // int case1 = solve(0, k - 2, slices, k / 3);
        // int case2 = solve(1, k - 1, slices, k / 3);
        // return max(case1, case2);
        //         vector<vector<int>> dp1(k, vector<int>(k, -1));
        //         int case1 = solveMemo(0, k - 2, slices, k / 3, dp1);//we are making two recursive calls so create seperate dps

        //         vector<vector<int>> dp2(k, vector<int>(k, -1));
        //         int case2 = solveMemo(1, k - 1, slices, k / 3, dp2);//we are making two recursive calls so create seperate dps
        //         return max(case1, case2);
        // return solveTab(slices);
        return solveSpaceOpt(slices);
    }
};