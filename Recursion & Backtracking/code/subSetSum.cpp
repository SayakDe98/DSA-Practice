#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int targetSum) {
    //base case
    if(i == n) {//if we reached end of array
        if(targetSum == 0) {//if target sum is 0 for empty array
            return 1;
        }
        return 0;//if empty array and targetSum is not 0 then return no possible subsets possible
    }

    //recursive case
    int inc = countSubsets(arr, n, i + 1, targetSum - arr[i]);//includes current element
    int exc = countSubsets(arr, n, i + 1, targetSum);//excludes current element

    return inc + exc;
}

int main() {
    vector<int> arr{1,2,3,4,5};
    int X = 6;

    cout << countSubsets(arr, arr.size(), 0, X) << endl;
    return 0;
}