//Input: arr[5] -> {1,2,7,8,5}
//output: {2,1,8,7,5}

//Input: arr -> {1,2,3,4,5,6}
//output: {2,1,4,3,6,5}
#include<vector>
#include<iostream>
using namespace std;

int main() {
    // vector<int> arr = {};
    // vector<int> arr = {1};
    // vector<int> arr = {1, 2};
    // vector<int> arr = {1,2,7,8,5};
    vector<int> arr = {1,2,3,4,5,6};

    // if(arr.size() > 1 && arr.size() % 2 == 0) {
    //     for(int i = 0; i < arr.size(); i += 2) {
    //         // if(i % 2 == 0) {//if using i++
    //             swap(arr[i], arr[i + 1]);
    //         // }
    //     }
    // }
    // else if (arr.size() > 1 && arr.size() % 2 != 0)
    // {
    //     for (int i = 0; i < arr.size() - 1; i += 2)
    //     {
    //         // if (i % 2 == 0)//if using i++
    //         // {
    //             swap(arr[i], arr[i + 1]);
    //         // }
    //     }
    // }
    for(int i = 0; i < arr.size(); i += 2) {
        if(i + 1 < arr.size()) {
            swap(arr[i], arr[i + 1]);
        }
    }
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    return 0;
}