#include <bits/stdc++.h>
bool isSafe(int row, int col, vector<vector<int>> &sudoku, int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (sudoku[row][i] == val)
        {
            return false; // if val exists in current row
        }
        if (sudoku[i][col] == val)
        {
            return false; // if val exists in current col
        }

        if (sudoku[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
        {
            return false; // if val exists in current 3 * 3 grid
        }
    }
}

bool solve(vector<vector<int>> &sudoku)
{
    int n = sudoku.size(); // will always be 9

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        { // traverse whole sudoku matrix
            if (sudoku[row][col] == 0)
            { // if we get a empty cell
                for (int val = 1; val <= 9; val++)
                { // try out all values from 1 to 9
                    if (isSafe(row, col, sudoku, n, val))
                    {
                        sudoku[row][col] = val; // place the val for current position

                        bool solutionExists = solve(sudoku);
                        if (solutionExists)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][col] = 0; // backtrack if solution didn't exist with this val
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &sudoku)
{
    // Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}