// Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.

//                                                                   If target is not found in the array,
//     return [ -1, -1 ].

//            You must write an algorithm with
//            O(log n) runtime complexity.

//            Example 1 :

//     Input : nums = [ 5, 7, 7, 8, 8, 10 ],
//             target = 8 Output : [ 3, 4 ] Example 2 :

//     Input : nums = [ 5, 7, 7, 8, 8, 10 ],
//             target = 6 Output : [ -1, -1 ] Example 3 :

//     Input : nums = [],
//             target = 0 Output : [ -1, -1 ]

//                                 Constraints :

//                                 0 <= nums.length <= 105 - 109 <=
//                                 nums[i] <= 109 nums is a non - decreasing array.- 109 <= target <= 109
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = { -1, -1 };
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid = (start + end) / 2;

        while(start <= end) {
            mid = (start + end) / 2;

            if(nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            }
        }
        start = 0;
        end = n - 1;
        mid = (start + end) / 2;
        while (start <= end)
        {
            mid = (start + end) / 2;

            if (nums[mid] == target)
            {
                ans[1] = mid;
                start = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto ans = s.searchRange(nums, 8);
    for(auto data: ans) {
        cout << data << endl;
    }
    return 0;
}