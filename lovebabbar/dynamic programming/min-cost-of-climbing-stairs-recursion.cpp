#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
private:
    int solve(int n, vector<int> &cost) {
        if (n == 0 || n == 1) {
            return cost[n];
        }

        return min(solve(n - 1, cost), solve(n - 2, cost)) + cost[n];
    } 

    int solve2(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return cost[n];
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = min(solve2(n - 1, cost, dp), solve2(n - 2, cost, dp)) + cost[n];
        return dp[n];
    }

    int solve3(int n, vector<int>& cost) { // Bottom Up approach / tabulation
        vector<int> dp(n + 1);

        if(n == 0 || n == 1) {
            return cost[n];
        }

        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[n - 1], dp[n - 2]);

    }

public : 
    int minCostClimbingStairs(vector<int> &cost) {
            // Recursion(TLE):
            int n = cost.size();
            // return min(solve(n - 1, cost), solve(n - 2, cost));
            // Top Down:
            // vector<int> dp(n + 1, -1);
            // return min(solve2(n - 1, cost, dp), solve2(n - 2, cost, dp));
            //Bottom Up:
            return solve3(n, cost);
    }
};
