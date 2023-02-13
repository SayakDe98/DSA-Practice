#include<iostream>
#include<cstring>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI","JKL","MNO","PQRS","TUV", "WXYZ"};//for 0 and 1 we have empty string else have some alphabets attached to it

void printKeyPadOutput(string input , string output, int i = 0) {//int i =0 is used for initializing integer i with 0
    if(input[i]=='\0') {//we have reached end of string so we print the string now this is the base case
        cout << output << endl;//everytime we reach end of a combination we print it
        return;
    }

    //recursive case
    int current_digit = input[i] - '0';//extracting current digit and converting to integer
    if(current_digit == 0 or current_digit == 1) {// if current digit is 1 or 0 then skip the digit and make a recursive call
        printKeyPadOutput(input, output, i + 1);
    }

    //if we have something which is in the keypad we need iterate over the corresponding digits in keypad
    //we can interate over each letter and for each letter we can have function calls
    for(int k = 0; k < keypad[current_digit].size(); k++) {
        printKeyPadOutput(input, output + keypad[current_digit][k], i + 1);
    }
    
}

int main() {
    string input;
    cin >> input;

    string ouput;
    printKeyPadOutput(input, ouput);

    return 0;
}