// 58. Length of Last Word
//     Easy

//     4044

//     200

//     Add to List

//         Share
//             Given a string s consisting of words and spaces,
//     return the length of the last word in the string.

//                A word is a maximal substring consisting of non -
//                space characters only.

//                Example 1 :

//     Input : s = "Hello World" Output : 5 Explanation : The last word is "World" with length 5. Example 2 :

//     Input : s = "   fly me   to   the moon  " Output : 4 Explanation : The last word is "moon" with length 4. Example 3 :

//     Input : s = "luffy is still joyboy" Output : 6 Explanation : The last word is "joyboy" with length 6.

//                                                                  Constraints :

//                                                                  1 <= s.length <= 104 s consists of only English letters and
//                 spaces ' '.There will be at least one word in s.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string str)
        {
            string temp = "";
            vector<string> s1;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == ' ' && temp.length() < 1)
                {
                    continue;
                }
                if (str[i] != ' ')
                {
                    temp += str[i];
                }
                else
                {
                    s1.push_back(temp);
                    temp = "";
                }
            }
            if (temp.length() > 0)
            {
                s1.push_back(temp);
            }
            return s1[s1.size() - 1].length();
        }
};

int main () {
    Solution s;
    cout << s.lengthOfLastWord("   fly me   to   the moon  ");
    return 0;
}