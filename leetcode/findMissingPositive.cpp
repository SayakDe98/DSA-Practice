// Given an unsorted integer array nums, return the smallest missing positive integer.

//     You must implement an algorithm that runs in
//     O(n)
// time and uses constant extra space.

//     Example 1 :

//     Input : nums = [ 1, 2, 0 ] Output : 3 Explanation : The numbers in the range[1, 2] are all in the array.Example 2 :

//     Input : nums = [ 3, 4, -1, 1 ] Output : 2 Explanation : 1 is in the array but 2 is missing.Example 3 :

//     Input : nums = [ 7, 8, 9, 11, 12 ] Output : 1 Explanation : The smallest positive integer 1 is missing.
#include<vector>
#include<set>
#include<iostream>
using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int> &nums){
            int n = nums.size();//storing the size of nums vector because n will be reused
            set<int> set;//we are defining a set which will contain integers only
            for(int i = 0; i < n; i++) {
                set.insert(nums[i]);//storing vector's values into set so that we can use set.end() and set.find() functions for solving the problem
            }            

            int i = 1;//we start from the first positive integer
            while(i <= n) {//we run a loop from i = 1 to i = n
                if(set.find(i) != set.end()) {//if we find i inside the set we increment value of 1 and check for that value and so on...
                    i++;
                } else {
                    return i;//if we don't get the value of i inside the set we return i because it is absent
                }
            }
            return n + 1;//if we reach end of nums vector then we return nums's size + 1th value as per the given problem statement
        }
};

int main() {
    Solution s;
    vector<int> nums = { 7, 8, 9, 11, 12 };
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}