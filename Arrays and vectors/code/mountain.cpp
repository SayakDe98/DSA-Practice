//Write a function that takes input an array of distinct integers
//and returns the length of the highest mountain.
//  * A mountain is defined as set of adjacent integers that are
//    strictly increasing until they reach a peak at which the become strictly decreasing
//  * Atleast 3 numbers are required to form a mountain.

//example 5,10,8 because 5 middle number is bigger than other two.

//Sample input : [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
//Sample output : 9

//How to approach such problems:
//1)Identify peaks. Peak is an element whose previous element is smaller and the next element is larger than it.
//2)Once a peak is identified keep moving backwards(downwards) till you reach a peak.Keep adding 1 for each element traversed backwards.
//3)Similarly for the elements which are after the peak till we reach next peak we need to keep a count for that as well.
//we need to also keep a highest peak variable

//Total T.c. : worst case is < O(2N)
//O(N) time complexity
//we will be calulating the downhill at left of peak only
//we will calculate the downhill at right of peak when we move forward i.e. move to next peak
#include<vector>
#include<iostream>

using namespace std;

int highest_mountain(vector<int> arr)
{
    int highest_peak = 0;

    int n = arr.size();

    for(int i = 1 ; i < n - 1 ;)//-1 because last element can't be a peak
    {
       //check if a[i] is a peak or not
       if(arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
       {
        //do some work
        int count = 1;
        int j = i;
        //count backwards (left)
        while(j >= 1 and arr[j] > arr[j-1])
        {
            j--;
            count++;
        }
        //count forwards(right)
        while(i <= n - 2 and arr[i] > arr[i + 1])
        {
            i++;
            count++;
        }
        highest_peak = max(highest_peak , count);
       }
       else
       {
        i++;
       }
    }

    return highest_peak;
}

int main()
{
    vector<int> arr {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout << highest_mountain(arr) <<endl;

    return 0;
}