//LIFO
#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string> s;
    s.push("Sayak");
    s.push("De");

    cout << "Element at top: " << s.top() << endl;

    //Let's remove top element
    s.pop();

    cout << "Element at top after using pop(): " << s.top() << endl;

    cout << "Size of stack: " << s.size() << endl;

    cout << "Empty stack? " << s.empty() << endl;

    return 0;
}