// 290. Word Pattern
//     Solved
//         Easy
//             Topics
//                 Companies
//                     Given a pattern and a string s,
//     find if s follows the same pattern.

//     Here follow means a full match,
//     such that there is a bijection between a letter in pattern and a non - empty word in s.

//                                                                            Example 1 :

//     Input : pattern = "abba",
//             s = "dog cat cat dog" Output : true Example 2 :

//     Input : pattern = "abba",
//             s = "dog cat cat fish" Output : false Example 3 :

//     Input : pattern = "aaaa",
//             s = "dog cat cat dog" Output : false

//                                            Constraints :

//                                            1 <= pattern.length <= 300 pattern contains only lower - case English letters.1 <=
//                                            s.length <= 3000 s contains only lowercase English letters and
//                     spaces ' '.s does not contain any leading or
//                 trailing spaces.All the words in s are separated by a single space.

// Bijection means only one charater is associated with one word i.e.one-to-one correspondence for applying this we use hashmaps.

// Approach
// We need to use two hashmaps- one for 'char to word' and another for 'word to char' mapping. While traversing in string s, we extract word from s and check whether that word is available in map, if it is then we check whether only one char is associated with it, if it is not then we return false. At last when we get full match we return true;

// Complexity
//     Time complexity : O(nlogn)

//                           Space complexity : O(n)

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool wordPattern(string p, string s) {
            unordered_map<char, string> p2s;
            unordered_map<string, char> s2p;

            int idx = 0, n = s.size();
            string temp = "";
            for(int i = 0; i <= n; i++) {
                if(s[i] == ' ' || i == n) {
                    if(idx < p.size() && (p2s.find(p[idx]) != p2s.end() || s2p.find(temp) != s2p.end())) {
                        if(p2s[p[idx]] != temp || s2p[temp] != p[idx]) {
                            return false;
                        }
                    } else {
                        p2s[p[idx]] = temp;
                        s2p[temp] = p[idx];
                    }
                    temp = "";
                    idx++;
                } else {
                    temp += s[i];
                }
            }
            return idx == p.size();
        }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog");
}