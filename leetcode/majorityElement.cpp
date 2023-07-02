// Given an array nums of size n, return the majority element.

//                                           The majority element is the element that appears more than ⌊n /
//                                           2⌋ times.You may assume that the majority element always exists in the array.

//                                           Example 1 :

//     Input : nums = [ 3, 2, 3 ] Output : 3 Example 2 :

//     Input : nums = [ 2, 2, 1, 1, 1, 2, 2 ] Output : 2

//                    Constraints :

//     n == nums.length 1 <= n <= 5 * 104 - 109 <= nums[i] <= 109
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int count = 0;
        int element = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (count >= nums.size() / 2)
            {
                return element;
            }
            if (element == nums[i + 1])
            {
                count++;
            }
            else
            {
                element = nums[i + 1];
            }
        }
        return element;
    }
};

int main () {
    Solution s;
    vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
    cout << s.majorityElement(nums) << endl;
    return 0;
}