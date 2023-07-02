// Implement pow(x, n), which calculates x raised to the power n(i.e., xn).

//                      Example 1 :

//     Input : x = 2.00000,
//             n = 10 Output : 1024.00000 Example 2 :

//     Input : x = 2.10000,
//             n = 3 Output : 9.26100 Example 3 :

//     Input : x = 2.00000,
//             n = -2 Output : 0.25000 Explanation : 2 - 2 = 1 / 22 = 1 / 4 = 0.25

//                                                                                Constraints :

//     -100.0 < x < 100.0 - 231 <=
//     n <= 231 - 1 n is an integer.Either x is not zero or n > 0. - 104 <= xn <= 104
#include<iostream>
#include<climits>
using namespace std;

class Solution {
    public:
        double power(double x, int n) {
            if(n == 0) {
                return 1;
            }

            return x * power(x, n - 1);
        }

        double myPow(double x, int n) {
            if(n == INT_MAX) {
                return (x == 1) ? 1 : (x == -1) ? -1 : 0;
            }
            if(n == INT_MIN) {
                return (x == 1 || x == -1) ? 1 : 0;
            }

            double num = 1;

            if(n >= 0) {
                num = power(x, n);
            } else {
                n = -n;
                num = power(x, n);
                num = 1.0 / num;
            }

            return num;
        }
};

int main () {
    Solution s;
    cout << s.myPow(3, 2) << endl;
    return 0;
}