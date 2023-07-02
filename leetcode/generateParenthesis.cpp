// Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

//                                                                                       Example 1 :

//     Input : n = 3 Output : [ "((()))", "(()())", "(())()", "()(())", "()()()" ] Example 2 :

//     Input : n = 1 Output : ["()"]

//                            Constraints :

//                            1 <= n <= 8

// Intuition : The problem
//                 requires generating
//             all possible combinations of well -
//             formed parentheses of length 2n. To solve this, we can use a recursive approach.At each step, we have two choices : either add an opening parenthesis "(" or add a closing parenthesis ")".However, we need to make sure that the number of opening parentheses is always greater than or equal to the number of closing parentheses, so that the parentheses remain well - formed.

//                                                                                                                                                                                                                                                                                                                                                                                         Approach : We define a helper function,
//             generateParentheses,
//             that takes the following parameters :

//     result : a reference to the vector of strings where we store the generated combinations.current : the current combination being generated.open : the count of opening parentheses "(" included in the current combination.close : the count of closing parentheses ")" included in the current combination.n : the total number of pairs of parentheses to be included.In the generateParentheses function,
//             we first check if the length of the current string is equal to 2n. If it is,
//             we have generated a valid combination,
//             so we add it to the result vector and return.

//             If the length of current is not equal to 2n,
//             we have two choices :

//     If the count of opening parentheses open is less than n,
//     we can add an opening parenthesis to the current combination and make a recursive call to generateParentheses,
//     incrementing the open count by 1. If the count of closing parentheses close is less than the open count,
//     we can add a closing parenthesis to the current combination and make a recursive call to generateParentheses,
//     incrementing the close count by 1. In the generateParenthesis function,
//     we initialize an empty result vector and call the generateParentheses function with the initial values of current as an empty string,
//     open and close counts as 0,
//     and n as the input value.

//         Finally,
//     we return the result vector containing all the generated combinations of well - formed parentheses.

//                                                                                     Complexity : The time complexity of this solution is O(4 ^ n / sqrt(n)),
//     where n is the input number of pairs of parentheses.The space complexity of this solution is O(n).

#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    void genParenthesis(vector<string> & result, string current, int open, int close, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            genParenthesis (result, current + "(", open + 1, close, n);
        }

        if (close < open) {
            genParenthesis (result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector <string> result;

        genParenthesis (result, "", 0, 0, n);

        return result;
    }
};

int main () {
    Solution s;

    auto res = s.generateParenthesis(3);
    
    for (string ans: res) {
        cout << ans << ", ";
    }

    return 0;
}