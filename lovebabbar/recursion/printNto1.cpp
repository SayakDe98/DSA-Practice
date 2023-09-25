#include<iostream>

using namespace std;

void printNto1 (int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    printNto1 (n-1); // tail recursion
}

int main () {
    int n;
    cout << "Input a number: ";
    cin >> n;
    cout << "Output: " << endl;
    printNto1(n);
    return 0;
}