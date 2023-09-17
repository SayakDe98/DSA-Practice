
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> copy;

        for (int i = 0; i < nums.size(); i++)
        {
            copy.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            copy[(i + k) % nums.size()] = nums[i];
        }

        nums.erase(nums.begin(), nums.end());
        for (int i = 0; i < copy.size(); i++)
        {
            nums.push_back(copy[i]);
        }
    }
};

int main () {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);
    cout << "[";
    for (int i: nums) {
        cout << i << " ";
    }
    cout << "]";
    return 0;
}