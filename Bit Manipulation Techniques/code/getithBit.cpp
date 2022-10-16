//WAP to get i th Bit
//WAP to set i th Bit
//WAP to clear i th Bit

//let n = 5
//5 = 000101, to get 2nd bit we are talking about 2nd bit from LHS
#include<bits/stdc++.h>
using namespace std;

size_t getIthBit(size_t n, size_t i){
    //to get the i th bit we will left shift 1 i times and then do the bitwise & of the 1 << i with the number
    int mask = (1 << i);

    return (mask & n) > 0 ? 1 : 0;
}

int main(){
    size_t n = 5;
    size_t i;
    
    cin >> i;

    cout << getIthBit(n, i) << endl;

    return 0;
}