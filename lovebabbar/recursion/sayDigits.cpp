// #include<iostream>
// #include<string>
// using namespace std;

// string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};


// int reverseN (int n, int newN) {
//     if (n == 0) {
//         return newN;
//     }

//     int digit = n % 10;
//     newN = newN * 10 + digit;
//     n /= 10;
//     return reverseN(n, newN);
// }

// void sayDigits (int n) {
//     if (n == 0) {
//         return;
//     }
//     int digit = n % 10;
//     cout << arr[digit] << " ";
//     n /= 10;

//     sayDigits(n);
// }

// int main () {
//     int n = 412;
//     n = reverseN(412, 0); 
//     sayDigits(n);
//     return 0;
// }


// OR
#include <iostream>
#include <string>
using namespace std;

string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void sayDigits(int n)
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n /= 10;

    sayDigits(n);
    cout << arr[digit] << " ";
}

int main()
{
    int n = 412;
    sayDigits(n);
    return 0;
}