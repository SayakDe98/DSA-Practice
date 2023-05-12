// Given an array nums of n integers, return an array of all the unique quadruplets[nums[a], nums[b], nums[c], nums[d]] such that :

//                                           0 <= a,
//     b, c, d < n a, b, c, and d are distinct.nums[a] + nums[b] + nums[c] + nums[d] == target You may return the answer in any order.

//                                                                                      Example 1 :

//     Input : nums = [ 1, 0, -1, 0, -2, 2 ],
//             target = 0 Output : [ [ -2, -1, 1, 2 ], [ -2, 0, 0, 2 ], [ -1, 0, 0, 1 ] ] Example 2 :

//     Input : nums = [ 2, 2, 2, 2, 2 ],
//             target = 8 Output : [[ 2, 2, 2, 2 ]]

//                                 Constraints :

//                                 1 <= nums.length <= 200
// - 10^9 <= nums[i] <= 10^9
// - 10^9 <= target <= 10^9

// Intuition:
// The problem asks to find all unique quadruplets in the given array whose sum equals the target value. We can use a similar approach as we do for the 3Sum problem. We can sort the array and then use two pointers approach to find the quadruplets whose sum equals the target value.

// Approach:
// Sort the input array in non-decreasing order.
// Traverse the array from 0 to n-3 and use a variable i to keep track of the first element in the quadruplet.
// If the current element is the same as the previous element, skip it to avoid duplicates.
// Traverse the array from i+1 to n-2 and use a variable j to keep track of the second element in the quadruplet.
// If the current element is the same as the previous element, skip it to avoid duplicates.
// Use two pointers, left = j+1 and right = n-1, to find the other two elements in the quadruplet whose sum equals the target value.
// If the sum of the four elements is less than the target value, increment left pointer.
// If the sum of the four elements is greater than the target value, decrement right pointer.
// If the sum of the four elements is equal to the target value, add the quadruplet to the result and increment left and decrement right pointers.
// Skip duplicate values of left and right pointers to avoid duplicate quadruplets.
// Return the result.
// Complexity
// Time Complexity: O(n^3) where n is the length of the input array. The two outer loops run in O(n^2) time and the inner two-pointer loop runs in O(n) time.

// Space Complexity: O(1) because we are not using any extra space apart from the output array.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > quadruplets;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];

                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }

                        left++;
                        right--;
                    }
                }
            }
        }

        return quadruplets;
    }
};

int main()
{
    Solution s;
    vector<int> input = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int> > res = s.fourSum(input, target);

    for (auto i = 0; i < res.size(); i++)
    {
        for (auto j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}