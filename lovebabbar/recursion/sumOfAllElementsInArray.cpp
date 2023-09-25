#include<iostream>
using namespace std;

int sumOfElements(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    if(size == 1) {
        return arr[0];
    }// can also add this case

    return arr[0] + sumOfElements(arr + 1, size - 1);
}

int main () {
    int arr[5] = {3,2,5,1,6};
    cout << "Sum: " << sumOfElements(arr, sizeof(arr) / sizeof(int)) << endl;
    return 0;
}