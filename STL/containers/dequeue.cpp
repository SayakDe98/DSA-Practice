//deletion and insertion at both ends
//dynamic data structure
//random access possible using at operation

#include<deque>
#include<iostream>
using namespace std;

int main() {
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_back(6);
    
    for(int i: d) {
        cout << i << " ";
    }

    cout << endl;

    d.pop_back();

    cout << "After popping from back: ";

    for (int i : d)
    {
        cout << i << " ";
    }

    cout << endl;

    d.pop_front();

    cout << "After popping from front: ";

    for (int i : d)
    {
        cout << i << " ";
    }

    cout << "Element at first index" << d.at(1) << endl;

    cout << "front: " << d.front() << endl;

    cout << "back: " << d.back() << endl;

    cout << "Before Erase: ";

    for(int i: d) {
        cout << i << " ";
    }

    cout << endl;

    d.erase(d.begin(), d.begin() + 1);
    cout << "After Erase: ";

    for(int i: d) {
        cout << i << " ";
    }

    cout << "Empty or not? " << d.empty() << endl;
    

    return 0;
}