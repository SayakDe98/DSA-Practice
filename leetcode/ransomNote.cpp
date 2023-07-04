// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

//                                                   Each letter in magazine can only be used once in ransomNote.

//                                                   Example 1 :

//     Input : ransomNote = "a",
//             magazine = "b" Output : false Example 2 :

//     Input : ransomNote = "aa",
//             magazine = "ab" Output : false Example 3 :

//     Input : ransomNote = "aa",
//             magazine = "aab" Output : true

//                                       Constraints :

//                                       1 <= ransomNote.length,
//             magazine.length <= 105 ransomNote and magazine consist of lowercase English letters.
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;

        for(char c: magazine) {
            mp[c]++;
        }

        for(char c: ransomNote) {
            if(mp.find(c) == mp.end() || mp[c] <= 0) {
                return false;
            }
            mp[c]--;
        }
        return true;
    }
};

int main () {
    Solution s;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << s.canConstruct(ransomNote, magazine);
    return 0;
}