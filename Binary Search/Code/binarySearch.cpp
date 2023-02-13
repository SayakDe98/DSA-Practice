#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int n, int key) {
    int index = -1;

    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while(start <= mid and end >= mid) {
        if(arr[start] == key) {
            index = start;
            break;
        } else if(arr[end] == key) {
            index = end;
            break;
        } else if(arr[mid] == key) {
            index = mid;
            break;
        } else if(key < arr[mid]) {
            end = mid - 1;
            mid = (start + end) / 2;
        } else if(key > arr[mid]) {
            start = mid + 1;
            mid = (start + end) / 2;
        } 
    }
    return index; 
}

int main() {
    int arr[] = { 1, 2, 5, 8, 10, 17, 19, 29 };
    int n = sizeof(arr) / sizeof(int);
    int key;

    cout << "Enter a key: " << endl;
    cin >> key;
    
    cout << binarySearch(arr, n, key) << endl;
    
    return 0;
}