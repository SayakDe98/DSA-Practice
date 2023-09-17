// 69. Sqrt(x)
//         Easy

//     7292

//     4297

//     Add to List

//     Share
//     Given a non
//     - negative integer x,
//     return the square root of x rounded down to the nearest integer.The returned integer should be non - negative as well.

//                                                                                                          You must not use any built
//                - in exponent function
//            or operator.

//               For example,
//     do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

//                                      Example 1 :

//     Input : x = 4 Output : 2 Explanation : The square root of 4 is 2,
//             so we return 2. Example 2 :

//     Input : x = 8 Output : 2 Explanation : The square root of 8 is 2.82842...,
//             and since we round it down to the nearest integer, 2 is returned.
#include<iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};

int main () {
    Solution s;
    cout << s.mySqrt(25) << endl;
    return 0;
}