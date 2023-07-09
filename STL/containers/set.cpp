//Only unique elements are present in a set
//Behind the scenes there is use of BST. If we have an element inside the set
//we can either delete it or add it. Modifications aren't allowed.
//Data is returned in sorted order.
//Set is slower than unordered set. In unordered set elements are stored in 
//random order that is not in sorted order.
//In set the elements will be sorted as well.

#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;
    //Insert operation happens in O(logn)
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(0);

    for(auto i: s) {
        cout << i << endl;
    }

    s.erase(s.begin());//we have given the iterator of s.begin() so the first element gets deleted

    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;
    //Let's delete 2 elements
    set<int>::iterator it = s.begin();
    it = it++;
    s.erase(it);

    for(auto i: s) {
        cout << i << endl;
    }

    cout << "Is 5 present? " << s.count(5) << endl;//is element 5 present??
    
    set<int>::iterator itr = s.find(5);//finds the iterator of 5

    cout << "value present at itr: " << *itr << endl;

    for(auto it = itr; it != s.end(); it++) {//we are printing all elements from 5
        cout << *it << endl;
    }
    return 0;
}