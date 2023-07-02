// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

// Approach
// Here the Approach is literally same as the sum https://leetcode.com/problems/regular-expression-matching/ or a small improvisation of it here the '*' symbol can take any pattern that is the only difference between those two, below is the pictorical representation of the approach followed and the breifing of it is given below.

// pic1.png

// Here we can clearly see that the final DP table is completely dependent on its previous states i.ei.ei.e given by the expression as follows -
// dp[i][j] = dp[i-1][j] | dp[i][j-1] | dp[i-1][j-1] when p[j-1] is
// indicated by a '*' otherwise we go with dp[i-1][j-1] as the state transition.
// This would be the way in which we must proceed based and the prev state and the final answer would be dp[m][n] we always do a step down indexing for convineance purposes.

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        bool res[m + 1][n + 1];
        memset(res, false, sizeof(res));
        res[0][0] = true;
        for (int i = 1; i <= m; i++)
        {
            if (p[i - 1] == '*')
            {
                res[i][0] = res[i - 1][0];
            }
            for (int j = 1; j <= n; j++)
            {
                if (p[i - 1] == '*')
                {
                    res[i][j] = res[i - 1][j] || res[i][j - 1];
                }
                else if (p[i - 1] == s[j - 1] || '?' == p[i - 1])
                {
                    res[i][j] = res[i - 1][j - 1];
                }
            }
        }
        return res[m][n];
    }
};