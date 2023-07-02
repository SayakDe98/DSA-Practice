// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

//                                                                                                            Example 1 :

//     Input : haystack = "sadbutsad",
//             needle = "sad" Output : 0 Explanation : "sad" occurs at index 0 and 6. The first occurrence is at index 0, so we return 0. Example 2 :

//     Input : haystack = "leetcode",
//             needle = "leeto" Output : -1 Explanation : "leeto" did not occur in "leetcode", so we return -1.

//                                                                                                 Constraints :

//                                                                                                 1 <= haystack.length,
//             needle.length <= 104 haystack and needle consist of only lowercase English characters.
#include<iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(haystack == needle) {
            return 0;
        }
        string compare = "";
        for(int i = 0; i < haystack.size(); i++) {
            compare = haystack[i];

            if(compare == needle) {
                return i;
            }

            for(int j = i + 1; j < haystack.size(); j++) {
                compare += haystack[j];

                if(compare == needle) {
                    return i;
                }
            }
            compare = "";
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("sadsad", "sad") << endl;
    return 0;
}