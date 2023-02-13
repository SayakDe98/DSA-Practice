#include<bits/stdc++.h>
using namespace std;

// int lower_bound(vector<int> arr, int key) {
//     int s = 0;
//     int e = arr.size() - 1;
//     int ans = -1;//by default we have ans = -1 because by default we assume key and hence lower bound doesn't exist

//     while(s <= e) {//binarySearch on left subarray
//         int mid = (s + e) / 2;
//         if(arr[mid] == key) {
//             ans = mid;//ans stores index of mid but we won't return ans because there might be a lower bound in left subarray of current subarray as well
//             e = mid - 1;
//         } else if(arr[mid] > key) {
//             e = mid - 1;
//         } else {
//             s = mid + 1;
//         }
//     }
//     return ans;//lower bound index is stored in ans
// }

// int upper_bound(vector<int> arr, int key) {
//     int s = 0;
//     int e = arr.size() - 1;
//     int ans = -1;

//     while(s <= e) {
//         int mid = (s + e) / 2;

//         if(arr[mid] == key) {
//             ans = mid;
//             s = mid + 1;
//         } else if(arr[mid] > key) {
//             e = mid - 1;
//         } else {
//             s = mid + 1;
//         }
//     }
//     return ans;
// } 

int main() {
    vector<int> arr = {0, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 10};
    int n = arr.size();

    // cout << "lower bound: " << lower_bound(arr, 3) << ", upper bound: " << upper_bound(arr,3) << endl;
    
    // cout << "Frequency Count: " << upper_bound(arr,3) - lower_bound(arr, 3) + 1 << endl;

    //Using STL methods:
    cout << "Frequency Count using STL and we don't even need to write the functions for this: " << upper_bound(arr.begin(), arr.end(), 3) - lower_bound(arr.begin(), arr.end(), 3) << endl;//we are getting iterators for the upper_bound and lower_bound functions, for upper bound we get index = upper bound + 1 so we dont need to do + 1
    return 0;
}