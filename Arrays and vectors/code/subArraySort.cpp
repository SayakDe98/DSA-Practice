//Given an array of size at-least two, find the smallest
//subarray that needs to be sorted in place so that entire 
//input array becomes sorted.

//If the input array is already sorted, the function should
//return [-1 , -1] , otherwise return the start & end index of smallest subarray.

//Input:
//a1 = [1,2,3,4,5,8,6,7,9,10,11]

//Output:[5,7]

//we can just sort the current array.
//and then compare the indexes
//if we see the values are different then we stop
//then we return the indices of left and right in an vector
//T.C = O(nlogn) , Space complexity: O(logn)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> subArraySort(vector<int> a)
{
    vector<int> b(a);//copies the value of a vector to vector b

    sort(a.begin() , a.end());

    int i = 0;

    int n = a.size();

    while(i < n and b[i] == a[i])
    {
        i++;
    }

    int j = a.size() - 1;

    while(j > 0 and b[i] == a[i])
    {
        j--;
    }

    if(i == a.size())//already sorted that is we reached the last element and all the elements are matching with the sorted array
        return { -1 , -1 };
    
    return { i , j };
}

//better approach : find the element for which left and right both are smaller, then if this is the first element which has left and right both less than itself then assign smallest and largest = current element
//else if it is larger than maximum then make it maximum , if it smaller than minimum then make it  minimum 
//once we don't get such elements we try to see for minimum element which is the place from where the array became unsorted note its index by storing it in a variable.
//also iterate from the last element which element isnt sorted in descending order, note its index and return that index as the last index which is unsorted.
//linear time for finding elements, linear time for finding positions hence tc = O(n) + O(n) = O(n)
//we have done this in another program named subArraySortOptimized


int main()
{
    vector<int> a{1,2,3,4,5,8,6,7,9,10,11};

    vector<int> arr = subArraySort(a);

    cout << "Starting position: " << arr[0] << "," << "ending position" << arr[1] << endl;

    return 0;
}