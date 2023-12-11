#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
private:
    void solve (string digits, int index, string mapping[], string output, vector<string>& ans) {
        // base case
        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        //process
        int digit = digits[index] - '0';// get digit by converting to int from char
        string value = mapping[digit]; // store the value of the digit in value

        //recursive relation
        for (int i = 0; i < value.size(); i++) { // run a loop to work out solution for every character present in value
            output.push_back(value[i]); // push the current character to the output string
            solve (digits, index + 1, mapping, output, ans); // run recursion to check for each element of next digit in digits string
            output.pop_back(); // remove the current character from the output string so that other cases can run properly
        }
    }
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }
        int index = 0;
        string output = "";
        string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        solve (digits, index, mapping, output, ans);
        return ans;
    }
};

int main () {
    Solution s;
    string digits = "23";
    vector<string> res = s.letterCombinations(digits);

    for (string i: res) {
        cout << "{" << i << "}" << endl;
    }
    return 0;
}