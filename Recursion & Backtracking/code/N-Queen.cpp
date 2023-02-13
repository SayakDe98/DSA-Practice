#include<iostream>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y) {
    //column check
    for (size_t k = 0; k < x; k++)
    {
        /* code */
        if(board[k][y] == 1) {
            return false;
        }
    }
    
    //check left diagonal
    int i = x;
    int j = y;

    while(i >= 0 and j >= 0) {
        if(board[i][j] == 1) {
            return false;//we got a queen @left diag
        }
        i--;j--;// this helps us move in left diagonal
    }

    //Right diag
    i = x;
    j = y;
    while (i >= 0 and j < n) {
        if(board[i][j] == 1) {
            return false;//we got a queen @ right diag
        }
        i--; j++;// this helps us move in right diagonal
    }
    
    return true;
    
}

void printBoard(int n, int board[][20]) {

    for (size_t i = 0; i < n; i++)
    {
        /* code */
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
}

bool solveNQueen(int n, int board[][20], int i) {
    
    //base case
    //if we reach row == N we are done
    if(i == n) {
        //Print the board
        printBoard(n, board);
        return true;
    }

    //recursive case
    //try to place queen in every row
    for (size_t j = 0; j < n; j++)
    {
        /* code */
        //check whether current position i and j are safe or not
        //check only upper two diagonals and vertical upper column
        if(canPlace(board, n, i, j)) {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);//to check that with this position of queen in this column for this row queen can be placed 
            //for the successive rows successfully
            if(success) {
                return true;
            }
            //backtrack 
            board[i][j] = 0;//removes queen from current position because success = false if we place queen here
        }
    }
    
    return false;//something failed and parent needs to change queen position
}

int main() {
    int board[20][20] = {0};// create a board
    int n;
    cin >> n;
 
    solveNQueen(n, board, 0);
    return 0;
}