#include<iostream>
using namespace std;

void sortArray(int *arr, int n) {
    if (n == 0 || n == 1) {
        return ;
    }

    // if (arr[n - 2] > arr[n-1]) {
    //     swap(arr[n-2], arr[n-1]);
    // }
    
    // return sortArray(arr, n - 1);
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i+1]);
        }
    }    
    sortArray(arr, n -1);
}

int main () {
    int arr[5] = {2,5,1,6,9};
    sortArray(arr, 5);
    for (int i: arr) {
        cout << i << " ";
    }
    return 0;
}