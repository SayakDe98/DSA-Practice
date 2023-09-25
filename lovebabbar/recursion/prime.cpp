#include<iostream>
using namespace std;
// bool prime (int n) { // for iterative approach
bool prime (int n, int i) { // for recursive approach
    // iterative approach:
    // for (int i = n - 1; i > 1; i--) {
    //     if (n % i == 0) {
    //         cout << i << endl;
    //         return false;
    //     }
    // }
    // return true;

    // recursive approach
    if (i == 1) {
        return true; // base case
    }
    if (n % i == 0) {
        return false;
    }
    return prime (n, i - 1);

}

int main() {
    int n = 2;
    // cout << (prime(n) == 1 ? "Prime" : "Not Prime") << endl; // iterative approach
    cout << (prime(n, n - 1) == 1 ? "Prime" : "Not prime") << endl; // recursive approach

    return 0;
}