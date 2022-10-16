//Write a function to check if a number is odd or even
//n % 2 == 0 -> even
//n % 2 == 1 -> odd
//using bitwise operator:
//all even numbers have last bit 0 and odd numbers last bit is 1
//so check if last bit 1 or 0
//so we can do & with number we will get 1 or 0 if we get 1 its odd number else if it is 0 then it is even number.
#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t n;

    cout << "Enter a number" << endl;

    cin >> n;

    if(n & 1){
        cout << "Odd" << endl;
    } else{
        cout << "Even" << endl;
    }

    return 0;
}