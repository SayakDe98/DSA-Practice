// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

//Explanation:
//Brute force: we will use two loops and then also need to check if equal so O(n^3)
//Dynamic Programming:
//We will check if the first and the last elements are equal by putting one pointer at start(pointer i) other at end(pointer j).
//If yes, then check if elements from  position i + 1 to j - 1.
//We go diagonally and check if i+1 and j-1 is pallindrome
//always remember single character is palindrome.
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); //n x n size
        string ans;
        int maxLength = 0;
        for(int diff = 0; diff < n; diff++) {
            for(int i = 0, j = i + diff; j < n; i++, j++) {//diff between i and j is diff
                if(i == j) {//iterating in first diagonal
                    dp[i][j] = 1;//for very first diagonal is always 1 since single character length is 1
                } else if(diff == 1) {//second digonal
                    if(s[i] == s[j]) {//starting and end positions that is i and j elements are same then check if inner string is pallindrome or not
                        dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                    }
                } else {
                    if(s[i] == s[j] && dp[i + 1][j - 1]) {//for other diagonals if last and first elments same and inner diagonal is same
                        dp[i][j] = dp[i + 1][j - 1] + 2;//+2 because of first and last elements
                    }
                } 
                if(dp[i][j]) {
                    if(j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        ans = s.substr(i, maxLength);
                    } 
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("aabaa") << endl;
    return 0;
}