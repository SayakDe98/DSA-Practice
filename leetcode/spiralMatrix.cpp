// Given an m x n matrix, return all elements of the matrix in spiral order.

//                               Example 1 :

//     Input : matrix = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ] Output : [ 1, 2, 3, 6, 9, 8, 7, 4, 5 ] Example 2 :

//     Input : matrix = [ [ 1, 2, 3, 4 ], [ 5, 6, 7, 8 ], [ 9, 10, 11, 12 ] ] Output : [ 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 ]

//                                                                                     Constraints :

//     m == matrix.length n == matrix[i].length 1 <= m,
//             n <= 10 - 100 <= matrix[i][j] <= 100

// sr : starting of row
//          er : end of row
//                   sc : starting of row
//                            ec : end of columns

// {first traverse first row increment starting row by one
// second traversal for insert last columns decrement last columns by 1
// third time insert last row decrement last row by one
// fourth time insert first row increment 1st column by row
// }
// repeat these all four steps untill sr <= er &&sc <= ec.

//                                                     Complexity
//                                                         Time complexity : O(m *n)

//                                                                               Space complexity : O(m *n)
#include<iostream>
#include<vector>
                                                                                                     using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int cnt = 0;
        int total = row * col;

        // index initialisation
        int sR = 0;       // starting row
        int sC = 0;       // starting column
        int eR = row - 1; // ending row
        int eC = col - 1; // ending column

        while (cnt < total)
        {

            // printing starting row
            for (int index = sC; cnt < total && index <= eC; index++)
            {
                ans.push_back(matrix[sR][index]);
                cnt++;
            }
            sR++;

            // printing ending column
            for (int index = sR; cnt < total && index <= eR; index++)
            {
                ans.push_back(matrix[index][eC]);
                cnt++;
            }
            eC--;

            // printing ending row
            for (int index = eC; cnt < total && index >= sC; index--)
            {
                ans.push_back(matrix[eR][index]);
                cnt++;
            }
            eR--;

            // printing starting column
            for (int index = eR; cnt < total && index >= sR; index--)
            {
                ans.push_back(matrix[index][sC]);
                cnt++;
            }
            sC++;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    auto z = s.spiralOrder(m);
    for(int i = 0; i < z.size(); i++) {
            cout << z[i] << " ";
    }
    return 0;
}