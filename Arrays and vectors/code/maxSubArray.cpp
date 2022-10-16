// Maximum Subarray Sum
// Implement a function that takes an input a vector of integers, and prints the maximum subarray sum that can be formed. A subarray is defined as consecutive segment of the array. If all numbers are negative, then return 0.

// Input

// {-1,2,3,4,-2,6,-8,3}
// Output

// 13



// Hint

// Expected Time Complexity
// O(N)


// Space Complexity
// O(1)

// #include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr){
    int n = arr.size();
    
    int curr_sub_sum = 0;
    int max_sub_sum_till_now = 0;
    
    for(int i = 0; i < n; i ++) {
        curr_sub_sum += arr[i];
        
        max_sub_sum_till_now = max(curr_sub_sum, max_sub_sum_till_now);
        
        if(curr_sub_sum < 0) {
            curr_sub_sum = 0;
        }
    }
    
    return max_sub_sum_till_now;
}

int main() {
    // vector<int> arr{ -1, 2, 3, 4, -2, 6, -8, 3};
    vector<int> arr{ -1, 2, 3, 4, -2, 6, -8, 3};
    
    auto s = maxSubarraySum(arr);

    cout << s << endl;

    return 0;
}