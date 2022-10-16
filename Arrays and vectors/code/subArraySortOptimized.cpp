//better approach : find the element for which left and right both are smaller, then if this is the first element which has left and right both less than itself then assign smallest and largest = current element
//else if it is larger than maximum then make it maximum , if it smaller than minimum then make it  minimum 
//once we don't get such elements we try to see for minimum element which is the place from where the array became unsorted note its index by storing it in a variable.
//also iterate from the last element which element isnt sorted in descending order, note its index and return that index as the last index which is unsorted.
//linear time for finding elements, linear time for finding positions hence tc = O(n) + O(n) = O(n)
//we have done this in another program named subArraySortOptimized
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

bool outOfOrder(vector<int> arr , int i)//to check if elements are out of order
{
    int x = arr[i];

    //Corner cases
    if(i == 0)//0th element is out of order if 0th element > arr[1]
    {
        return x > arr[1];//if x > arr[1] return true
    }

    if(i == arr.size() - 1)//last element is out of order if last element is smaller than penultimate element
    {
        return x < arr[i - 1];//if x<arr[i-1] return true
    }

    return x > arr[i + 1] or x < arr[i - 1];//for elements other than 0th and last element to be  out of order this is the condition,then return true
}

pair<int , int> subArraySort(vector<int> arr)
{
    int smallest = INT_MAX;

    int largest = INT_MIN;

    for(int i = 0 ; i < arr.size() ; i++)
    {
        int x = arr[i];

        if(outOfOrder(arr , i))//check if current element is out of order
        {
            smallest = min(smallest , x);

            largest = max(largest , x);
        }
    }

    //next step we find the right index where smallest and largest lie(subarray)
    if(smallest == INT_MAX)//if smallest doesn't change,as smallest was initialized to INT_MAX
    {
        return {-1 , -1};//elements are in sorted manner
    }

    int left = 0;

    while(smallest >= arr[left])
    {
        left++;
    }

    int right = arr.size() - 1;

    while(largest <= arr[right])
    {
        right--;
    }

    return {left , right};//returns the left index and the right index
}

int main()
{
    vector<int> arr= {1,2,3,4,5,8,6,7,9,10,11};

    auto p = subArraySort(arr);

    cout << "Starting position: " << p.first << "," << "ending position: " << p.second << endl;

    return 0;
}