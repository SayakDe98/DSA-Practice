#include<iostream>

using namespace std;

void reachHome (int src, int &dest) { // &dest means no new copy of variable is created hence we save memory since dest doesn't change
    if (src == dest) {
        cout << "Reached Home";
        return;
    }

    cout << (src == 0 ? "Started Journey" : "On the Way...") << endl;

    reachHome (src + 1, dest);
} 

int main () {
    int src = 0; // we start from 0
    int dest = 5;
    reachHome(src, dest);
    return 0;
}