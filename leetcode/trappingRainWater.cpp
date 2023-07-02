// Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

//                                                                                                 Example 1 :

//     Input : height = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ] Output : 6 Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case,
//             6 units of rain water(blue section) are being trapped.Example 2:

// Input : height = [ 4, 2, 0, 3, 2, 5 ] Output : 9

//                  Constraints :

//     n == height.length 1 <= n <= 2 * 104 0 <= height[i] <= 105

// Approach
    // Here the approach is like we basically find the left max and right max and based on that we start our movement in two pointer , first have a glance at the below depicted figure which is later followed by explaination.

    // As shown in the figure we start with finding the left most height and the right most height and then we do left++ , right-- and continue. Now if the new left height is greater than max left height then we update the lmax height and similarly for the right side.
    // When This is not the case the we proceed with the side with the minimum height , say it's left for the further understanding , now we take the difference b/w the left heights and add to the water stored i.ei.ei.e water += lmax - height[lpos]; or water += rmax - height[rpos]; according to the current scenario as explained above.
    // In the same way depicted above we further continue till the loop i.ei.ei.e ends while(lpos <= ros) then we would finally obtain the water which can be trapped during this process. https://leetcode.com/problems/trapping-rain-water/solutions/3401992/100-detailed-explaination-with-pictures-in-c-java-python-two-pointers/
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n - 1];
        int lpos = 1;
        int rpos = n - 2;
        int water = 0;
        while (lpos <= rpos)
        {
            if (height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if (height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if (lmax <= rmax && height[lpos] < lmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        }
        return water;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}
