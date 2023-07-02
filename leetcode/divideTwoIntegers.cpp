// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

//                                                                                                          The integer division should truncate toward zero,
//     which means losing its fractional part.For example, 8.345 would be truncated to 8, and-2.7335 would be truncated to - 2.

//                                                                                                                           Return the quotient after dividing dividend by divisor.

//                                                                                                                           Note : Assume we are dealing with an environment that could only store integers within the 32 -
//                                                                                            bit signed integer range : [−231, 231 − 1 ].For this problem,
//     if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than - 231, then return -231.

//                                                                                                                             Example 1 :

//     Input : dividend = 10,
//             divisor = 3 Output : 3 Explanation : 10 / 3 = 3.33333.. which is truncated to 3. Example 2 :

//     Input : dividend = 7,
//             divisor = -3 Output : -2 Explanation : 7 / -3 = -2.33333.. which is truncated to - 2.

//                                                                 Constraints :

//     -231 <= dividend,
//             divisor <= 231 - 1 divisor != 0

// Explanation:
// 	dividend = (quotient) * divisor + remainder
// We have to find the quotient in this equation and we are given divisor and dividend.
// Any number can be represented in binary form. Same goes for quotient :

// Let us have an example: 58/5:
// 58 = (11) * 5 + 3
// Representing the quotient in binary form: (11)10 = (1011)2:

// 	58 = (2^3 + 2^1 + 2^0) * 5 + 3                // --- (I)
// 	58 = [(2^3 * 5) + (2^1 * 5) + (2^0 * 5)] + 3  // --- (II)
// Since we dont know the quotient and remainder the equation we know is:
// 58 = (q) * 5 + rem

// We get a hint at what we would like to do here. We will first multiply 5 with maximum power of 2 such that the resulting number is still smaller than the dividend (read further if you don't understand why). Since multiplication operator is not allowed, we would use bitwise left shift to achieve this multiplication: each time we shift 5 by 1, we multiply it by 2:

// 	5 << 0 = 5               // less than dividend
// 	5 << 1 = 5*2 = 10        // less than dividend
// 	5 << 2 = 5*2*2 = 20      // less than dividend
// 	5 << 3 = 5*2*2*2 = 40    // less than dividend
// 	5 << 4 = 5*2*2*2*2 = 80  // (stop and consider the previous value as the result is greater than dividend
// We observe that:
// 58 = (2^3 * 5) + (something * 5) + rem // --- (III)
// You can see we are getting close to the equation we initialy wanted (eqa II).

// Since 5 is multiplied with 23, we add 23 to our answer.
// Further operating on equation III:

// 	58 - (2^3 * 5)  =  (something * 5) + rem
// 	58 - (8 * 5) = something * 5 + rem
// 	58 - 40 = something * 5 + rem
// 	18 = something * 5 + rem
// What we effectively have done is, subtracted the result we got from our first step from dividend (58 - 40).
// We arived at the same question again but with a smaller dividend this time.
// dividend = 18, divisor = 5

// Therefore let us repeat the process:

// 	5 << 0 = 5           // less than dividend
// 	5 << 1 = 5*2 = 10    // less than dividend
// 	5 << 2 = 5*2*2 = 20  // (stop and consider the previous value as the result is greater than dividend
// We add 21 to our answer.
// Looking back:

// 	18  =  (2^1 * 5) + (something * 5) + rem
// 	58 - (2^3 * 5) = (2^1 * 5) + (something * 5) + rem
// 	58 =  (2^3 * 5) + (2^1 * 5) + (something * 5) + rem
// You can notice we are gradually advancing towards equ II:
// Our new dividend is now:

// 	18 - (2^1 * 5)  =  (something * 5) + rem
// 	18 - (2 * 5) = something * 5 + rem
// 	18 - 10 = something * 5 + rem
// 	8 = something * 5 + rem
// dividend = 8, divisor = 5
// Repeating the process:

// 	5 << 0 = 5           // less than dividend
// 	5 << 1 = 5*2 = 10    // (stop and consider the previous value as the result is greater than dividend
// We add 20 to our answer.
// New dividend:

// 	8 = (2^0 * 5) + (something * 5) + rem
// 	8 - 5 = something * 5 + rem
// 	3 = something * 5 + rem
// dividend = 3, divisor = 5
// At this step, we stop iterating as our dividend is less than the divisor (we have also found our remainder = 3, as 5 should be multiplied with 0 and what remains is the remainder).

// Looking back again for the last time:

// 	3 = 0*5 + rem
// 	8 = (2^0 * 5) + 3
// 	18  =  (2^0 * 5) + (2^1 * 5) + 3
// 	58 = (2^3 * 5) + (2^1 * 5) + (2^0 * 5) + 3
// In the process, we have finally reached the equation we wanted to, and have got the answer as:
// quotient = (2^3 + 2^1 + 2^0)
#include<climits>
#include<iostream>
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
        {
            return 1;
        }
        bool isPositive = ((dividend < 0) == (divisor < 0)); // both dividend and divisor are of same sign, answer is positive

        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;

        while (a >= b)//dividend is greater than equal to divisor
        {
            short q = 0;

            while (a > (b << (q + 1)))
            {
                q++;
            }

            ans += (1 << q);//add 2 ^ q to ans;
            a -= (b << q);//reduce b ^ q from dividend
        }

        if (ans == (1 << 31) and isPositive)//if ans can't be stored in unsigned int
        {
            return INT_MAX;
        }

        return isPositive ? ans : -ans;
    }
};

int main() {
    Solution s;
    cout << s.divide(10,3) << endl;
    return 0;
}