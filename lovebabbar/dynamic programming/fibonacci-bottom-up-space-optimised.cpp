#include<iostream>
using namespace std;

int main () {
    int n = 518;
    int prev1 = 1;// this is equivalent to dp[1]
    int prev2 = 0; // this is equivalent of dp[0]
    if (n == 0) {
        return prev2;
    }
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        // shift logic
        prev2 = prev1;
        prev1 = current;
    }
    cout << prev1 << endl;
    return 0;
}