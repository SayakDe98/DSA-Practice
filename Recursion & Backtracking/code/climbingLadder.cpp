#include<iostream>
using namespace std;
//tc: O(3 ^ n) which is exponential so we use dynamic programming. Same sub problems occur multiple times in recursion tree that can be avoided by using dynamic programming
int climbingLadder(int n) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {// when n = 2 then n-3 will be -1 because in recursive case we are calling same function with n - 3 so when n < 0 return 0;
        return 0;
    }

    //recursive
    return climbingLadder(n - 1) + climbingLadder(n - 2) + climbingLadder(n - 3);
}

int main() {
    int N = 4;

    cout << climbingLadder(N) << endl;

    return 0;
}