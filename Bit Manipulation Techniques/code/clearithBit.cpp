//clear ith bit means set the ith bit to 0
#include<iostream>
using namespace std;

void clearithBit(int &n, int i){
    int mask = ~(1 << i);

    n = n & mask;

    cout << n << endl;
}

int main(){
    int n = 13;

    int i;

    cin >> i;

    clearithBit(n, i);

    return 0;
}