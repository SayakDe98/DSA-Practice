#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
    //Set is a collection of keys
    unordered_set<int> s{1,2,3,8,11,15,0};//unordered set stores only keys

    s.insert(111);//isnertion

    s.erase(11);//O(1)

    int key;
    cout<<"Enter the key:"<<endl;
    cin>>key;

    if(s.find(key)!=s.end())//finding done @ O(1) time. s.end() is an iterator it returns the address of last element+1
    {
        cout<<key<<" is present"<<endl;
    }
    else
    {
        cout<<key<<" is not present"<<endl;
    }

    //Print all the elements of unordered set
    for(auto x : s)//random order of storing the values in unordred_set
    {
        cout<<x<<endl;
    }
    
    return 0;
}