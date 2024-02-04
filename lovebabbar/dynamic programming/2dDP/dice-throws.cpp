//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // long long solve(int dice, int faces, int target) {
    //     if(target < 0) {
    //         return 0;
    //     }

    //     if(dice == 0 && target != 0) {
    //         return 0;
    //     }

    //     if(target == 0 && dice != 0) {
    //         return 0;
    //     }

    //     if(dice == 0 && target == 0) {
    //         return 1;
    //     }

    //     long long ans = 0;

    //     for(int i = 1; i <= faces; i++) {
    //         ans += solve(dice - 1, faces, target - i);
    //     }
    //     return ans;
    // }
    long long solve(int faces, int dices, int target)
    {
        if (target < 0)
        {
            return 0;
        }

        if (dices == 0 && target != 0)
        {
            return 0;
        }

        if (target == 0 && dices != 0)
        {
            return 0;
        }

        if (dices == 0 && target == 0)
        {
            return 1;
        }

        long long ans = 0LL;

        for (int face = 1; face <= faces; face++)
        {
            ans += solve(faces, dices - 1, target - face);
        }
        return ans;
    }

    long long solveMemo(int faces, int dices, int target, vector<vector<long long>> &dp)
    {
        if (target < 0)
        {
            return 0;
        }

        if (dices == 0 && target != 0)
        {
            return 0;
        }

        if (target == 0 && dices != 0)
        {
            return 0;
        }

        if (dices == 0 && target == 0)
        {
            return 1;
        }

        if (dp[dices][target] != -1)
        {
            return dp[dices][target];
        }

        long long ans = 0LL;

        for (int face = 1; face <= faces; face++)
        {
            ans += solveMemo(faces, dices - 1, target - face, dp);
        }
        return dp[dices][target] = ans;
    }

    long long solveTab(int d, int f, int t)
    {
        vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));

        dp[0][0] = 1;
        for (int dice = 1; dice <= d; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                long long ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if (target - i >= 0)
                        ans += dp[dice - 1][target - i];
                }
                dp[dice][target] = ans;
            }
        }
        return dp[d][t];
    }

    long long solveSpaceOpt(int d, int f, int t)
    {
        vector<long long> prev(t + 1, 0);
        vector<long long> curr(t + 1, 0);

        prev[0] = 1;
        for (int dice = 1; dice <= d; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                long long ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if (target - i >= 0)
                        ans += prev[target - i];
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        return curr[t];
    }
    long long noOfWays(int M, int N, int X)
    {
        // code here
        // return solve(M, N, X);
        // vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
        // return solveMemo(M, N, X, dp);
        // return solveTab(N, M, X);
        return solveSpaceOpt(N, M, X);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends