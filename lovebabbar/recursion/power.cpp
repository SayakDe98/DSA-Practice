#include<iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    if (b == 1) {
        return a;
    }

    if (b % 2 == 0) {
        return power(a, b / 2) * power(a, b / 2);
    }
    // if (b % 2 == 1) {
        return a * power(a, b / 2) * power(a, b / 2);
    // } 
}

int main() {
    int a,b;
    // cin >> a >> b;
    a = 2;
    b = 4;
    int ans = power(a,b);
    cout << "Answer: " << ans << endl;
    return 0;
}