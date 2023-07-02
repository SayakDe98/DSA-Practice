// Given an integer array nums, find the subarray with the largest sum, and return its sum.

//                                                                      Example 1 :

//     Input : nums = [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ] Output : 6 Explanation : The subarray[4, -1, 2, 1] has the largest sum 6. Example 2 :

//     Input : nums = [1] Output : 1 Explanation : The subarray[1] has the largest sum 1. Example 3 :

//     Input : nums = [ 5, 4, -1, 7, 8 ] Output : 23 Explanation : The subarray[5, 4, -1, 7, 8] has the largest sum 23.

//                                                                 Constraints :

//                                                                 1 <= nums.length <= 105 - 104 <=
//                                                                 nums[i] <= 104

//                                                                 Follow up : If you have figured out the
//                                                                             O(n) solution,
//             try coding another solution using the divide and conquer approach, which is more subtle.

#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int> &A, int i, bool mustPick, vector<vector<int>> &dp)
    {
        if (i >= size(A))
            return mustPick ? 0 : -1e5;
        if (dp[mustPick][i] != -1)
            return dp[mustPick][i];
        if (mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i + 1, true, dp));
        return dp[mustPick][i] = max(solve(A, i + 1, false, dp), A[i] + solve(A, i + 1, true, dp));
    }
};

int main() {
    Solution s;
    s.maxSubArray();
    return 0;
}