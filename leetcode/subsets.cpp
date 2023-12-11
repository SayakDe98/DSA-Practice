// 78. Subsets
//     Medium

//     15867

//     233

//     Add to List

//         Share
//             Given an integer array nums of unique elements,
//     return all possible subsets(the power set).

//            The solution set must not contain duplicate subsets.Return the solution in any order.

//            Example 1 :

//     Input : nums = [ 1, 2, 3 ] Output : [ [], [1], [2], [ 1, 2 ], [3], [ 1, 3 ], [ 2, 3 ], [ 1, 2, 3 ] ] Example 2 :

//     Input : nums = [0] Output : [ [], [0] ]

//                                 Constraints :

//                                 1 <= nums.length <= 10 - 10 <=
//                                 nums[i] <= 10 All the numbers of nums are unique.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        void solve(vector<int> nums, int index, vector<int> output, vector<vector<int> >& ans) {
            // base case
            if(index >= nums.size()) { // if index more than input array
                ans.push_back(output);
                return;
            }

            // exclude
            solve(nums, index + 1, output, ans); // do nothing just increment index by 1

            // include
            int element = nums[index];
            output.push_back(element);
            solve(nums, index + 1, output, ans);
        }
    public:
        vector<vector<int> > subsets(vector<int> &nums) {
            vector<vector<int>> ans;
            vector<int> output;
            int index  = 0;
            solve(nums, index, output, ans);
            return ans;
        }
};

int main () {
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int> > res = s.subsets(nums);
    for (vector<int> i: res) {
        cout << "{";
        for (int j: i) {
            cout << j << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}