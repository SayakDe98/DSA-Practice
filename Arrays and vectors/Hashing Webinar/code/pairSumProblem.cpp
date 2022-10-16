 //Given a set of numbers print pairs whose sum is equal to k
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void pairSum(vector<int> arr , int sum)//total complexity of this program is O(n)
{
    unordered_set<int> s;

    for(int i=0;i<arr.size();i++)
    {
        int x = sum - arr[i];

        if(s.find(x)!=s.end())
        {
            cout<<x<<" & "<<arr[i]<<endl;
        }
        s.insert(arr[i]);//we are inserting after doing the find operation hence we can search for duplicate values as well.
    }
    
}

 int main()
 {
    int k;

    cout<<"Enter the value of k:"<<endl;

    cin>>k;

    //Approaches to solve this problem:
    //1.Two nested loops. One loop for iterating the fast moving pointer O(N^2)
    //2.Sorting + two pointer O(nlogn) . One pointer for fast moving and one pointer for slow moving pointer
    //3.Sorting + Binary Search O(nlogn)
    //4.Hashing O(n) best approach
    //we will do hashing as we go through the array.

    vector<int>arr ={10,5,2,3,-6,9,11,2};

    pairSum(arr,k);
    return 0;
 }