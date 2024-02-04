class Solution
{
private:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
    {
        if (index == nums1.size())
            return 0;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        if (swapped)
        {
            swap(prev1, prev2);
        }
        int ans = INT_MAX;
        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = solve(nums1, nums2, index + 1, 0);
        }

        if (nums1[index] > prev2 && nums2[index] > prev1)
        { // we are not doing swap originally but we are checking it like this as if they were swapped
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));
        }

        return ans;
    }

    int solveMemo(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
    {
        if (index == nums1.size())
            return 0;
        if (dp[index][swapped] != -1)
        {
            return dp[index][swapped];
        }
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        if (swapped)
        {
            swap(prev1, prev2);
        }
        int ans = INT_MAX;
        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = solveMemo(nums1, nums2, index + 1, 0, dp);
        }

        if (nums1[index] > prev2 && nums2[index] > prev1)
        { // we are not doing swap originally but we are checking it like this as if they were swapped
            ans = min(ans, 1 + solveMemo(nums1, nums2, index + 1, 1, dp));
        }

        return dp[index][swapped] = ans;
    }
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        // create dp
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0)); // nums1.size() + 1 because index + 1 exists in loop

        // handle base cases
        // we will run 2 loops and outer loop will not run for index == nums1.size()
        for (int index = nums1.size() - 1; index >= 1; index--)
        { // index>=1 because index-1 for 0 will be invalid index
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                if (swapped)
                {
                    swap(prev1, prev2);
                }
                int ans = INT_MAX;
                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = dp[index + 1][0];
                }

                if (nums1[index] > prev2 && nums2[index] > prev1)
                { // we are not doing swap originally but we are checking it like this as if they were swapped
                    ans = min(ans, 1 + dp[index + 1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int solveSpaceOpt(vector<int> &nums1, vector<int> &nums2)
    {
        int swap = 0, noSwap = 0, currSwap = 0, currNoSwap = 0;
        // handle base cases
        // we will run 2 loops and outer loop will not run for index == nums1.size()
        for (int index = nums1.size() - 1; index >= 1; index--)
        { // index>=1 because index-1 for 0 will be invalid index
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                if (swapped)
                { // swap was giving error so we created our own
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }
                int ans = INT_MAX;
                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = noSwap;
                }

                if (nums1[index] > prev2 && nums2[index] > prev1)
                { // we are not doing swap originally but we are checking it like this as if they were swapped
                    ans = min(ans, 1 + swap);
                }

                // dp[index][swapped] = ans;
                if (swapped)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            swap = currSwap;
            noSwap = currNoSwap;
        }
        return min(swap, noSwap);
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swapped = 0;
        // return solve(nums1, nums2, 1, swapped);
        // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        // return solveMemo(nums1, nums2, 1, swapped, dp);
        // return solveTab(nums1, nums2);
        return solveSpaceOpt(nums1, nums2);
    }
};