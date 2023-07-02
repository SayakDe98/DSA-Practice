// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.
// Example 2:

// Input : n = 4 Output : "1211" Explanation : countAndSay(1) = "1" countAndSay(2) = say "1" = one 1 = "11" countAndSay(3) = say "11" = two 1's = "21" countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
#include<iostream>
using namespace std;

class Solution {
    public:
        string solve(int n, string s) {
            if(n  == 0) return s;//if we reach base case we return "1"

            int count = 1;//we initialize count with 1 because prev has only 1 digit with count 1
            char prev = s[0];//we store value of first character in prev
            string temp = "";//we initialize temporary string with empty string

            for(int i = 1; i < s.size(); i++) {//we run a loop from i = 1 because i = 0 is prev value, we run loop till s's length
                if(prev == s[i]) count++;//if previous digit and current digit matches we increase count by 1

                else {
                    temp = (temp + (char)(count + '0')) + prev;//we are converting count to character and adding to prev
                    prev = s[i];//s[i] is stored in prev because now s[i] is prev
                    count = 1;//we change count back to 1 because same digit is repeated once
                }
            }
            temp = (temp + (char)(count + '0')) + prev; // we are converting count to character and adding to prev

            return solve(n - 1, temp);//performing recursion
        }

        string countAndSay(int n) {
            return solve(n - 1, "1");//for n = 1 countAndSay will give output 1
        }
};

int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}