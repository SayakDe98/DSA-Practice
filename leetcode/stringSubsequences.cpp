#include<vector>
#include<iostream>
using namespace std;

class Solution {
    private:
        void solve (string str, int index, string output, vector<string>& ans) {
            // base case
            if (index >= str.length()) {
                if (output.size() > 0) { // can also do output.length() > 0 or output != ""
                    ans.push_back(output);
                }
                return;
            }

            // exclude string subsequence
            solve (str, index + 1, output, ans);

            // include string subsequence
            char element = str[index];
            output.push_back(element);
            solve(str, index + 1, output, ans);
        }

    public:
        vector<string> subsequences (string str) {
            vector<string> ans;
            string output = "";
            int index = 0;
            solve (str, index, output, ans);
            return ans;
        }
};

int main () {
    Solution s;
    vector<string> res = s.subsequences("abc"); 
    for (string i: res) {
        cout << "{" << i << "}" << endl;
    }
    return 0;
}