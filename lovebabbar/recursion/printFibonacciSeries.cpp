#include<iostream>
using namespace std;

void fibonacci (int a, int b, int start, int &n) {
    if (start == n - 2) {
        cout << a << endl;
        return;
    }
    cout << a << endl;
    cout << b << endl;
    a = a + b;
    b = a + b;
    fibonacci(a, b, start + 1, n);
}

int main () {
    int a = 0;
    int b = 1;
    int n = 5;
    int start = 1;
    fibonacci(a, b, start, n);
    return 0;
}