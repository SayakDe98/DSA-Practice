//Given n non-negative integers representing an elevation
//map where the width of each bar is 1 , compute how much water it can trap after raining.
//input: height=[0,1,0,2,1,0,1,3,2,1,2,1],width of each bar is 1
//output:6

//iteration on all the positions take n time.
//after going to each position we will calculate
//what is lvl of water in the left and what is lvl of water in the right
//It will again take n time. Hence total tc will be n^2

//We don't want to calculate maximum value in the left and maximum value in the right again and again
//We can build 2 arrays one for left and one for right
//In the left array we can fill in the left to right direction.
//We can store what is the highest lvl encountered so far
//For the right array we will iterate from right we will store the highest element from right

//let's suppose we are at a certain index,
//that index value stored is 1 , to its left the highest is 2 and to its right the highest is 3 then min(right_highest,left_highest) - current value = number of unit of water required.
//min(3,2) - 1 = 2 - 1 = 1
//water for ith index = min(l[i] , r[i]) - h[i]
//total water = summation of water for all the indexes
//T.C.:O(n) + O(n) = O(n)

#include<iostream>
#include<vector>

using namespace std;

int trappedWater(vector<int> heights)
{
    int n = heights.size();

    if(n <= 2) return 0;

    vector<int> left(n,0) , right(n,0); //initializing vector of n elements all of them are 0 each for left and right vector

    left[0] = heights[0];//for storing the value of the 0th element

    right[n - 1] = heights[n - 1];//for storing the value of the last element

    for(int i = 1 ; i < n ; i++)
    {
        left[i] = max(left[i - 1] , heights[i]);//current element is heights[i]. left[i - 1] contains the highest element till now. we are storing the highest element till now from left in left[i - 1]

        right[n - i - 1] = max(right[n - i] , heights[n - i - 1]);//storing the value of the highest element from right till this index
    }

    int water = 0;//initialize total water present as 0

    for(int i = 0 ; i < n ; i++)
    {
        water += min(left[i] , right[i]) - heights[i];//adding the water present
    }

    return water;//returning total water
}

int main()
{
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trappedWater(water) << endl;

    return 0;
}