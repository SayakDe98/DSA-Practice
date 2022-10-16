//Get the smallest window for housing problem

//approach store the indices where we get subarray and find the differences and the one with lowest difference is the answer

#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

void housing(int *arr, int n, int k){
    int i = 0;
    int j = 0;
    int curr_sum = 0;
    int lowest_diff = INT_MAX;
    int low_i, low_j;

    while(j < n){
       curr_sum += arr[j];
       j++;

       if(curr_sum > k and i < j){
        curr_sum -= arr[i];
        i++;
       }

       if(curr_sum == k){
        cout << i << "-" << j - 1<< endl;
        if(lowest_diff > (j - i)){
            lowest_diff = j - i - 1;
            low_i = i;
            low_j = j - 1;
        }
       }
    }
    cout << "Smallest window: " << low_i << "-" << low_j << endl;
}

int main(){
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};

    int n = sizeof(plots) / sizeof(int);

    int k = 8;

    housing(plots, n, k);
    return 0;
}