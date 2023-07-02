// Given an array of strings strs, group the anagrams together.You can return the answer in any order.

//                                     An Anagram is a word or
//                                     phrase formed by rearranging the letters of a different word or phrase,
//     typically using all the original letters exactly once.

//     Example 1 :

//     Input : strs = [ "eat", "tea", "tan", "ate", "nat", "bat" ] Output : [ ["bat"], [ "nat", "tan" ], [ "ate", "eat", "tea" ] ] Example 2 :

//     Input : strs = [""] Output : [[""]] Example 3 :

//     Input : strs = ["a"] Output : [["a"]]

//                                   Constraints :

//                                   1 <= strs.length <= 104 0 <= strs[i].length <= 100 strs[i] consists of lowercase English letters.
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto m = s.groupAnagrams(strs);
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}