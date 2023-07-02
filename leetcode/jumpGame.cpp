// You are given an integer array nums.You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

//     Return true if you can reach the last index,
//     or false otherwise.

//         Example 1 :

//     Input : nums = [ 2, 3, 1, 1, 4 ] Output : true Explanation : Jump 1 step from index 0 to 1,
//             then 3 steps to the last index.Example 2 :

//     Input : nums = [ 3, 2, 1, 0, 4 ] Output : false Explanation : You will always arrive at index 3 no matter what.Its maximum jump length is 0,
//             which makes it impossible to reach the last index.

//                 Constraints :

//                 1 <= nums.length <= 104 0 <= nums[i] <= 105

//Approach:
//We start at 0th index, we can jump max of steps = value of current element
//We have a reachable variable and if current index is greater than reachable then we can't reach last index
//On every iteration where i <= reachable we update reachable with max(current index + current element) because that is the max reachable index till now from start.
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > reachable) {
                return false;
            }

            reachable = max(reachable, nums[i] + i);
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> jumper = { 2, 3, 1, 1, 4 };//returns 1 which is true
    // vector<int> jumper = { 3, 2, 1, 0, 4 };//returns 0 which is false
    cout << s.canJump(jumper) << endl;
    return 0;
}