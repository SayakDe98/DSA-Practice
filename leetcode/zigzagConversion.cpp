class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string ans;
        int charsInSection = 2 * (numRows - 1);
        int n = s.size();
        for(int currRow = 0; currRow < numRows; currRow++) {
            int index = currRow;

            while(index < n) {
                ans += s[index];

                if(currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = charsInBetween + index;

                    if(secondIndex < n) 
                        ans += s[secondIndex];
                }

                index += charsInSection;
            }
        }
        return ans;
    }
};