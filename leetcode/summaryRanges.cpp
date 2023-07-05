You are given a sorted unique integer array nums.

    A range[a, b] is the set of all integers from a to
    b(inclusive)
        .

    Return the smallest sorted list of ranges that cover all the numbers in the array exactly.That is,
    each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

                                                                      Each range[a, b] in the list should be output as :

    "a->b" if a != b "a" if a == b

                                                                      Example 1 :

    Input : nums = [ 0, 1, 2, 4, 5, 7 ] Output : [ "0->2", "4->5", "7" ] Explanation : The ranges are : [ 0, 2 ]-- > "0->2"[4, 5]-- > "4->5"[7, 7]-- > "7" Example 2 :

    Input : nums = [ 0, 2, 3, 4, 6, 8, 9 ] Output : [ "0", "2->4", "6", "8->9" ] Explanation : The ranges are : [ 0, 0 ]-- > "0"[2, 4]-- > "2->4"[6, 6]-- > "6"[8, 9]-- > "8->9"

                                                                                                                Constraints :

                                                                                                                0 <= nums.length
                                                                                                                <= 20 - 231 <=
                                                                                                                nums[i] <= 231 - 1 All the values of nums are unique.nums is sorted in ascending order.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int n = nums.size();
        int prevIndex = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i < n and nums[i] == nums[i - 1] + 1)
            {

                continue;
            }
            else
            {
                int currIndex = i - 1; // Store the current index as i-1
                if (currIndex == prevIndex)
                {
                    // If the range has only one element, add it to the result
                    ans.push_back(to_string(nums[prevIndex]));
                }
                else
                {
                    // If the range has more than one element, add the range to the result
                    ans.push_back(to_string(nums[prevIndex]) + "->" + to_string(nums[currIndex]));
                }
                prevIndex = i; // Update the previous index to the current index
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    cout << s.summaryRanges(nums);
    return 0;
}