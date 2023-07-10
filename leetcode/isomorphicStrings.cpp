// Given two strings s and t, determine if they are isomorphic.

//                            Two strings s and t are isomorphic if the characters in s can be replaced to get t.

//                            All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character,
//     but a character may map to itself.

//     Example 1 :

//     Input : s = "egg",
//             t = "add" Output : true Example 2 :

//     Input : s = "foo",
//             t = "bar" Output : false Example 3 :

//     Input : s = "paper",
//             t = "title" Output : true

//                                  Constraints :

//                                  1 <= s.length <= 5 * 104 t.length ==
//                     s.length
//                         s and
//                 t consist of any valid ascii character.

//MY Solution:
// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         if (s.length() != t.length())
//         {
//             return false;
//         }

//         unordered_map<char, char> hmap;

//         for (int i = 0; i < t.length(); i++)
//         {
//             if (hmap[s[i]] and hmap[s[i]] != t[i])
//             {
//                 return false;
//             }
//             hmap[s[i]] = t[i];

//             for (auto &it : hmap)
//             {

//                 if (it.second == t[i] and it.first != s[i])
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

//Optimized copied solution:
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < t.length(); i++)
        {
            if (m1[s[i]] and m1[s[i]] != t[i])
                return false;
            if (m2[t[i]] and m2[t[i]] != s[i])
                return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("egg", "add") << endl;
    return 0;
}