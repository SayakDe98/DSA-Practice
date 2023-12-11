#include<bits/stdc++.h>
#define MOD 100000007

//utility functions
int add (int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mult (int a, int b) {
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

//recursive solution
int solve (int n, int k) {
    if (n == 1) {
        return k;
    }

    if (n == 2) {
        return add(k, mult(k, k - 1));
    }

    int diffColors = mult(solve(n - 2, k), k - 1);
    int sameColors = mult(solve(n - 1, k), k - 1);
    return add(diffColors, sameColors);
}

//Top Down Approach
int solveTopDown(int n, int k, vector<int>& dp) {
    if (n == 1) {
        return k;
    }

    if (n == 2) {
        return add(k, mult(k, k - 1));
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int diffColors = mult(solveTopDown(n - 2, k, dp), k - 1);
    int sameColors = mult(solveTopDown(n - 1, k, dp), k - 1);
    dp[n] = add(diffColors, sameColors);
    return dp[n];
}

//Bottom Up Approach
int solveBottomUp (int n, int k) {
    vector<int> dp(n + 1);
    dp[1] = k;
    dp[2] = add(k, mult(k, k - 1));

    for (int i = 3; i <= n; i++) {
        int diffColors = mult(dp[i - 2], k - 1);
        int sameColors = mult(dp[i - 1], k - 1);
        dp[i] = add(diffColors, sameColors);
    }
    return dp[n];
}

//Space Optimised
int solveSpaceOptimized (int n, int k) {
    int prev2 = k;
    int prev1 = add(k, mult(k, k - 1));

    for (int i = 3; i <= n; i++) {
        int ans = add(mult(prev2, k - 1), mult(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    //recursive solution
    return solve(n, k);

    //top down approach
    vector<int> dp(n + 1, - 1);
    return solveTopDown(n, k, dp);

    //bottom up approach
    return solveBottomUp(n, k);

    //space optimized approach
    return solveSpaceOptimized(n, k);
}
