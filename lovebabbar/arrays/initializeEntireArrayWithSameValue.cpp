#include<vector>
#include<iostream>
using namespace std;
int main() {
    vector<int> s(100000,-24);
    for(int i: s) {
        cout << i << endl;
    }
    return 0;
}