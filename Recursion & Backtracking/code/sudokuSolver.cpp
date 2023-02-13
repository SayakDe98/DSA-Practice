#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no) {
    //check if no is present in row and col
    for (size_t k = 0; k < 9; k++)
    {
        if(mat[k][j] == no || mat[i][k] == no) {
            return false;//if we get nuber in same row or col we return false
        }
    }

    //check for subgrid
    int sx = (i / 3) * 3;//this is starting value of i(x - axis) for subgrid
    int sy = (j / 3) * 3;//this is starting point of j(y - axis) for subgrid
    
    for (size_t x = sx; x < sx + 3; x++)//go from sx to sx + 3 because in each subgrid there are elements from sx to sx + 3
    {
        /* code */
        for (size_t y = sy; y < sy + 3; y++)//go from sy to sy + 3 because in each subgrid there are elements from sy to sy + 3
        {
            /* code */
            if(mat[x][y] == no) {//if we get the number in subgrid return false
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    //base case
    if(i == n) {
        //print the solution
    for (size_t i = 0; i < 9; i++)
    {
        /* code */
        for (size_t j = 0; j < 9; j++)
        {
            /* code */
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
        return true;
    }
    //recursive case
    //end of the row
    if(j == n) {  
        return solveSudoku(mat, i + 1, 0, n);//start solving from next row
    }

    //skip prefilled cell
    if(mat[i][j] != 0) {
        return solveSudoku(mat, i, j + 1, n);
    }

    //cell to be filled
    //try out all possibilities
    for(int no = 1; no <= n; no++) {
        //whether it is safe to place the number or not
        if(isSafe(mat, i, j, no)) {
            mat[i][j] = no;//if number is safe we place it in matrix
            bool solveSubProblem = solveSudoku(mat, i , j + 1, n);//we solve subproblem
            if(solveSubProblem == true) {
                return true;//we return true if we can solve subproblem
            }
        }
    }

    //if no option works
    mat[i][j] = 0;// we make current cell as 0
    return false;//return false to previous cell
}

int main() {
    int n = 9;
    int mat[9][9] = {//initial matrix
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(!solveSudoku(mat,0,0,n)) {//if we can't solve sudoku we return no solution exists
        cout << "No solution exists!";
    }

    return 0;
}