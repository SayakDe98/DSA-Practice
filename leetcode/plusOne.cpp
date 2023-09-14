// 66. Plus One
//     Solved
//         Easy
//             Topics
//                 Companies
//                     You are given a large integer represented as an integer array digits,
//     where each digits[i] is the ith digit of the integer.The digits are ordered from most significant to least significant in left - to - right order.The large integer does not contain any leading 0's.

//                                                                                                                                           Increment the large integer by one and return the resulting array of digits.

//                                                                                                                                           Example 1 :

//     Input : digits = [ 1, 2, 3 ] Output : [ 1, 2, 4 ] Explanation : The array represents the integer 123. Incrementing by one gives 123 + 1 = 124. Thus,
//             the result should be[1, 2, 4].Example 2 :

//     Input : digits = [ 4, 3, 2, 1 ] Output : [ 4, 3, 2, 2 ] Explanation : The array represents the integer 4321. Incrementing by one gives 4321 + 1 = 4322. Thus,
//             the result should be[4, 3, 2, 2].Example 3 :

//     Input : digits = [9] Output : [ 1, 0 ] Explanation : The array represents the integer 9. Incrementing by one gives 9 + 1 = 10. Thus,
//             the result should be[1, 0].

//                 Constraints :

//                 1 <= digits.length <= 100 0 <= digits[i] <= 9 digits does not contain any leading 0's.
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size(); //store the digits vector's size which will be utilized later
        //Add 1 to the last element:
        digits[n - 1]++;
        // Handle carry
        for (int i = n - 1; i > 0; i--) {
            if (digits[i] > 9) {//Carry produced since digits[i] is greater than 9
                digits[i] -= 10; // Subtract 10 since digits[i] is 10, we get 0
                digits[i - 1]++;
            }
        }

        // Handle carry if carry exists in first digit
        if (digits[0] > 9) {//Carry produced in 0th position since value of 0th position is 10
            digits[0] -= 10;//Subtract 10 since digits[0] is 10, we get 0
            digits.insert(digits.begin(), 1); //Add first digit as 1
        }
        return digits;
    }
};

int main () {
    Solution s;
    vector<int> digits = {4, 3, 2, 1};
    vector<int> res = s.plusOne(digits);
    string temp;
    for (int i: res) {
        temp += to_string(i);
    }
    cout << temp;
    return 0;
}