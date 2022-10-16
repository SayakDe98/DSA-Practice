//Given an array containing N integers and an number S denoting a target sum.
//Find all distinct integers that can add up to form target sum.
//The numbers in each triplet should be ordered in ascending order,
//and triplets should be ordered too.
//Return empty array if no such triplet exists.

//Input: array = [1,2,3,4,5,6,7,8,,9,15]
//target=18

//Output:
//[[1,2,15]
//[3,7,8]
//[4,6,8]
//[5,6,7]]

//Approach 1 : Brute force: using 3 loops : O(n^3)

//Approach 2 : Use the pair-sum problem to solve this problem
//Start from a number say start from 1 then solve pair sum problem with 2 and solve for remaining array
//O(n^2) (time)+ O(n)(space)

//Approach 3 : to reduce space we need to avoid using a DS(unordered_set here
//Find all pairs whose sum = 7, we can do two pointer approach
//Time complexity : O(n) but array must be sorted.
//If array isn't sorted we need to sort it and sorting takes nlogn
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Two pointer approach
vector<vector<int>> triplets(vector<int> &arr , int sum)
{
    // sort(arr.begin(),arr.end());//if we are given unsorted array we sort it.Also don't pass const vector<int> &arr because then we can't change arr. Also sorting increase time complexity.
    int low = 1;
    int high = arr.size() - 1;
    int pairSum = 0;
    vector<vector<int>> triplet;
    for(auto i = 0 ; i < arr.size() - 2 ; i++)
    {
        while(low < high)
        {
            pairSum = arr[low] + arr[high];

            if(pairSum + arr[i]== sum)
            {
                triplet.push_back({arr[i], arr[low],arr[high]});
                low++;
                high--;
            }
            else if(pairSum < sum)
            {
                low++;
            }
            else if(pairSum > sum)
            {
                high--;
            }
        }
    }
    return triplet;
}

int main()
{
   vector<int> arr {1,2,3,4,5,6,7,8,9,15};
    // vector<int> arr {12,1,2,3,4,5,6,7,8,9,15};//if we provide unsorted array make sure to sort it in the triplets function
    int targetSum = 18 ;
    auto result = triplets(arr , targetSum);
    
    if(result.size() != 0)
    {
        cout << "The triplets are : "<<endl;

        for(auto i : result)
        {
            for(auto v : i)
            {
                cout << v << "  ";
            }
            cout << endl;
        }
    }

    else
    {
        cout << "Triplets are absent" << endl;
    }

    return 0;
}