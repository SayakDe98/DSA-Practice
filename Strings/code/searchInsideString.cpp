//to find the first occurance of a string use the find function of string
//to find the next occurance find the word but from index + 1

#include<string>
#include<iostream>

using namespace std;

int main(){
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);

    string word;
    cout << "Enter a string to find inside the above string:" << endl;
    getline(cin, word);
    int index = s.find(word);

    if(index != -1){
        cout << "The word's first occurance is :" << index << endl;
    } else if(index == -1){
        cout << "The word is absent" << endl;
    }

    //for finding the second occurance:
    int secondOccurance = s.find(word, index + 1);

    if(secondOccurance != -1){
        cout << "The word's second occurance is :" << secondOccurance << endl;
    } else{
        cout << "There is no second occurance of the word" << endl;
    }
    return 0;
}
