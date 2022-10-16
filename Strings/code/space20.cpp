//Space20
//given a string, write a function to replace all spaces in a string with '%20'.
//It is given that the string has sufficient space at the end to hold the additional characters.

//Sample Input:
//hello world, how are you?

//Sample Output;
//hello%2020world,%20%20how%20are%20you?
#include<bits/stdc++.h>
#include<cstring>
#include<iostream>

using namespace std;

void replace_space(char *str){
    //1.calc spaces
    int spaces = 0;//initialize spaces with 0
    
    for(int i = 0; str[i] != '\0'; i ++){//iterate over the entire string
        if(str[i] == ' '){
            spaces += 1;//if we find a space we increment spaces by 1
        }
    }

    int idx = strlen(str) + 2 * spaces;//final index contains length of string and twice of spaces since we need %20 which will replace a space so we need 2 more characters to replace space with %20
    str[idx - 1] = '/0';//we need to terminate string with null character

    for(int i = strlen(str) - 1; i >= 0; i --){//we are traversing in reverse direction oer the string
        if(str[i] == ' '){//we encounter a space
            str[idx - 1] = '0';
            str[idx - 2] = '2';
            str[idx - 3] = '%';
            idx = idx - 3;//decremnting index by 3 since we used up 3 characters to concatenate %20
        } else{// if we didn't encounter a string
            str[idx - 1] = str[i];//concatenating character to index, idx - 1 because last index will be null terminated
            idx --;//decrementing index by 1 since we concatenated a character
        }
    }
}

int main(){
    char input[10000];//initializing the char array
    cin.getline(input,1000);//getting input upto 1000 characters
    replace_space(input);//executing the function to replace space with %20
    cout << input << endl;//displaying the transformed sentence/word
    return 0;
}