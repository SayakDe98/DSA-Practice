#include<iostream>
using namespace std;

int linearSearch (int *arr, int size, int element) {
    if (size < 0) {
        return -1;
    }
    if (arr[size] == element) {
        return size;
    }
    return linearSearch(arr, size - 1, element);
}


int main () {
    int arr[5] = {2,3,1,0,4};
    cout << linearSearch(arr, sizeof(arr) / sizeof(int), 0);
    return 0;
}