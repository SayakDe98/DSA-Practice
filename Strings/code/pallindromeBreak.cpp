// Palindrome Break
// Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

// Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

// Example-1

// Input: palindrome = "abccba"
// Output: "aaccba"
// Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".

// Of all the ways, "aaccba" is the lexicographically smallest.

// Example-2

// Input: palindrome = "a"
// Output: ""
// Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.

// Example-3

// Input: palindrome = "aa"
// Output: "ab"
// Example-4

// Input: palindrome = "aba"
// Output: "abb"

#include<bits/stdc++.h>
#include<string>
using namespace std;

string breakPallindrome(string& pallindrome){
    size_t len = pallindrome.size();
    
    if(len == 1){
        return "";
    }

    for (size_t i = 0; i < len / 2; i++)
    {
        /* code */
        if(pallindrome[i] > 'a'){
            pallindrome[i] = 'a';

            return pallindrome;
        }
    }

    pallindrome[len - 1] = 'b';

    return pallindrome;
}

int main(){
    string s;

    cout << "Enter a pallindrome string: " << endl;

    getline(cin, s);

    cout << breakPallindrome(s) << endl;

    return 0;
}
