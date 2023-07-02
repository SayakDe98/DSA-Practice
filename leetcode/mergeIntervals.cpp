// Given an array of intervals where intervals[i] = [ starti, endi ], merge all overlapping intervals, and return an array of the non - overlapping intervals that cover all the intervals in the input.

//                                                                                                                                      Example 1 :

//     Input : intervals = [ [ 1, 3 ], [ 2, 6 ], [ 8, 10 ], [ 15, 18 ] ] Output : [ [ 1, 6 ], [ 8, 10 ], [ 15, 18 ] ] Explanation : Since intervals[1, 3] and [ 2, 6 ] overlap,
//                                   merge them into[1, 6].Example 2 :

//     Input : intervals = [ [ 1, 4 ], [ 4, 5 ] ] Output : [[ 1, 5 ]] Explanation : Intervals[1, 4] and [ 4, 5 ] are considered overlapping.

//                                                                                                              Constraints :

//                                                                                                              1 <= intervals.length <= 104 intervals[i].length ==
//                                                                                                          2 0 <= starti <= endi <= 104

// Intuition
//         We can solve this question using Array +
//     Sorting.

//     Approach
//         We can easily understand the approach by seeing the code which is easy to understand with comments.

//     Complexity
//         Time complexity : Time Complexity : O(NlogN),
//     Sorting the array(intervals) costs O(NlogN). Where N is the size of the Vector(intervals).

// Space complexity:
// Space Complexity : O(1), Constant Space. Extra space is only allocated for the Vector(output)
// which can go upto size N, however the output does not count towards the space complexity.

#include<iostream>
#include<vector>
#include<algorithm>
                          using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval: intervals) {
            if(output.empty() || output.back()[1] < interval[0]) {
                output.push_back(interval);
            } else {
                output.back()[1] = max(interval[1], output.back()[1]);
            }
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<vector<int>> input = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
    auto ans = s.merge(input);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0;j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}