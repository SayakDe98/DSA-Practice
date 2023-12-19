//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    int solve(int &n, int *a, int curr, int prev)
    {
        if (curr == n)
        {
            return 0;
        }
        int include = 0;

        if (prev == -1 || a[prev] <= a[curr])
        {
            include = 1 + solve(n, a, curr + 1, curr);
        }

        int exclude = 0 + solve(n, a, curr + 1, prev);
        return max(include, exclude);
    }

    int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
    {
        // base case
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // include
        int include = 0;
        if (prev == -1 || a[curr] > a[prev])
            include = 1 + solveMem(n, a, curr + 1, curr, dp);

        // exclude
        int exclude = 0 + solveMem(n, a, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }

    int solveTab(int n, int a[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // we don't need to check for base case because we will run from next iteration

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                    include = 1 + dp[curr + 1][curr + 1]; // we need to take n+1 when initializing rows as we did above because we are doing n - 1 + 1 and max size of array is n and index in array ends at n-1
                // curr+1 for column because we need to change coordinate
                // exclude
                int exclude = 0 + dp[curr + 1][prev + 1]; // loop runs for prev = -1 so prev+1 since -1 is not valid index

                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][-1 + 1]; // we are doing +1 because -1 is not valid array index
    }

    int solveSpaceOpt(int n, int a[])
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        // we don't need to check for base case because we will run from next iteration

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                    include = 1 + nextRow[curr + 1]; // we need to take n+1 when initializing rows as we did above because we are doing n - 1 + 1 and max size of array is n and index in array ends at n-1
                // curr+1 for column because we need to change coordinate
                // exclude
                int exclude = 0 + nextRow[prev + 1]; // loop runs for prev = -1 so prev+1 since -1 is not valid index

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[-1 + 1]; // we are doing +1 because -1 is not valid array index
    }

    int solveOptimal(int n, int a[])
    {
        if (n == 0)
        {
            return 0;
        }

        vector<int> ans;
        ans.push_back(a[0]); // because we always include the 1st element at start
        for (int i = 1; i < n; i++)
        { // n tc
            if (a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin(); // find the index on which the just greater element exists nlogn tc
                ans[index] = a[i];
            }
        }
        return ans.size(); // total tc = nlogn
    }

public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        //   vector<int> ans(n, -1);
        int prevIndex = -1;
        int currIndex = 0;
        //   return solve(n, a, currIndex, prevIndex);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solveMem(n, a, currIndex, prevIndex, dp);
        // return solveTab(n, a);
        // return solveSpaceOpt(n, a);
        return solveOptimal(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends