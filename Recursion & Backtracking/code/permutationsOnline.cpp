#include<bits/stdc++.h>
using namespace std;

void permute(string s1, vector<string>& ans, int index) {
    //base case
    if(index >= s1.length()) {
        ans.push_back(s1);
        return;
    } 
    for(size_t j = index; j < s1.length(); j++) {
        //swap elements
        swap(s1[index], s1[j]); 
        
        //recursion below handles rest cases
        permute(s1, ans, index + 1); //index + 1 because it is comeplete for current index
        
        //backtracking to prevent changing of original string
        swap(s1[index], s1[j]);
        
    }
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    // string s1 = s;
    int index = 0;
    vector<string> ans;
    // permute(s1, ans, index);
    permute(s, ans, index);//remember there will be n! permutations for n characters of string
    set<string> se(begin(ans), end(ans));//to prevent redundancies, because we can't store same values twice
    ans.assign(se.begin(), se.end());
    return ans;
}

int main() {
    string s = "abc";

    vector<string> a = findSortedPermutations(s);
    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        cout << a[i] << endl;
    }
    
}