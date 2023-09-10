// Given a sorted array of distinct integers and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.

//                                                                                                                      You must write an algorithm with
//                                                                                                                      O(log n) runtime complexity.

//                                                                                                                      Example 1 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 5 Output : 2 Example 2 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 2 Output : 1 Example 3 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 7 Output : 4

//                      Constraints :

//                      1 <= nums.length <= 104 - 104 <=
//                      nums[i] <= 104 nums contains distinct values sorted in ascending order.- 104 <= target <= 104
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        if (target > nums[end])
            return n;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (target > nums[mid])
            {
                start = mid + 1;
            }

            if (target <= nums[mid])
            {
                end = mid;
            }
        }
        return start;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 7);
    return 0;
}