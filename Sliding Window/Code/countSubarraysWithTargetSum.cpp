#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr, int k){
    unordered_map<int, int> prevSum;

    int curr_sum = 0;
    int subArrayCount = 0;

    for(size_t i = 0; i < arr.size(); i++){
        curr_sum += arr[i];

        if(curr_sum == k){
            subArrayCount++;
        }

        //if curr_sum exceeds sum k then find the number of subarrays having this sum and exclude those subarrays from curr_sum by increasing subArrayCount by same amount
        if(prevSum.find(curr_sum - k) != prevSum.end()){
            subArrayCount += (prevSum[curr_sum - k]);
        }

        //add curr_sum value to count of diff values of sum
        prevSum[curr_sum]++;
    }

    return subArrayCount;
}

int main(){
    vector<int> arr{10, 2, -2, -20, 10};
    int K = -10;

    cout << cntSubarrays(arr, K) << endl;

    return 0;
}