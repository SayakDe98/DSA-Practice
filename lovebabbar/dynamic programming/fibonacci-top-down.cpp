#include<vector>
#include<iostream>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n == 0 || n == 1) {
        return n;
    }

    dp[n] = (dp[n - 1] != -1 ? dp[n - 1] : fib(n - 1, dp)) + (dp[n - 1] != -2 ? dp[n - 2] : fib(n - 2, dp));
    return dp[n];
    // if (dp[n] != -1) {
    //     return dp[n];
    // }

    // return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    // cin >> n;
    n = 519;
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp);
    return 0;
}