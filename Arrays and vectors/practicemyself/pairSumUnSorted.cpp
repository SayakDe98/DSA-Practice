#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool pairSum(const vector<int> & arr , int targetSum)//O(N) T.C.
{
    unordered_set<int> comp;//unordered_set stores only unique keys, comp means complement

    for(auto value : arr)
    {
        if(comp.find(value)!=comp.end())
        {
            return true;
        }
        comp.insert(targetSum-value);//assuming it won't underflow
    }
        return false;
}

int main()
{
    vector<int> arr = {10,2,1,4,4,6};

    int sum = 8;

    int result = pairSum(arr , sum);    

    if(result == true)
        cout << "Suitable pair present"<<endl;

    else
        cout << "Suitable pair absent" <<endl;

    return 0;
}