#include<unordered_set>
#include<cmath>
#include<iostream>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> seen;
        while (n != 1) {
            int digitSum = 0;

            while (n > 0) {
                int digit = n % 10; // extracts digit
                digitSum += pow(digit, 2); // for squaring the digit and adding to sum
                n /= 10;
            }
            if (seen.count(digitSum)) {
                return false; // cycle detected
            }
            seen.insert(digitSum);
            n = digitSum; // assign the new digitSum to n
        }  
        return true; // happyNumber      
    }
};

int main () {
    Solution s;
    cout << (s.isHappy(19) == 1 ? "Happy Number" : "Not Happy Number");
    return 0;
}