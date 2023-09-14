// 242. Valid Anagram
//     Solved
//         Easy
//             Topics
//                 Companies
//                     Given two strings s and t,
//     return true if t is an anagram of s, and false otherwise.

//                                              An Anagram is a word or
//                                              phrase formed by rearranging the letters of a different word or phrase,
//     typically using all the original letters exactly once.

//     Example 1 :

//     Input : s = "anagram",
//             t = "nagaram" Output : true Example 2 :

//     Input : s = "rat",
//             t = "car" Output : false

//                                Constraints :

//                                1 <= s.length,
//             t.length <= 5 * 104 s and t consist of lowercase English letters.

//                             Follow up : What if the inputs contain Unicode characters
//     ? How would you adapt your solution to such a case
//     ?

// Intuition:
// The Intuition is to determine if two strings are anagrams, compare the characters in both strings and check if they have the same characters but in a different order. By tracking the count of each character, if the counts match for all characters, the strings are anagrams;
// otherwise, they are not .

//            Approach 1 : Sorting
//                             Explanation : sort(s.begin(), s.end());
// sorts the characters in string s in ascending order.This rearranges the characters in s so that they are in alphabetical order.sort(t.begin(), t.end());
// sorts the characters in string t in ascending order.Similarly, this rearranges the characters in t to be in alphabetical order.return s == t;
// compares the sorted strings s and t using the equality operator(==).If the sorted strings are equal, it means that the original strings s and t have the same characters in the same order, indicating that they are anagrams.In this case, the function returns true.Otherwise, if the sorted strings are not equal, the function returns false, indicating that the strings are not anagrams.This code takes advantage of the fact that anagrams have the same characters, but in different orders.By sorting the characters, the code transforms the problem into a comparison of the sorted strings, simplifying the anagram check.

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          However,
//     it's worth noting that this approach has a time complexity of O(n log n) due to the sorting operation, where n is the length of the strings.

// Approach 2: Hash Table
// Explanation:
// Create an unordered map count to store the character frequencies. The key of the map represents a character, and the value represents its frequency.
// Iterate over each character x in string s. For each character, increment its frequency in the count map by using the count[x]++ expression.
// Iterate over each character x in string t. For each character, decrement its frequency in the count map by using the count[x]-- expression.
// Iterate over each pair x in the count map. Each pair consists of a character and its corresponding frequency. Check if any frequency (x.second) is non-zero. If any frequency is non-zero, it means there is a character that appears more times in one string than the other, indicating that the strings are not anagrams. In that case, return false.
// If all frequencies in the count map are zero, it means the strings s and t have the same characters in the same frequencies, making them anagrams. In this case, the function returns true.
// This approach counts the frequency of characters in one string and then adjusts the count by decrementing for the other string. If the strings are anagrams, the frequency of each character will cancel out, resulting in a map with all zero frequencies.

// The time complexity of this solution is O(n), where n is the total number of characters in both strings. It iterates over each character once to count the frequencies and then compares the frequencies in the map, making it an efficient solution for the problem.

#include<algorithm>
#include<iostream>
#include<unordered_map>
    using namespace std;

    class Solution{
        public:
    bool isAnagram(string s, string t)
    {
        //Approach 1: Sorting. Sort both the strings and compare for equality.
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t ? true : false;

        //Approach 2: Using hashmap(unordered map) to store each char as key and frequency as value.
        //Incrementing the value of hashmap for first string and decrementing the same for the second string
        // unordered_map<char, int> count;

        // for (char c: s) {
        //     count[c]++;
        // }        
        // for (char c: t) {
        //     count[c]--;
        // }
        // for (pair c: count) {
        //     if (c.second != 0) {
        //         return false;
        //     }
        // }
        // return true;

        //Approach 3: Using hashmap array
        char count[26] = {0};
        for (char c: s) {
            count[c - 'a']++;
        }
        for (char c: t) {
            count[c - 'a']--;
        }

        for (int c: count) {
            if (c != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s, t);
    return 0;
}