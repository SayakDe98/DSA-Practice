//Decimal to Binary
//Convert a number from decimal format into binary format.

//Input: N = 10

//Output: 1010
#include<iostream>
using namespace std;

string decimalToBinary(int n){
    string s;
    string ans;

    while(n > 0){
        s += to_string(n % 2);

        n /= 2;
    }

    for(int i = s.length() - 1; i >= 0; i--){
        ans += s[i]; 
    }

    return ans;
}

int main(){
    int n;

    cout << "Enter a number in decimal" << endl;

    cin >> n;

    cout << "It's binary equivalent is: " << decimalToBinary(n);
    
    return 0;
}