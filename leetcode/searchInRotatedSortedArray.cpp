// There is an integer array nums sorted in ascending order(with distinct values).

//     Prior to being passed to your function,
//     nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length) such that the resulting array is[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]](0 - indexed).For example, [ 0, 1, 2, 4, 5, 6, 7 ] might be rotated at pivot index 3 and become[4, 5, 6, 7, 0, 1, 2].

//                                                                                                                                                                                                                                                                                     Given the array nums after the possible rotation and an integer target,
//     return the index of target if it is in nums, or -1 if it is not in nums.

//                                                      You must write an algorithm with O(log n) runtime complexity.

//                                                      Example 1 :

//     Input : nums = [ 4, 5, 6, 7, 0, 1, 2 ],
//             target = 0 Output : 4 Example 2 :

//     Input : nums = [ 4, 5, 6, 7, 0, 1, 2 ],
//             target = 3 Output : -1 Example 3 :

//     Input : nums = [1],
//             target = 0 Output : -1

//                                 Constraints :

//                                 1 <= nums.length
//                                 <= 5000 - 104 <=
//                                 nums[i] <= 104 All values of nums are unique.nums is an ascending array that is possibly rotated.- 104 <= target <= 104

// Intuition : The given problem asks us to find the index of the target element in the given rotated sorted array.

//             Approach : The solution provided in the code implements two approaches,
//     Brute force and Binary search.

//     The Brute force approach :

//     Iterates through the array and checks if the current element is equal to the target.If it is,
//     then it returns the index of that element, otherwise, it returns - 1. This approach has a time complexity of O(n).The Binary search approach is based on the fact that a rotated sorted array can be divided into two sorted arrays.

//                                                                        The approach starts with finding the mid element and compares it with the target element.If they are equal,
//     it returns the mid index.If the left half of the array is sorted, then it checks if the target lies between the start and the mid, and updates the end pointer accordingly.Otherwise, it checks if the target lies between mid and end, and updates the start pointer accordingly.If the right half of the array is sorted, then it checks if the target lies between mid and end, and updates the start pointer accordingly.Otherwise, it checks if the target lies between start and mid, and updates the end pointer accordingly.This process continues until the target element is found, or the start pointer becomes greater than the end pointer, in which case it returns - 1. This approach has a time complexity of O(log n).Complexity:
// Time Complexity :

//     The time complexity of the Brute force approach is
//     O(n),
//     where n is the size of the input array.The time complexity of the Binary search approach is O(log n),
//     where n is the size of the input array.Space Complexity : The space complexity of both approaches is O(1) as we are not using any extra space to store any intermediate results.

//                                                               Code : C++ Brute Force : class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (target == nums[i])
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

//let's do binary search below:
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mid = left + (right - left) / 2;
        if (nums[left] == target)
        {
            return 0;
        }

        if (nums[right] == target)
        {
            return right;
        }
        while (left <= right)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] >= nums[left])
            {
                if (target < nums[mid] and target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] and target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            mid = left + (right - left) / 2;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums, 0);
    return 0;
}