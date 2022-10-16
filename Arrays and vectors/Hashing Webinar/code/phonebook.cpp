#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;

int main()
{
    map<string , list<string>> phonebook;

    //1 key of Prateek with 3 values stored in list of string type
    phonebook["Prateek"].push_back("1111111111");
    phonebook["Prateek"].push_back("1111111112");
    phonebook["Prateek"].push_back("1111111113");

    //1 key of Krishan with 3 values stored in list of string type
    phonebook["Krishna"].push_back("2111111111");
    phonebook["Krishna"].push_back("2111111112");
    phonebook["Krishna"].push_back("2111111113");

    for(pair<string , list<string>> item : phonebook)
    {
        //try to print it
    }   

    return 0;
}