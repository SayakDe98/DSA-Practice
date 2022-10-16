#include<iostream>

#include<vector>

using namespace std ;

int main()
{

vector < vector <int> > arr={
    {1,2},//this row has 2 elements
    {3,4,5},//this row has 3 elements
    {6,7,8,9},//this row has 4 elements
    {10}//this row has 1 element
};

arr[0][0] += 10; // we accessed the element at 0th row and 0th column and added 10 i.e. updated it

for(int i = 0 ; i < arr.size() ; i++)
{
    for(int number : arr[i])
    {
        cout << number << "," ;
    }
    cout << endl ;
}

return 0;

}