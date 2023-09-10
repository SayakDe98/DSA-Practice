#include<iostream>
using namespace std;

string URLify (string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            result += "%20";
        } else {
            result += s[i];
        }
    }
    return result;
}

int main () {
    string s = "Mr 3ohn Smith";
    cout << URLify(s);
    return 0;
}