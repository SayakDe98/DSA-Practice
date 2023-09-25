// https : // www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
        int
        countDistinctWays(int nStairs)
{
    //  Write your code here.

    if (nStairs < 0)
    {
        return 0;
    }
    if (nStairs == 0)
    {
        return 1;
    }
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}
int main() {
    cout << countDistinctWays(3) << endl;
    return 0;
}