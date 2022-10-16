//method 1 : set the ith bit to 0 then do or operation with that bit
#include<iostream>
using namespace std;

void updateithBit(int &n, int i, int v){
    int mask = (v << i);
    
    n = n | mask;

    cout << n << endl;
}

int main(){
    int n = 13;//number to be operated on is n = 13
    int i, v;//i is the bit which we want to change and v is value of the bit we want to change to

    cin >> i >> v;

    updateithBit(n, i, v);

    return 0;
}