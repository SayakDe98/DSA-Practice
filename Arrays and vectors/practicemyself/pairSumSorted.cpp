#include<iostream>
#include<vector>
using namespace std;

bool pairSum(const vector<int> &arr1 , int sum)//O(N) T.C.
{
    int low = 0;
    
    int high = arr1.size()-1;

    cout<<high <<endl;

    while(low < high)
    {
        int s = arr1[low] + arr1[high];
        if(s == sum)
        {
            cout<<"Pair found: ";
            cout<< arr1[low] << " , "<<arr1[high]<<endl;
            return true;
        }
        else if(s < sum)
        {   
            cout<<"Too small ";
            cout<<"Low"<<low<<"value:"<<arr1[low];
            cout<<"High"<<high<<"value:"<<arr1[high]<<endl;
            low++;
        }
        else if(s > sum)
        {   
            cout<<"Too large ";
            cout<<"Low "<<low<<" value: "<<arr1[low]<<" & ";
            cout<<"high "<<high<<" value: "<<arr1[high]<<endl;
            high--;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {1,2,4,4,6};

    int sum = 8;

    int result = pairSum(arr , sum);    

    if(result == true || result == 1)
        cout << "Suitable pair present"<<endl;

    else
        cout << "Suitable pair absent" <<endl;

    return 0;
}