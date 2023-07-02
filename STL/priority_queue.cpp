//For max heap: The first element will always be greatest(default)
//For min heap: The first element will always be smallest

#include<queue>
#include<iostream>
using namespace std;

int main() {
    priority_queue<int> maxi;//this is based on max heap.Whenever we fetch we get greatest element

    //for min heap:
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    
    int n = maxi.size();
    
    for(int i = 0; i < n; i++) {
        cout << maxi.top() << endl;
        maxi.pop();
    }

    cout << endl;

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    int m = mini.size();

    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << endl;
        mini.pop();
    }
    return 0;
}