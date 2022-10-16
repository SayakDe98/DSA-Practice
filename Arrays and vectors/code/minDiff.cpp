// Minimum Difference
// Implement a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) who absolute difference is closest to zero, and returns a pair containing these two numbers, with the first number from array. Only one such pair will exist for the test.

// Input

// Array1 = [23, 5, 10, 17, 30]
// Array2 = [26, 134, 135, 14, 19]
// Output

// 17,19

#include<vector>
#include<algorithm>
#include<climits>
#include<bits/stdc++.h>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    int min_diff = INT_MAX;
    pair<int,int> values;

    for(int i = 0; i < a.size(); i ++) {
        for(int j = 0; j < b.size(); j ++) {
            if( abs(a[i] - b[j]) < min_diff ) {
                min_diff = abs(a[i] - b[j]);
                values = { a[i],b[j] };
            }
        }
    }
    return values;
}

int main() {
    vector <int> arr1{23, 5, 10, 17, 30};
    vector <int> arr2{26, 134, 135, 14, 19};

    auto result =  minDifference(arr1, arr2);
  
    return 0;
}