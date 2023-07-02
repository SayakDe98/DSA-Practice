// There is a robot on an m x n grid.The robot is initially located at the top - left corner(i.e., grid[0][0]).The robot tries to move to the bottom - right corner(i.e., grid[m - 1][n - 1]).The robot can only move either down or right at any point in time.

//                                                                                                                                                                                                                                   Given the two integers m and n,
//     return the number of possible unique paths that the robot can take to reach the bottom - right corner.

//                                                                                              The test cases are generated so that the answer will be less than
//                or equal to 2 * 109.

//                Example 1 :

//     Input : m = 3,
//             n = 7 Output : 28 Example 2 :

//     Input : m = 3,
//             n = 2 Output : 3 Explanation : From the top - left corner, there are a total of 3 ways to reach the bottom - right corner : 1. Right->Down->Down 2. Down->Down->Right 3. Down->Right->Down

//                                                                                                                          Constraints :

//                                                                                                                          1 <=
//                                                                            m,
//             n <= 100

// ✔️ Solution - II (Dynamic Programming - Memoization)

// The above solution had a lot of redundant calculations. There are many cells which we reach multiple times and calculate the answer for it over and over again. However, the number of unique paths from a given cell (i,j) to the end cell is always fixed. So, we dont need to calculate and repeat the same process for a given cell multiple times. We can just store (or memoize) the result calculated for cell (i, j) and use that result in the future whenever required.

// Thus, here we use a 2d array dp, where dp[i][j] denote the number of unique paths from cell (i, j) to the end cell (m-1, n-1). Once we get an answer for cell (i, j), we store the result in dp[i][j] and reuse it instead of recalculating it.
#include<iostream>
using namespace std;

class Solution {
    public:
        int dp[101][101]{};
        int uniquePaths(int m, int n, int i = 0, int j = 0) {
            if(i >= m || j >= n) {
                return 0;
            }
            if(i == m - 1 and j == n - 1) {
                return 1;
            }
            if(dp[i][j]) {
                return dp[i][j];
            }
            return dp[i][j] = uniquePaths(m, n, i + 1, j) + uniquePaths(m, n, i, j + 1);
        }
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    return 0;
}