#include<iostream>
#include<algorithm>
using namespace std;

bool uniqueString(string s) {
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "abcdbefghijklmnopqrstuvwxyz";
    cout << uniqueString(s) << endl;
    return 0;
}