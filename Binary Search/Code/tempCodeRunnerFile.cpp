int upper_bound(vector<int> arr, int key) {
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