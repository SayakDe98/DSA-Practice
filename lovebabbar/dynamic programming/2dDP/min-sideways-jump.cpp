class Solution
{
private:
    int solve(vector<int> &obstacles, int currLane, int currPos)
    {
        int n = obstacles.size() - 1;
        if (currPos == n)
        {
            return 0; // because we reached the ending point hence we don't need to make sideways jump for that
        }

        if (obstacles[currPos + 1] != currLane)
        {                                                   // if there are no obstacles if we want to go straight for next position
            return solve(obstacles, currLane, currPos + 1); // we just increment the currPos of frog but don't change the lane
        }
        else
        {
            int ans = INT_MAX;

            // we only have 3 lanes(1,2 and 3) so we run a loop from 1 to 3

            for (int i = 1; i <= 3; i++)
            {
                if (currLane != i && obstacles[currPos] != i)
                {                                                     // we don't want to check for currLane and we don't want to go where there is obstacle
                    ans = min(ans, 1 + solve(obstacles, i, currPos)); // we are finding the minimum no of lanes because it might be possible there is no obstacles for curr position
                }
            }
            return ans;
        }
    }

    int solveMemo(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1;
        if (currPos == n)
        {
            return 0; // because we reached the ending point hence we don't need to make sideways jump for that
        }
        if (dp[currLane][currPos] != -1)
        {
            return dp[currLane][currPos];
        }
        if (obstacles[currPos + 1] != currLane)
        {                                                                                   // if there are no obstacles if we want to go straight for next position
            return dp[currLane][currPos] = solveMemo(obstacles, currLane, currPos + 1, dp); // we just increment the currPos of frog but don't change the lane
        }
        else
        {
            int ans = INT_MAX;

            // we only have 3 lanes(1,2 and 3) so we run a loop from 1 to 3

            for (int i = 1; i <= 3; i++)
            {
                if (currLane != i && obstacles[currPos] != i)
                {                                                             // we don't want to check for currLane and we don't want to go where there is obstacle
                    ans = min(ans, 1 + solveMemo(obstacles, i, currPos, dp)); // we are finding the minimum no of lanes because it might be possible there is no obstacles for curr position
                }
            }
            return dp[currLane][currPos] = ans;
        }
    }

    int solveTab(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9)); // initialize dp

        // base cases:
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {                                                      // if there are no obstacles if we want to go straight for next position
                    dp[currLane][currPos] = dp[currLane][currPos + 1]; // we just increment the currPos of frog but don't change the lane
                }
                else
                {
                    int ans = 1e9;

                    // we only have 3 lanes(1,2 and 3) so we run a loop from 1 to 3

                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && obstacles[currPos] != i)
                        {                                           // we don't want to check for currLane and we don't want to go where there is obstacle
                            ans = min(ans, 1 + dp[i][currPos + 1]); // we are finding the minimum no of lanes because it might be possible there is no obstacles for curr position. But we are doing bottom up so we do currPos+1 because INT_MAX present in all 3 lanes for curr lane.
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

    int solveSpaceOpt(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));//initialize dp
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        // base cases:
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {                                    // if there are no obstacles if we want to go straight for next position
                    curr[currLane] = next[currLane]; // we just increment the currPos of frog but don't change the lane
                }
                else
                {
                    int ans = INT_MAX;

                    // we only have 3 lanes(1,2 and 3) so we run a loop from 1 to 3

                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && obstacles[currPos] != i)
                        {                                // we don't want to check for currLane and we don't want to go where there is obstacle
                            ans = min(ans, 1 + next[i]); // we are finding the minimum no of lanes because it might be possible there is no obstacles for curr position. But we are doing bottom up so we do currPos+1 because INT_MAX present in all 3 lanes for curr lane.
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        int startingLane = 2;
        int startingPosition = 0;
        // return solve(obstacles, startingLane, startingPosition);
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));//there are 4 rows(lanes) and obstacles.size() number of positions
        // return solveMemo(obstacles, startingLane, startingPosition, dp);

        // return solveTab(obstacles);
        return solveSpaceOpt(obstacles);
    }
};