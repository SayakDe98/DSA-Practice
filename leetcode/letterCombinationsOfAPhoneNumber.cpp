// Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.Return the answer in any order.

//                                                               A mapping of digits to
//                                                               letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.

//                                                               Example 1 :

//     Input : digits = "23" Output : [ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" ] Example 2 :

//     Input : digits = "" Output : [] Example 3 :

//     Input : digits = "2" Output : [ "a", "b", "c" ]

//                                   Constraints :

//                                   0 <= digits.length <= 4 digits[i] is a digit in the range['2', '9'].
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
        {
            return result;
        }

        string combination(digits.size(), ' ');

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(result, mapping, combination, digits, 0);
        return result;
    }

private:
    void backtrack(vector<string> &result, const vector<string> &mapping, string &combination, const string &digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(combination);
        }
        else
        {
            string letters = mapping[digits[index] - '0'];

            for (char letter : letters)
            {
                combination[index] = letter;
                backtrack(result, mapping, combination, digits, index + 1);
            }
        }
    }
};

int main()
{
    Solution s;
    auto res = s.letterCombinations("23");
    for (auto i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}