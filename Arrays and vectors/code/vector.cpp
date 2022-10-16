#include<iostream>

#include<vector>

using namespace std ;

int main()
{
    // vector <int> arr ;

    // cout << arr.size() << endl ; // returns 0 , arr.size() returns the number of elements
    
    vector <int> arr = {1 , 2 , 5 ,10 , 15} ;

    cout << arr.size() << endl ; // returns 5

    cout << arr.capacity() << endl; // returns 5 because we initialized 5 elements at starting
    
    arr.push_back(17) ;

    cout << arr.size() << endl; // returns 6 because we added one extra element at O(1) time complexity

    cout << arr.capacity() << endl; // returns 10 because doubling of memory occurs when we add more elements than what was initialized.

    arr.push_back(20);

    arr.push_back(23);
    
    arr.push_back(25);
    
    arr.push_back(28);
    
    arr.push_back(30);

    cout<< arr.capacity() << endl;// as we got more than 10 the size of array in memory doubled.

    cout << "The elements in the array are : " << endl ;

    arr.pop_back() ; //it is used to delete the last element from the array.
    
    for(int i = 0 ; i < arr.size() ; i++) //arr.size() is used to get the size of the array so we use it access the elements of the dynamic array arr called vector
        cout << arr[i] << endl;

    //insert is used to insert into the middle of vector, 
 
    //erase is used to remove an element from a vector.

    //Fill constructor : use this to fill and initialized vector.

    vector<int> arr1  (10 , 7); // Fill constructor

    cout << "Output from Fill constructor : " << endl ; //Fill constructor is used to fill a vector with same element once or several number of times.

    for(int i = 0 ; i < arr1.size() ; i++) //accessing elements using for loop
        cout << arr1[i] << endl ;
    
    

    return 0;

}