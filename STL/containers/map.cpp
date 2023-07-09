//Data is stored in form of key value pair
//All the keys will be unique and a key will point only 1 value
//Love(key) can point to scorpio(value) and Babbar(key) is pointing to scorpio(value) that is two different keys are pointing to one value.
//But there cannot be duplicate keys.

#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int, string> m;

    m[1] = "babbar";
    m[2] = "love";
    m[13] = "kumar";

    for(pair i: m) {
        // cout << typeid(i).name() << endl;
        cout << i.first << endl;//sequence of printing is in ascending order of keys
    }
    //For unordered_map sequence if keys is random
    //There is another way of inserting key value pairs:
    // m.insert(5, "bheem");//this isn't working idk why
    m[5] = "bheem";
    for(pair i: m) {
        cout << i.first << " " + i.second << endl;
    }

    cout << "Finding 13: " << m.count(13) << endl;
    cout << "Finding -13: " << m.count(-13) << endl;

    cout << "Before erase: " << endl;

    for(pair i: m) {
        cout << i.first << ": " << i.second << endl;
    }

    cout << "After erase: " << endl;

    m.erase(5);
    for(pair i: m) {
        cout << i.first << ": " << i.second << endl;
    }

    //Search complexity of this map is O(logn) which comes from red black tree or balanced tree
    //Search complexity of unordered_map is O(1) which comes from hashtable
    map<int, string>::iterator it = m.find(5);//returns iterator for an element
    
    cout << (*it).first << endl;//returns the position of iterator
    for(map<int, string>::iterator i = it; i != m.end(); i++) {
        cout << (*i).first << endl;
    }
    return 0;
}