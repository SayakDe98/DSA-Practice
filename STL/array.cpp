#include<iostream>
#include<array>
//Similar type of elements are stored in contigious memory location and the size of an array is static
using namespace std;

int main() {
    int basic[3] = { 1, 2, 3 };//normal array without stl

    array<int, 3> a = { 1, 2, 3 };//stl array

    int size = a.size();

    for(int i = 0; i < size; i++) {
        cout << a[i] << endl;
    }

    //O(1) complexity methods on array
    cout << "Element at 2nd index: " << a.at(2) << endl;

    cout << "Empty or not? " << a.empty() << endl;

    cout << "First element: " << a.front() << endl;

    cout << "Last element: " << a.back() << endl;
}