//Sorted SubSequences

//You are given a string, you need to print all subsequences
//of the string by length and lexicographic sorted 
//order if length is same.

//Sample Input: 
//abcd
//Sample Output: 
//,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd

//A subset/subsequence is different from substring
//In a subset/subsequence we can pick non conitnous part of the string 
//and can form a subset
//here ac is a subset, ad, bd,etc
//" " is also a subset
//0 length subset: " "
//1 length subset: a,b,c,d
//2 length subset: ab,ac,ad,bc,cd
//3 length subset: abc,abd,acd,bcd
//4 length subset: abcd

//method 1: recursion
//method 2: bit masking
//both have same complexity
// for a string of length n we have 2^n subsets
//because for each character we have 2 choices:
//either it will be a part of subset or it won't be a part of subset

//method 1: recursion:
//output:
//                    " "
//                   /    \
//                 a       " "
//                / \      /  \
//              ab   a     b  " "
//             / \   /\    /\   /\
//            abc ab ac a bc b  c " "

#include<bits/stdc++.h>
#include<string>
using namespace std;

void subsequence(string s, string o, vector<string> &v){
    //base case
    if(s.size() == 0){//when we reached leaf node
        v.push_back(o);//we are storing output in string o
        return;
    }
    //recursive case
    //abc -> substr(1) -> bc -> substr(1) -> c
    //" "
    //a " " (modified output)

    char ch = s[0];//we get 0th letter and then append this in output
    string reduced_input = s.substr(1);

    //includes the current letter
    subsequence(reduced_input, o + ch, v);//input is reduced_input, output is to be concatenated with current output we have formed so far.

    //excludes the current letter
    subsequence(reduced_input, o, v);//we are retaining the previous output

}

bool compare(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;//lexicographic comparision
    }

    return s1.length() < s2.length();//length based comparision
}

int main(){
    string s;

    cin >> s;

    vector<string> v;

    string output = "";

    subsequence(s, output, v);

    sort(v.begin(), v.end(), compare);

    for(auto s: v){
        cout << s << ",";
    }
    return 0;
}