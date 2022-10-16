#include<iostream>
#include<unordered_map>
#include<map>
using namespace std ;

int main()
{
    //unordered_map<string , int > menu ;//O(1) for unordered_map
    map<string , int > menu ;//O(logn) operation for map

    //Insert key-value pairs inside the hashtable O(1) operation
    menu["maggi"] = 15 ;
    menu["cold drink"] = 20 ;
    menu["dosa"] = 99 ;
    menu["pizza"] = 499 ;
    menu["indianplatter"] = 399 ;

    //cout << menu["dosa"] ; //square brackets is the overloaded operator. This is operator overloading . operator overloading is done by default by the STL.
 
    //update query
    menu["dosa"] = (1 + 0.1) * menu["dosa"];//incrementing dosa price by 10%

    //deletion
    menu.erase("dosa");

    //Search inside a collection of key value pairs inside this hash table:
    string item ;
    cout << "Enter an item to search : " << endl ;
    cin >> item;

    //searching done in O(1) time
    if(menu.count(item) == 0)//menu.count(item) returns 0 or 1
    {
        cout << item << " is not available" <<endl;
    }

    else
    {
        cout << item << " is available, and its cost is " << menu[item] << endl;
    }

    //we can iterate over all key-value pairs that are present
    for(pair<string,int> item: menu) // O(N) time for iteration
    {
        cout<<item.first<<"-"<<item.second<<endl; // first is for key,second is for value
    }//Random order hence name unordered map , for map we have in lexicographical sorted order,sorting done for keys only.

    
    return 0 ;
}
