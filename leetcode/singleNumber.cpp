// 136. Single Number
// Easy

// 15190

// 611

// Add to List

// Share
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:

// Input: nums = [1]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++)
        {
            count[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (count[nums[i]] == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main () {
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution s;
    cout << s.singleNumber(nums);
    return 0;
}