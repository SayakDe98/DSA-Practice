#include<bits/stdc++.h>
using namespace std;
//We used DNF(dutch national flag) algo

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    cout << "hi" << endl;
    int low = 0, mid = 0, high = balls.size() - 1;
    while(mid <= high) {
        if(balls[mid] == 0) {
            swap(balls[low], balls[mid]);
            low += 1;
            mid += 1;
        } else if(balls[mid] == 1) {
            mid += 1;
        } else if(balls[mid] == 2) {
            swap(balls[mid], balls[high]);
            high -= 1;
        }
    }
    return balls;
}

int main() {
    vector<int> balls = {0, 0, 1, 2, 0, 1, 2, 0};
    auto s = sortBalls(balls);

    for (size_t i = 0; i < s.size(); i++)
    {
        /* code */
        cout << s[i] << ",";
    }
    
    return 0;
}