#include <bits/stdc++.h>
#include<vector>
long long int spaceOptimizedTabulation(vector<int> &nums)
{
    long long int prev2 = 0;
    long long int prev1 = nums[0];
    long long int n = nums.size();
    for (long long int i = 1; i < n; i++)
    {
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;
        long long int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if (n == 1)
    {
        return valueInHouse[0];
    }
    vector<int> first, last;
    // long long int ans = solveRec(valueInHouse, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(valueInHouse[i]);
        }
        if (i != 0)
        {
            last.push_back(valueInHouse[i]);
        }
    }
    return max(spaceOptimizedTabulation(first), spaceOptimizedTabulation(last));
}