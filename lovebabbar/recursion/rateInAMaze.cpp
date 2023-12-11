// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.
// Your Task:  
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

// Constraints:
// 2 ≤ N ≤ 5
// 0 ≤ m[i][j] ≤ 1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int i, int j, int n, vector<vector<int>> m, vector<vector<int>> visited)
    {
        if ((i >= 0 && i < n) && (j >= 0 && j < n) && visited[i][j] == 0 && m[i][j] == 1)
        {
            return true; // safe condition
        }
        else
        {
            return false; // unsafe condition
        }
    }

    void solve(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans)
    {
        // we are in x, y index

        // Mark this position / spot as visited
        visited[x][y] = 1;

        // base case: we reached destination
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // Down
        int i = x + 1;
        int j = y;
        if (isSafe(i, j, n, m, visited))
        {
            path.push_back('D');
            solve(m, n, i, j, visited, path, ans);
            path.pop_back(); // backtrack to remove this path such that we can have more ways to reach dest
        }
        // Up
        i = x - 1;
        j = y;
        if (isSafe(i, j, n, m, visited))
        {
            path.push_back('U');
            solve(m, n, i, j, visited, path, ans);
            path.pop_back(); // backtrack to remove this path such that we can have more ways to reach dest
        }
        // Left
        i = x;
        j = y - 1;
        if (isSafe(i, j, n, m, visited))
        {
            path.push_back('L');
            solve(m, n, i, j, visited, path, ans);
            path.pop_back(); // backtrack to remove this path such that we can have more ways to reach dest
        }
        // Right
        i = x;
        j = y + 1;
        if (isSafe(i, j, n, m, visited))
        {
            path.push_back('R');
            solve(m, n, i, j, visited, path, ans);
            path.pop_back(); // backtrack to remove this path such that we can have more ways to reach dest
        }

        visited[x][y] = 0; // backtrack to remove this path such that we can have more ways to reach dest
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        // Create an ans vector type string
        vector<string> ans;
        // First check if src = 0, then return empty array
        if (m[0][0] == 0)
        {
            return ans;
        }

        // Create a path to store the path
        string path = "";

        // Create src
        int srcx = 0;
        int srcy = 0;

        // Copy the maze into m
        vector<vector<int>> visited = m;
        // Mark every spot with 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        // Solve the problem recursively
        solve(m, n, srcx, srcy, visited, path, ans);

        // Sort the string to get lexicographically sorted answer
        sort(ans.begin(), ans.end());

        // return the answer
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
