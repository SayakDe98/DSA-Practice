#include<iostream>
using namespace std;

int highestPowerOf2(int k){
    int res = 0;
    for (size_t i = k; i >= 1; i--)
    {
        /* code */
        if((i & (i - 1)) == 0){
            res = i;
            break;
        }
    }
    return res;
}

int earthLevels(int n){
    int lvl = 0;

    if((n & (n - 1)) == 0){
        return 1;//if exactly power of 2
    }

    //divide by closest power of 2 which is just less than current number
    while(n > 0){
        n -= highestPowerOf2(n);
        lvl++;
    }

    return lvl;
}

int main(){
    int n;

    cout << "Enter the number of steps: " << endl;

    cin >> n;

    cout << "The minimum number of levels: " << earthLevels(n) << endl;
    
    return 0;
}