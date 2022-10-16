//a ^ N 
//5 ^ 3 = 5 * 5 * 5 = 125
//3 ^ 5 = 3 * 3 * 3 * 3 * 3 = 243

//IF we multiply it takes O(n) tc
//we want to do in log(n)

//a ^ N = 3 ^ 5 = 3 ^ 101(that is 5's binary representation = 101)
//any number n will have atmost N bits
//if n = 15, 15 has 4 bits, log(15 + 1) base 2 = 4
//n = 8, 8 has 3 bits
//when we go one digit to the left we square the previous power
//101 where a ^ 1 = 1, a ^ 2 = 0, a ^ 3 = 1, hence (a ^ 4).(a ^ 1) = a ^ 5 , here a = 3 hence 3 ^ 5 = 243

//initially assume ans = 1
//then find out the LSB we get here  = 1, hence  mulitply ans with a
//then find the next bit to left we get 0 then dont need to multiply 
//then we have msb we see value = 1, so multiply with a ^ 4
//ans = a ^ 5
//as there can be only log n bits hence we can find the answer in logn time

#include<iostream>
using namespace std;

int fastExpo(int a, int n){
    int ans = 1;

    while(n > 0){
        int last_bit = (n & 1);
        if(last_bit){//if last bit is 1
            ans = ans * a;
        }
        a = a * a;//since we are moving to the left hence we multiplying a with a means we are squaring power of a
        n = n >> 1;//we are doing right shift.
    }

    return ans;
}

int main(){
    int a, n;
    cin >> a >> n;

    cout << fastExpo(a, n) << endl;

    return 0;
}