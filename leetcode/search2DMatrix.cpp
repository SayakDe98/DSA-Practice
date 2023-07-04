#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> oneD;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                oneD.push_back(matrix[i][j]);
            }
        }
        if (oneD.empty())
        {
            return false;
        }

        if (oneD.size() == 1 && oneD[0] == target)
        {
            return true;
        }
        if (oneD.size() == 1)
        {
            return false;
        }
        int start = 0;
        int end = oneD.size();
        while (start <= end and start < oneD.size())
        {
            int mid = (start + end) / 2;
            if (oneD[mid] == target)
                return true;

            if (oneD[mid] < target)
            {
                start = mid + 1;
            }
            else if (oneD[mid] > target)
            {
                end = mid - 1;
            }
        }
        return false;
    }
};

int main () {
    Solution s;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}