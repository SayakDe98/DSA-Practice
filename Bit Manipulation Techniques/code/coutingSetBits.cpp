//Count the number of set bits in a number
//example: 9 -> 1001 it has 2 set bits

//how to approach:
//to get last bit we do and operation with 1
//then we can right shift the original number then do and operration with 1 again

#include<iostream>
using namespace std;

//method 1
int countSetBits(int &n){
    int count = 0;
    while(n > 0){
        int last_bit = n & 1;

        count += last_bit;

        n = n >> 1;
    }

    return count;
}

//method 2
int count_bits_hack(int n){
    int ans = 0;

    while(n > 0){
        //removes the last set bit from current answer
        n = n & (n - 1);

        ans++;
    }

    return ans;
}

int main(){
    int n = 5;

    // cout << countSetBits(n) << endl;
    //OR
    cout << count_bits_hack(n) << endl;

    return 0;
}