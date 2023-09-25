#include<iostream>
using namespace std;

int binarySearch (int arr[], int low, int mid, int high, int key) {
    //base cases:
    if (low > high)
    {
        return -1;
    }
    if (key > arr[high] || key < arr[low]) {
        return -1;
    }
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[low] == key) {
        return low;
    }
    if (arr[high] == key) {
        return high;
    }
  
    if (key < arr[mid]) {
        high = mid - 1;
    }
    if (key > arr[mid]) {
        low = mid + 1;
    }
    return binarySearch(arr, low, mid, high, key);
}

int main () {
    int arr[5] = { 1, 4, 7, 10 , 16}; // sorted array for Binary Search
    int key = 10;
    int n = sizeof(arr) / sizeof(int);
    cout << binarySearch(arr, 0, n / 2, n - 1, key);
    return 0;
}
//Better approach
// int binarySearch(vector<int> nums, int start, int end, int key)
// {
//     if (start > end)
//     {
//         return -1;
//     }
//     if (key < nums[start] or key > nums[end])
//     {
//         return -1;
//     }

//     int mid = start + (end - start) / 2;
//     if (nums[mid] == key)
//     {
//         return mid;
//     }

//     if (key > nums[mid])
//     {
//         return binarySearch(nums, mid + 1, end, key);
//     }
//     else
//     {
//         return binarySearch(nums, start, mid - 1, key);
//     }
// }

// int search(vector<int> &nums, int target)
// {
//     // Write your code here.
//     return binarySearch(nums, 0, nums.size() - 1, target);
// }