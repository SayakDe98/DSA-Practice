#include<bits/stdc++.h>
using namespace std;

void permute(string& s, int L, int R) {
        if(L == R) {//base case
            cout << s << endl;
        } else {
            for (size_t i = L; i <= R; i++)
            {
                /* code */
                swap(s[L], s[i]);//swapping

                permute(s, L + 1, R);//permutations made

                swap(s[L], s[i]);//backtracking
            }
            
        }
    
}

int main() {
    string s = "acb";

    permute(s, 0, s.length() - 1);

    return 0;
}