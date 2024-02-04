class Solution
{
private:
    bool check(vector<int> &base, vector<int> &newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        { // for comparing length, height and width of base and new box
            return true;
        }
        return false;
    }
    int solveSpaceOpt(int n, vector<vector<int>> &a)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        // we don't need to check for base case because we will run from next iteration

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(a[curr], a[prev]))
                    include = a[curr][2] + nextRow[curr + 1]; // we need to take n+1 when initializing rows as we did above because we are doing n - 1 + 1 and max size of array is n and index in array ends at n-1, a[curr][2] because we are adding the height only to get the max height
                // curr+1 for column because we need to change coordinate
                // exclude
                int exclude = 0 + nextRow[prev + 1]; // loop runs for prev = -1 so prev+1 since -1 is not valid index

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[-1 + 1]; // we are doing +1 because -1 is not valid array index
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        // sort every dimension of all cuboids
        //  for(int i = 0; i < n; i++) {
        //      sort(cuboids[i].begin(), cuboids[i].end());
        //  }
        // alternative using for each loop
        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }
        // sort every cuboid
        sort(cuboids.begin(), cuboids.end());

        // solve the problem using Longest Increasing Subsequence
        return solveSpaceOpt(cuboids.size(), cuboids);
    }
};