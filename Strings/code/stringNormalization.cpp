// String Normalisation
// You are given a sentence with words separated by spaces.

// Your task is to:

// Write a function that returns a copy of this sentence where all the words:

// start with a capital letter

// the rest of the letters are lower case

// Note:

// Your function should not modify the sentence given as argument.

// Sample Input

// This is SO MUCH FUN!
// Sample Output

// This Is So Much Fun!

#include<bits/stdc++.h>
#include<string>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    
    copy[0] = toupper(copy[0]);
    for(size_t i = 1; copy[i] != '\0'; i++){
        if(copy[i - 1] == ' '){
            copy[i] = toupper(copy[i]);
        } else{
            copy[i] = tolower(copy[i]);
        }
    }

    return copy;
}

int main(){
    string sentence;

    cout << "Enter a sentence: " << endl;

    getline(cin, sentence);

    cout << normalize(sentence) << endl;

    return 0;
}