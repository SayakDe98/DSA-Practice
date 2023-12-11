#include<string>
#include<iostream>
using namespace std;

bool isPallindrome(string s, int i, int j) {
    if (i > j) {
        return true;
    }

    if (s[i] != s[j]) {
        return false;
    }

    return isPallindrome(s, i + 1, j - 1);
}
int main () {
    string s = "abba";
    cout << isPallindrome(s, 0, s.length() - 1);
    return 0;
}