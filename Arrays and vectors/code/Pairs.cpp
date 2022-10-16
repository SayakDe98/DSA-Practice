//DONE IN practicemyself
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
//brute force
bool pairSumBruteForce(vector<int> &arr , int sum)//O(N^2)
{
    int currSum = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        for(int j = 0 ; j <arr.size() ; j++)
        {
            currSum = arr[i] + arr[j];
            if(currSum == sum)
                return true;
        }
    }
    return false;
}

bool pairSumBinarySearch(const vector<int> &arr1 , int sum1)//O(NlogN) with sorted array
{
    int low = 0;
    
    int high = arr1.size() - 1;

    int currSum = 0;
    while(low < high)
    {
        currSum = arr1[low] + arr1[high];

        if(currSum == sum1)
        {
            return true;
        }
        else if(currSum < sum1)
        {
            low++;
        }
        else if(currSum > sum1)
        {
            high--;
        }
    }
    return false;
}

//Approach 3 : unordered set/hashset/hashtable with assuming the complement is sum - current number
bool pairSumHashTable(const vector<int> &arr2 , int sum2)//O(N) complexity even with an unsorted array as input
{
    unordered_set<int> comp;

    for(auto value : arr2)
    {
        if(comp.find(value)!=comp.end())
        {
            return true;
        }
        comp.insert(sum2 - value);
    }

    return false;
}

//Approach 3 but returns the pair
vector<int> pairSumReturn(const vector<int> &arr3 , int sum3)
{
    unordered_set<int> S;

    vector<int> result;

    for(auto i = 0 ; i < arr3.size() ; i++)
    {
        int x = sum3 - arr3[i] ;
        if(S.find(i)!=S.end())
        {
            result.push_back(x);
            result.push_back(arr3[i]);

            return result ;
        }
        S.insert(arr3[i]);
    }

    return {};//returns an empty vector
}

int main()
{
    //Approach 1 : Brute Force:
    // vector<int> arr ={10,5,2,3,-6,9,11};

    // int sum = 4;

    // bool result = pairSumBruteForce(arr,sum);

    // if(result == true)
    //     cout<<"Pair exists"<<endl;
    // else
    //     cout<<"Pair doesn't exists"<<endl;

    //Approach 2: Binary Search with sorted array
    // vector<int> arr1 ={1,4,6,10};

    // int sum1 = 10;

    // bool result1 = pairSumBinarySearch(arr1 , sum1);

    // if(result1)
    // {
    //     cout<<"Pair exists"<<endl;
    // }
    // else
    // {
    //     cout<<"Pair doesn't exists"<<endl;
    // }

    //Approach 3:Hashtable approach using hashset i.e. unordered_set in c++
    // vector<int> arr2 = {10, 15, 8 ,8 ,5 ,1};

    // int sum2 = 16 ;

    //  bool result2 = pairSumBinarySearch(arr2 , sum2);

    // if(result2)
    // {
    //     cout<<"Pair exists"<<endl;
    // }
    // else
    // {
    //     cout<<"Pair doesn't exists"<<endl;
    // }

    vector<int> arr3 {10, 15, 8 ,8 ,5 ,1};

    int sum3 = 16 ;

    auto result3 = pairSumReturn(arr3 , sum3);

    if(result3.size()!=0)
    {
        cout<<"Pair exists and the pair is : "<<result3[0]<<" and "<<result3[1]<<endl;
    }
    else
    {
        cout<<"Pair doesn't exists"<<endl;
    }
    return 0;
}