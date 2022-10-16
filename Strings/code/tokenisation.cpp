//String tokenisation
//Tokenizing a string denotes splitting a string with respect to some delimeter(s).

//Input:
//"today is a sunny day"

//Output:
//"today","is","a","sunny",day

//Method 1: Using stringstream class
// #include<iostream>
// #include<sstream>
// #include<vector>
// using namespace std;

// int main(){
//     string input;

//     getline(cin, input);//taking string input

//     //create a stringstream object
//     stringstream ss(input);//ss is stringstream object

//     //stringstream acts as a buffer which helps us to read/write data
//     //let's use it to read data
//     string token;//we are going to use it to store our data
//     vector <string> tokens;//creating tokens vector to store string
//     while(getline(ss, token, ' ')){//' ' is delimeter, ss will read each word and put it inside the token string 
//         tokens.push_back(token);//stores all token inside tokens
//     }

//     //print all tokens
//     for(auto token: tokens){
//         cout << token << ",";
//     }

//     return 0;
// }

//Method 2: Using strtok(string token) function
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    char input[1000];
    cin.getline(input, 1000);

    //strtok()
    // cout << strtok(input," ") << ",";//tokenising when there are spaces, gives the first token always

    // //if we pass NULL as a parameter in subsequent calls we can get subsequent words isntead of only first word
    // cout << strtok(NULL, " ") << "," ;
    // cout << strtok(NULL, " ") << ",";
    // cout << strtok(NULL, " ");

    //if we use a while loop we can call strtok for the number of words that are present
    //the function knows how many words are there because it maintains the state of the string you passed in the last function call
    //we can store the state by using a static variable
    //like below:
    char *token = strtok(input, " ");

    while(token != NULL){
        cout << token << ",";// we are printing here to handle cases when string is null
        token = strtok(NULL, " ");
    }
    return 0;
}
