//1. we will check the number of bits
//2. we will have 0's for last i positions which we want to clear
//3. we will do binary AND operation with the current number

#include<iostream>
using namespace std;

int clearLastiBits(int &n, int i){
//let's have all 1's then do left shift it to i positions
//to get all 1's we need to do ~0 or -1
    // int mask = (-1 << i);
    // OR
    int mask = ((~0) << i);

    n = n & mask;

    return n;
}

int main(){
    int n = 15;
    int i;

    cin >> i;

    cout << clearLastiBits(n, i) << endl;

    return 0;
}