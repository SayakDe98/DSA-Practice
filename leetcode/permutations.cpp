// Given an array nums of distinct integers, return all the possible permutations.You can return the answer in any order.

//                                                  Example 1 :

//     Input : nums = [ 1, 2, 3 ] Output : [ [ 1, 2, 3 ], [ 1, 3, 2 ], [ 2, 1, 3 ], [ 2, 3, 1 ], [ 3, 1, 2 ], [ 3, 2, 1 ] ] Example 2 :

//     Input : nums = [ 0, 1 ] Output : [ [ 0, 1 ], [ 1, 0 ] ] Example 3 :

//     Input : nums = [1] Output : [[1]]

//                                 Constraints :

//                                 1 <= nums.length <= 6 - 10 <=
//                                 nums[i] <= 10 All the integers of nums are unique.

// Approach
//     Not need of an extra array,
//     just use swap on every element.

//     Complexity
//         Time complexity : O(N *N !)
//                               Space complexity : O(N !)
//                                                      Code
#include<vector>
#include<iostream>
using namespace std;

class Solution 
{
    
    public:
        vector<vector<int>> v;

        void solve(vector<int> &a, int idx)
        {
            if (idx >= a.size())
            {
                v.push_back(a);
                return;
            }

            for (int i = idx; i < a.size(); i++)
            {
                swap(a[i], a[idx]);
                solve(a, idx + 1);
                swap(a[i], a[idx]);
            }
        }

        vector<vector<int>> permute(vector<int> &nums)
        {
            solve(nums, 0);
            return v;
        }
   
};

int main() {
    Solution s;
    vector<int> a = { 1, 2, 3 };
    auto res = s.permute(a);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}