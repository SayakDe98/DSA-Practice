#include<bits/stdc++.h>
using namespace std;

long long int powerModulo(int a, int b){
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed.
    long long int ans = ( pow(a, b) );
    return ans % 1000000007;
}

int main() {
    cout << powerModulo(5, 3) << endl;
    return 0;
}