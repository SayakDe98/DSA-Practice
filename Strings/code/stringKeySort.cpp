//sort strings

//Given a list of 'n' strings S0,S1,S2,...,Sn-1, each consisting
//of digits and spaces, the number of spaces is the same for each entry, the goal is to implement a variation of a sort command.
//None of the strings contains consecutive spaces.
//Also, no string starts with a space nor ends with it.
//Spaces are used to divide string into columns, which can
//be used as keys in comparisions.

//The program has to support the required parameters:
//key: integer denoting the column used as a key in comparisions
//The left-most column is denoted by 1.
//reversed: boolean variable indicating whether to reverse
//the result of comparisions.

//comparision-type: either lexicographic or numeric.
//Lexicographic means that we use Lexicographical order
//where for example(122 < 13)

//Numeric means that we compare the strings by their numeric values,
//so(13 < 122). If the comparision type is 'numeric' and numeric values of keys of Si and Sj are equal 
//for i < j, then Si is considered strictly smaller than Sj because it comes first

// numeric comparision: 22 > 13
//lexicographic comparision: 130 < 22 
// in the input it will be given if we want lexicographic or numeric comparision
//we need to build a function which supports both lexicograph comparision as well as numeric comaprision

//Sample Input:
//---------------

//3 <- 3 strings
//92 022 <- string 1
//82 12 <- string 2
//77 13 <- string 3
//2 false numeric <- 2 is column number, false is because we don't need to reverse the string, numeric is type of comparision that we have to do.

//Sample Output:
// 82 12
// 77 13
// 92 022

//Explanation
//---------------
//The key for ordering is 2, reversal is false and ordering is numeric.
//Therefore, the keys 022, 12 and 13 should be ordered as 12, 13 and 022.
//Therefore, the final output is 82, 12, 77, 13 and 92 022.

//keys=022,12,13,12 smallest,13 bigger,022 bigget
//hence numeric comparision: s2, s3,s1
//12,13,022 and as we have reversal parameter as false so we aren't reversing the string
//if we had reversal parameter we would have s1,s3,s2

//First extract keys from every row/string
//take help of tokenisation
//store data in form of (string 1, key 1)
//so we will create pair to map key and value

//Secondly, do sorting:
//1)lexicographic
//2)numeric

//If reverse parameter is true then we will use the reverse function to reverse the string

//Implementation:
#include<bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key){
    //string tokeniser
    //hello how are you-> first call hello,second call how, third call are, fourth call you

    char *s = strtok((char *)str.c_str(), " ");

    while(key > 1){
        s = strtok(NULL," ");
        key --;
    }

    return (string)s;
}

int convertToInt(string s){
    int ans = 0;
    int p = 1;

    for(int i = s.length() - 1; i >= 0; i--){
        ans = ((s[i] = '0') * p);
        p = p * 10; 
    }

    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string,string> s2){
    string key1, key2;
    
    key1 = s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string,string> s2){
    string key1, key2;

    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}

int main(){
    int n;
    cin >> n;

    cin.get();// consume extra \n or enter

    string temp;
    vector <string> v;

    for(int i = 0; i < n; i ++){
        getline(cin, temp);// includes white spaces hences takes 2, false and numeric in single string because we want entire string(row) in one string
        v.push_back(temp);
    }

    int key;

    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    //below 2 lines can be used to extract 3rd string
    // string s = "20 30 40 50";
    // cout << extractStringAtKey(s,3) << endl;

    //1. to extract keys for comparision and store them
    vector<pair<string,string>> vp;//vector of pair of string,string
    //we are going to map each string mapped with its key inside this vector

    for (int i = 0; i < n; i++)
    {
        vp.push_back({v[i], extractStringAtKey(v[i],key)});//we are storing the key and value in the form of a pair hence we are using curly braces
    }

    //2. Sorting
    if(ordering == "numeric"){
        sort(vp.begin(), vp.end(), numericCompare);
    } else{
        sort(vp.begin(), vp.end(), lexicoCompare);
    }   

    //3.Reversal
    if(reversal == "true"){
        reverse(vp.begin(), vp.end());
    }

    //4.Output
    for(int i = 0; i < n; i ++){
        cout << vp[i].first << endl;
    }

    return 0;
}