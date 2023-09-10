// 80. Remove Duplicates from Sorted Array II
// Medium
// 5.9K
// 1.1K
// Companies
// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++)
// {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

//                         Example 1 :

//     Input : nums = [ 1, 1, 1, 2, 2, 3 ] Output : 5,
//             nums = [ 1, 1, 2, 2, 3, _ ] Explanation : Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.It does not matter what you leave beyond the returned k(hence they are underscores).Example 2 :

//     Input : nums = [ 0, 0, 1, 1, 1, 1, 2, 3, 3 ] Output : 7,
//             nums = [ 0, 0, 1, 1, 2, 3, 3, _, _ ] Explanation : Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.It does not matter what you leave beyond the returned k(hence they are underscores).

//                                                                                                                                                                        Constraints :

//                                                                                                                                                                        1 <= nums.length <= 3 * 104 - 104 <=
//                                                                                                                                                                        nums[i] <= 104 nums is sorted in non - decreasing order.

// Approach - 2
// here the given array is sorted. we use this consept here => at index i the element nums[i] is present more than two times in the array is nums[i] == nums[i-2]

// let assume nums [0,0,1,1,1,1,2,3,3]
// We start from index 2
// so nums[2] != nums[0] then the element in 2nd index is not more than 2 times. so we can add nums[2]
// but for index 4
// nums[4] == nums[2]
// sowe can not add the element nums[4]

// please dry run the solution for better understanding

// One edge case is if the size of nums is less than 2 then simple return the size

// Complexity
// Time complexity:
// O(n)
// O(n) O(n)
//     Space complexity : O(1) O(1) O(1)
#include<iostream>
#include<vector>
                           using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            if (nums.size() <= 2) {
                return nums.size();
            }
            int k = 0;
            for (int i = 2; i < nums.size(); i++) {
                if (nums[i] != nums[k]) {
                    nums[k + 2] = nums[i];
                    k++;
                }
            }
            return k + 2;
        }
};

int main () {
    Solution s;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}