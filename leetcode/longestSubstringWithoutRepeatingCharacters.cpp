// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

//Here we use two pointer . We have start and end pointers.
//We will use a set data structure here.
//If we don't have unique characters in the current set then we remove the last element and increment last by 1.
//Otherwise we keep moving forward. Also note the longest length till now.
#include<set>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;//We will be using set ds here

        int Max = 0;//maximum length of substring is 0 initally
        int start = 0;//starting index is 0 initally
        int end = 0;//end index is 0 intially

        while(start < s.size()) {//till we don't reach end of string we keep iterating
            auto it = Set.find(s[start]);//checks if starting element present in set

            if(it == Set.end()) {//if there are no duplicate elements then enter here
                if(start - end + 1 > Max) {
                    Max = start - end + 1;
                }
                Set.insert(s[start]);//insert current starting element in set
                start++;//increment starting index by 1 
            } else {
                Set.erase(s[end]);//delete the last element cause its duplicate
                end++;
            }
        }
        return Max;
    }
};


int main() {
    Solution s;
    cout << endl;
    cout << s.lengthOfLongestSubstring(" ");
    return 0;
}