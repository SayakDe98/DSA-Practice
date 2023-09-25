#include<iostream>
// #include<vector>
using namespace std;
// vector<int> vec = {2,4,6,9,11,13};
// bool isSorted (int n) {
//     if (n == 0) {
//         return true;
//     }
//     if (vec[n] < vec[n - 1]) {
//         return false;
//     }
//     return isSorted(n - 1);
// }



// Alternative:
bool isSorted (int *arr, int size)
{
    // bool isSorted(int arr[], int size)
    // {
        // base case
        if (size == 0 || size == 1)
        {
            return true;
        }
        if (arr[0] > arr[1])
        {
            return false;
        }
        else
        {
            bool remainingPart = isSorted(arr + 1, size - 1);
            return remainingPart;
        }
    }

    int main()
    {
        // cout << (isSorted(vec.size()) == 1 ? "Sorted" : "Not Sorted");
        int arr[5] = {2, 4, 9, 9, 9};
        cout << (isSorted(arr, sizeof(arr) / sizeof(int)) == 1 ? "Sorted" : "Not Sorted");
        return 0;
    }