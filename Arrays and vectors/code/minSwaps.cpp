//Given an array of size N, find the minimum number of swaps needed to make the array as sorted

//Sample Input:
//a1 = [5,4,3,2,1]

//Sample Output: 2

//5&1 4&2 , hence 2 swaps

//Sample input:
//a1 = [2,4,5,1,3]

//Sample output:3

//2&1, 4&2 5&3

//Sample Input:
//a1 = [10,11,5,4,3,2,1]

//Sample Output: 4

//We can't use bubble or merge sort because they don't minimize number of sorts they just concerned with sorting

//We should know correct location of each element
//We can use nlogn inbuilt sorting algo

//2 11 5 4 3 10 1//we swaped 10 & 2
//11 2 5 4 3 10 1//swapped 2 & 11
//1 2 5 4 3 10 11//swapped 11 and 1
//1 2 3 4 5 10 11//we swapped 5 & 3,hence total swaps to sort = 4
//For a cycle containing n elements we will need n - 1 swaps

//So find all the non itersecting cycles present in the array
//For each cycle we need to know the size and number of swaps will be  size - 1

//we compare the old and new locations and check which elements are completing the cycle
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minSwaps(vector<int> arr)
{
    // Know the actual positions of elements (sorting)
    //store the current indices
    int n = arr.size();

    pair<int , int> ap[n];
    
    for(int i = 0 ; i < n ; i++)
    {
        ap[i].first = arr[i];

        ap[i].second = i;
    }

    //sorting
    sort(ap , ap + n);

    //building the main logic
    vector<bool> visited(n , false);

    int ans = 0;

    for(int i = 0 ; i < n ; i++)
    {
        int old_position = ap[i].second;

        //if element is visited or is in the right side
        if(visited[i] == true or old_position == i)
        {
            continue;
        }

        //visiting the element or index for the first time
        int node = i;

        int cycle = 0;

        while(!visited[node])
        {
            visited[node] = true;

            int next_node = ap[node].second;

            node = next_node;

            cycle += 1;
        }


    ans += cycle - 1;//n - 1 swaps
    }

    return ans;
}

int main()
{
    vector<int> arr{2, 4, 5, 1, 3};

    cout << "Minimum number of swaps required : " << minSwaps(arr) << endl;

    return 0;
}