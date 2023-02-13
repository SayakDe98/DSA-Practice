//lets take two pointers one for starting and another for ending index
//one edge case: if both pointers reach end of array we return -1, -1
//let the pointers be fast and slow which represents fast and slow moving pointers
//both are at index 0 at beginning
//now if we get element at fast lesser than element at slow
//we make a variable highest_till_now and assign arr[slow]. we also make another variable highest_till_now_index and assign slow
//slow += 1
//keep moving fast and keep noting the highest_till_now index and highest_till_now
//now we check if we reach end with only decerasing elements then we return [slow, arr.size() - 1]
//make another variable last_unsorted_index, where if we get an increasing element after we found unsorted elements then we note that index, now if we reach the last index then we return [slow, last_unsorted_index]
#include<bits/stdc++.h>
using namespace std;

pair<int,int> subarraySorting(vector<int> a) {
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    size_t slow = 0;
    size_t fast = 0;
    size_t highest_till_now, highest_till_now_index;
    bool unordered_array = false;
    pair<int,int> ans;
    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        cout << a[slow] << "," << a[fast] << endl;
        if(fast == a.size() - 1 and !unordered_array) {
            ans = {-1, -1};
            break;
        } else if(a[slow] > a[slow + 1] and !unordered_array) {
            cout << "Inside else if statement 1:" << a[slow]  << "," << a[fast] << endl;
            highest_till_now = a[slow];
            highest_till_now_index = slow;
            slow++;
            fast++;
            unordered_array = true;
        } else if(unordered_array and fast <= a.size() - 1) {
            cout << "Inside else if statement 2:" << a[slow] << "," << a[fast] << endl;
            fast++;
            ans = {slow, fast};
        } else if(!unordered_array and a[slow] < a[slow + 1] and slow <= a.size() - 1) {
            fast++;
            slow++;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};

    pair<int,int> ans = subarraySorting(a);

    cout << ans.first << "," << ans.second << endl;
    
    return 0;
}