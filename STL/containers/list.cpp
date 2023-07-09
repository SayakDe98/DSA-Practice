//Doubly linked list is used to create list. 

#include<list>
#include<iostream>
using namespace std;

int main() {
    list<int> li;

    li.push_back(1);
    li.push_front(2);
    cout << "After pushing two elements: ";
    for(int i: li) {
        cout << i << " ";
    }
    cout << endl;
    //erase has O(n) complexity
    li.erase(li.begin());
    cout << "After erase: ";
    for(int i: li) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Size of list:" << li.size() << endl;

    list<int> li1(5, 100);
    for(int i: li1) {
        cout << i << " ";
    }
    return 0;
}