//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
private:
    int solve(int index, int A[], int diff)
    {
        if (index < 0)
        {
            return 0;
        }

        int ans = 0;

        for (int j = index - 1; j >= 0; j--)
        {
            if (A[index] - A[j] == diff)
                ans = max(ans, 1 + solve(j, A, A[index] - A[j]));
        }
        return ans;
    }

    int solveMemo(int index, int A[], int diff, unordered_map<int, int> dp[])
    {
        if (index < 0)
        {
            return 0;
        }
        if (dp[index].count(diff))
        {
            return dp[index][diff];
        }
        int ans = 0;

        for (int j = index - 1; j >= 0; j--)
        {
            if (A[index] - A[j] == diff)
                ans = max(ans, 1 + solveMemo(j, A, A[index] - A[j], dp));
        }
        return dp[index][diff] = ans;
    }

public:
    int lengthOfLongestAP(int A[], int n)
    {
        // code here
        if (n <= 2)
        {
            return n;
        }

        int ans = 0;
        // recursion
        //  for(int i = 0; i < n; i++) {
        //      for(int j = i + 1; j < n; j++) {
        //          ans = max(ans, 2 + solve(i, A, A[j] - A[i]));
        //      }
        //  }
        // memoization
        //  unordered_map<int, int> dp[n+1];
        //  for(int i = 0; i < n; i++) {
        //      for(int j = i + 1; j < n; j++)
        //          ans = max(ans, 2 + solveMemo(i, A, A[j] - A[i], dp));
        //  }
        //  return ans;

        // tabulation
        //  unordered_map<int, int> dp[n+1];
        vector<vector<int>> dp(n + 1, vector<int>(A[n - 1] - A[0] + 1, INT_MIN));
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j];
                int count = 1;

                // if(dp[j].count(diff))//checking if already present
                //     count = dp[j][diff];
                if (dp[j][diff] != INT_MIN)
                    count = dp[j][diff];

                dp[i][diff] = 1 + count; // taking current element
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends