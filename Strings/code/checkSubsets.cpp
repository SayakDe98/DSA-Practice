//Given two non-empty strings, write a function that
//determines whether the second string is subsequent of
//first one.

//Sample Input:
//codingminutes
//cines

//Sample Output:
//Yes

//explanation: c,i,n,e,s are present in same order in codingminutes hence output is yes

//1. generate all possible subsets of first string then check if second string matches with one of those subsets
//it is inefficient solution because generating subsets is going to take (2^n) * n time after that matching will also take extra time
//it is an exponential solution.

//2. keep two pointers, start matching either from left or start matching from right
//we need to match all characters of first string with all characters of second string
//start from right:s matches for cines and coding minutes
//bring both i & j pointer to index - 1 
//e's match then decrement index by 1
//we find t in i pointer but value of j pointer doesn't match hence only decrement i pointer
//like this reach the end of both the strings by reaching i and j at 0th position
//T.C. : O(m + n)

#include<bits/stdc++.h>
#include<string>
using namespace std;

bool checkSubsets(string s1, string s2){
    bool ans;
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    while(i >= 0 && j >= 0){
        if(s2[j] == s1[i]){
            i --;
            j --;
        } else{
            i --;
        }
    }

    if(j == -1){
        ans = true;
    } else{
        ans = false;
    }
    
    return ans;
}

int main(){
    string s1, s2;

    cout << "Enter a string: " << endl;
    getline(cin,s1);

    cout << "Enter another string to check if it is a subset: " << endl;
    getline(cin,s2);

    bool result = checkSubsets(s1, s2);

    cout << result << " " << s2 << " is a subset of " << s1 << endl; 

    return 0;
}
