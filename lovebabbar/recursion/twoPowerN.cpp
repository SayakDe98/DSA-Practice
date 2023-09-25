#include<iostream>

using namespace std;

// int twoPowerN (int n , int res) {
//     if (n == 0) {
//         return res;
//     }
//     res *= 2;
//     return twoPowerN(n - 1, res);
// }

// int main () {
//     int n = 3;
//     cout << twoPowerN(n, 1) << endl;
//     return 0;
// }

// using recursive relation:
int twoPowerN(int n) {
    if (n == 0) {
        return 1;
    } // base case
    // int smallerProblem = n - 1;
    // int biggerProblem = 2 * smallerProblem;
    // return biggerProblem;
    return 2 * twoPowerN(n - 1); // recursive relation
}

int main () {
    int n = 3;
    cout << twoPowerN(n) << endl;
    return 0;
}