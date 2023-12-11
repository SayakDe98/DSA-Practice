#include<string>
#include<iostream>
using namespace std;

// string reverseString(string input, int lastIndex) {
//     if (lastIndex < 0) {
//         return "";
//     }

//     return input[lastIndex] + reverseString(input, lastIndex - 1);
// }

// int main () {
//     string s = "abcde";
//     cout << reverseString(s, s.length() - 1);
//     return 0;
// }

// Alternate better:
#include<string>
#include<iostream>
using namespace std;

void reverse(int i, int j, string &s) {
    if (i > j) {
        return;
    }

    swap(s[i], s[j]);
    i++;
    j--;

    reverse(i, j , s);
}

int main () {
    string s = "abba";
    string temp = s;
    int i = 0, j = s.length() - 1;
    reverse(i, j, s);
    cout << "reversed: "<< s << endl;
    if (s == temp) {
        cout << "pallindrome";
    } else {
        cout << "not pallindrome";
    }
    return 0;
}