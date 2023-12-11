#include<vector>
#include<iostream>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check if a queen exists in current row
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    // check if queen exists in upper diagonal
    x = row;
    y = col;

    while (x >= 0 and y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // check if queen exists in lower diagonal
    x = row;
    y = col;

    while (x < n and y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            temp.push_back(board[row][col]);
        }
    }
    ans.push_back(temp); // add board to ans
}

    void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans)
{
    if (col == n) { // base case, if we placed a queen in every column
        addSolution (board, ans, n); // add solution to board
        return;
    }

    for (int row = 0; row < n; row++) { // try to place a queen in every row for current column
        if (isSafe(row, col, board, n)) { // check if it is safe to place a queen in this row and column
            board[row][col] = 1;           // place the queen in current row and current column to check if this will create a n queen solution
            solve(col + 1, n, board, ans); // solve for next column recursively
            board[row][col] = 0; //backtracking to remove the queen from current row and column so we can find more solutions
        }
    }
}

    vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans; // make a variable to store the answer
    vector<vector<int>> board(n, vector<int>(n, 0)); // create a n * n board and all elements must be 0
    int starting_column = 0; // store the starting column for better understanding
    solve (starting_column, n, board, ans); // solve the problem recursively
    return ans;
}
