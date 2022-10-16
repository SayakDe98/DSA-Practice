//set the ith bit to 1
//to do this do masking then do or operation with current number
#include<iostream>
using namespace std;

void setIthBit(int &n, int i){
    int mask = (1 << i);

    n = n | mask;

    cout << n << endl;//output is the resultant number in decimal
}

int main(){

    int n = 5;
    int i;
    cin >> i;

    setIthBit(n, i);

    return 0;
}