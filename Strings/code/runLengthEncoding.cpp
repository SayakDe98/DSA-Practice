// Run Length Encoding
// Write a function to perform basic string compression using the counts of repeated characters, also known as Run Length Encoding. Let see one example, the input string "aaaabcccccaaa" would become "a4b1c5a3". If the "compressed" string would not become smaller than the original string, your function should return the input string. You can assume the string has only uppercase and lowercase letters. You may use the to_string(int) method to convert an integer into string.

// Sample Inputs

// bbbaaaadexxxxxx
// abc
// Sample Outputs

// b3a4d1e1x6
// abc
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string compressString(const string &str){
    string s ;
    int count = 1;
    bool oneCountMoreThanOne = false;

    for (int i = 0; i < str[i] != '\0'; i++)
    {
        /* code */
        if(str[i + 1] == str[i]){
            count++ ;
            oneCountMoreThanOne = true;
        } else if(str[i + 1] != str[i] && count != 1){
            s += str[i] + to_string(count);
            count = 1;
        } else if(str[i + 1] != str[i] && count == 1 && !oneCountMoreThanOne){
            s += str[i];
        } else if(str[i + 1] != str[i] && count ==1 && oneCountMoreThanOne){
            s += str[i] + to_string(1);
        }
    }
    
    
    return s;
}

int main(){
    string s;

    cout << "Enter a string: " << endl;

    getline(cin, s);

    cout << compressString(s) << endl;

    return 0;
}