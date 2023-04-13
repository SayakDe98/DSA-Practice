//Problem Statement:

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

//Approach:
//Brute force:
//Use two loops:
//First loop runs from 0th index and we use the second loop for comparing with every other index in which element is present. We compare the addition of the two with target.
//If the target matches we staraigthway return the indices and end the program. We just need a pair of indices.
// #include<vector>
// #include<iostream>
// using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size(); i++) {
//             for(int j = i + 1; j < nums.size(); j++) {
//                 if(nums[i] + nums[j] == target) 
//                 return { i, j };
//             }
//         }
//         return { -1, -1 };
//     }

//     void print() {
//         vector<int> nums = { 2,7,11,15 };
//         int target = 9;

//         auto res = twoSum(nums, target);
//         for(int i = 0; i < res.size(); i++) {
//             i != res.size() - 1 &&  (cout << res[i] << ",");
//             i == res.size() - 1 && (cout << res[i]);
//         }
//     }
// };

// int main() {
//     Solution s;

//     s.print();

//     return 0;
// }

//Optimized approach: hashmap approach
//It is possible to solve this problem in linear time.
//We will have the current value as the key of hashmap and the current index as the value of hashmap.
//Steps to solve:
//1. Create a hashmap with integer as key and value
//2. We will check for every element till we get the required target or till the array / vector ends.
//3. The current number in array will serve as the key of hasmap and we will check if target - current key exists in hashmap if yes then we will return {(target - current) number's index, current index}

//For c++ we will use unordered_map as a hashmap. It has a key and a value. The key value pair is for unique.
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end())
                return { map[target - nums[i]], i };
            map[nums[i]] = i;
        }
        return { -1, -1 };
    }

  void print() {
        vector<int> nums = { 2, 7, 11, 15 };
        int target = 9;

        auto res = twoSum(nums, target);
        for(int i = 0; i < res.size(); i++) {
            i != res.size() - 1 &&  (cout << res[i] << ",");
            i == res.size() - 1 && (cout << res[i]);
        }
    }
};

int main() {
    Solution s;
    s.print();
    return 0;
}