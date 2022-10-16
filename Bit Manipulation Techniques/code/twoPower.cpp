//Find if a number is power of 2
//16 -> 10000, 15 -> 01111
//if n is a power of 2 then n - 1 will have all 1's except at msb
//hence n & (n - 1) = 0

#include<iostream>
using namespace std;

bool isPowerOf2(int &n){
    bool ans = false;

    if((n & (n - 1)) == 0){
        ans = true;
    }

    return ans;
}

int main(){
    int n;
 
    cin >> n;

    bool ans = isPowerOf2(n);
     
    if(ans){
       cout << "It is power of 2" << endl;
    } else{
       cout << "It is not power of 2" << endl;
    }

    return 0;
}