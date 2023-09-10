// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

//                                                                        A subsequence of a string is a new string that is formed from the original string by deleting
//                                                                        some(can be none) of the characters without disturbing the relative positions of the remaining characters.(i.e., "ace" is a subsequence of "abcde" while "aec" is not )
//                                                                            .

//                                                                        Example 1 :

//     Input : s = "abc",
//             t = "ahbgdc" Output : true Example 2 :

//     Input : s = "axc",
//             t = "ahbgdc" Output : false

//                                   Constraints :

//                                   0 <= s.length
//                                   <= 100 0 <= t.length
//                                   <= 104 s and t consist only of lowercase English letters.

//                                      Follow up : Suppose there are lots of incoming s,
//             say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence.In this scenario, how would you change your code ?

// p1 and p2 are pointers used to traverse s and t strings, respectively.The while loop runs until we reach the end of either string 's' or 't'.Inside the loop, we check if the characters at p1 and p2 are the same.If they match, we move both pointers to the next character in their respective strings(p1++ and p2++).If they don 't match, we only move the pointer for string ' t' to the next character (p2++). After the loop ends, we check if we reached the end of string 's'(p1 == s.length()).If true, it means all characters in 's' were found in 't' in the same order, so we return true.If false, it means either some characters were not found or they were not in the same order, so we return false.The algorithm has a time complexity of O(m + n), where m is the length of string s and n is the length of string t.This is because in the worst case, we may need to iterate through both strings completely.The while loop runs until we reach the end of either string s or string t, resulting in a linear time complexity.The space complexity of the algorithm is O(1) since it only uses a constant amount of additional space to store the two pointers p1 and p2.Regardless of the input sizes, the space used by the algorithm remains constant, making it operate in constant space.
#include<iostream>
using namespace std;

class Solution{
    public:
    bool isSubsequence(string s, string t)
    {
        // if (s.empty())
        // {
        //     return true;
        // }
        // if (s.size() == t.size())
        // {
        //     for (int i = 0; i < s.size(); i++)
        //     {
        //         if (s[i] != t[i])
        //         {
        //             return false;
        //         }
        //     }
        //     return true;
        // }
        // for (int i = 0, j = 0; i < s.size() and j < t.size(); j++)
        // {
        //     if (s[i] == t[j])
        //     {
        //         i++;
        //     }
        //     if (i == s.size())
        //     {
        //         return true;
        //     }
        // }
        // return false;
        int p1 = 0, p2 = 0;
        while(p1 < s.length() and p2 < t.length()) {
            if(s[p1] == t[p2]) {
                p1++;
            }
            p2++;
        }
        return p1 == s.length();
    }
};

int main() {
    Solution S;
    string s = "abc", t = "ahbgdc";
    cout << S.isSubsequence(s, t) << endl;
    return 0;
}