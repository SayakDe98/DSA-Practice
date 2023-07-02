//Similar type of elements are stored in contigious memory location and the size of an vector is dynamic. If vector is filled then if we try to enter more elements then all elements till now will get copied to new vector with double size of previous vector and the old vector gets dumped.
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(1);
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(2);
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(3);
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;

    cout << "Ele at 2nd index: "<< v.at(2)<< endl;

    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    cout << "Before Pop: " << endl;

    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "After Pop: " << endl;

    for (int i : v)
    {
        cout << i << " ";
    }

    
}