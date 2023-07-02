//FIFO

#include<queue>
#include<iostream>
using namespace std;

int main() {
    queue<string> q;

    q.push("Love");
    q.push("Babbar");
    q.push("Kumar");

    cout << "First element: " << q.front() << endl;
    cout << "Size before pop(): " << q.size() << endl;
    q.pop();

    cout << "First element after pop(): " << q.front() << endl;

    cout << "Size after pop(): " << q.size() << endl;
    return 0;
}