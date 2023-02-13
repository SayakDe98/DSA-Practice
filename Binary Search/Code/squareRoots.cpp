#include<iostream>
using namespace std;

float square_root(int N, int P) {
    int s = 0;
    int e = N;
    float ans = 0;

    //Binary search for integer part(search space 0 ...N)
    while (s <= e) {
        /* code */
        int mid = (s + e) / 2;
        if(mid * mid == N) {
            return mid;//if we get exact square we return the square root = mid
        } else if(mid * mid < N) {
            ans = mid;//mid may be a possible answer for integer part
            s = mid + 1;//we are only checking in the right part
        } else {
            e = mid - 1;//we won't be updating value because 4 ^ 2 > 10
        }
    }
    cout << "Integer part: " << ans << endl;

    //Linear Search for decimal part
    float inc = 0.1;
    for (size_t place = 1; place <= P; place++) {
        /* code */
        //linear search
        while(ans * ans <= N) {
            ans += inc;
        }

        //take one step back
        ans = ans - inc;//subtracting because we want ans * ans <= N, check video for better understanding
        inc = inc / 10.0;
    }
    
    return ans;
}

int main() {
    int n, p;
    cin >> n >> p;

    cout << square_root(n, p) << endl;

    return 0;
}