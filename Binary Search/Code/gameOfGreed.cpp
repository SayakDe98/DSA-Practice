#include<iostream>
using namespace std;

bool divideAmongK(int arr[], int n, int k, int min_coins) {
    int partitions = 0;
    int current_friend = 0;

    for (size_t i = 0; i < n; i++)
    {
        /* code */
        if(current_friend + arr[i] >= min_coins) {
            partitions += 1;
            current_friend = 0; 
        } else {
            current_friend += arr[i];
        }
    }
    return partitions >= k;
}

int k_partition(int *arr, int n, int k) {
    //minimum is 0 and maximum is sum of all the elements of the array
    int start = 0;
    int end = 0;//end = sum of all elements initialized with 0
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        end += arr[i];
    }
    int ans;


    while(start <= end) {
        int mid = (start + end) / 2;
        bool isPossible = divideAmongK(arr, n, k, mid);

        if(isPossible) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int a[] = {12, 20, 33, 40};

    int n = sizeof(a) / sizeof(int);
    int k = 3;

    cout << k_partition(a, n, k) << endl;
    
    return 0;
}