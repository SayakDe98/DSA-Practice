//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool solve(int index, int N, int *arr, int target)
    {
        if (index >= N)
        {
            return 0; // because we are unable to find ans till now and we reach out of array we return false
        }

        if (target < 0)
        {
            return 0; // if target becomes negative we are return false, because not achieveable
        }

        if (target == 0)
        {
            return 1; // if we reach target we return true
        }

        int incl = solve(index + 1, N, arr, target - arr[index]); // increment index by 1 and reduce target because we are closer to target by arr[index]
        int excl = solve(index + 1, N, arr, target - 0);

        return incl or excl;
    }

    bool solveMemo(int index, int N, int *arr, int target, vector<vector<int>> &dp)
    {
        if (index >= N)
        {
            return 0; // because we are unable to find ans till now and we reach out of array we return false
        }

        if (target < 0)
        {
            return 0; // if target becomes negative we are return false, because not achieveable
        }

        if (target == 0)
        {
            return 1; // if we reach target we return true
        }

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int incl = solveMemo(index + 1, N, arr, target - arr[index], dp); // increment index by 1 and reduce target because we are closer to target by arr[index]
        int excl = solveMemo(index + 1, N, arr, target, dp);

        return dp[index][target] = incl or excl;
    }

    bool solveTab(int N, int arr[], int total)
    {
        vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));

        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 1; // handling base case:   if(target == 0) { return 1;//if we reach target we return true
        }

        for (int index = N - 1; index >= 0; index--)
        {
            for (int target = 0; target <= total / 2; target++)
            {
                bool incl = 0;
                if (target - arr[index] >= 0)
                    incl = dp[index + 1][target - arr[index]];
                bool excl = dp[index + 1][target - 0];

                dp[index][target] = incl or excl;
            }
        }
        return dp[0][total / 2];
    }

    bool solveSpaceOpt(int N, int arr[], int total)
    {
        // vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));
        vector<int> currRow(total + 1, 0);
        vector<int> nextRow(total + 1, 0);
        // for(int i = 0; i <= N; i++) {
        //     dp[i][0] = 1; // handling base case:   if(target == 0) { return 1;//if we reach target we return true
        // }
        currRow[0] = 1;
        nextRow[0] = 1;
        for (int index = N - 1; index >= 0; index--)
        {
            for (int target = 0; target <= total / 2; target++)
            {
                bool incl = 0;
                if (target - arr[index] >= 0)
                    incl = nextRow[target - arr[index]];
                bool excl = nextRow[target - 0];

                currRow[target] = incl or excl;
            }
            nextRow = currRow;
        }
        return nextRow[total / 2];
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            total += arr[i];
        }
        if (total & 1)
        {
            return 0; // if odd sum then partition not possible
        }
        int target = total / 2;
        // return solve(0, N, arr, total / 2);
        // vector<vector<int>> dp(N + 1, vector<int> (target + 1, -1));
        // return solveMemo(0, N, arr, target, dp);

        // return solveTab(N, arr, total);
        return solveSpaceOpt(N, arr, total);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends