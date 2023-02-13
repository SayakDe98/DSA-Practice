#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int s, int e) {
    vector<int> temp;
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int count = 0;

    while(i <= mid and j <= e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            count += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }

    return count;
}

int inversionCount(vector<int> &arr, int s, int e){
    //base case
    if(s >= e) {
        return 0;
    }

    //recursion case
    int mid = (s + e) / 2;
    int invLeftPart = inversionCount(arr, s, mid);
    int invRightPart = inversionCount(arr, mid + 1, e);
    int crossInv = merge(arr, s, e);

    return invLeftPart + invRightPart + crossInv;
}

int main() {
    // int arr[] = { 0, 5, 2, 3, 1 };
    vector<int> arr = { 0, 5, 2, 3, 1 };
    int s = 0;
    // int n = sizeof(arr) / sizeof(int);
    int n = arr.size() - 1;
    cout << inversionCount(arr, s, n) << endl;
    return 0;
}