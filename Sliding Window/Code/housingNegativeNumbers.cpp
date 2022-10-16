//Now we have included negative numbers in array as well.
#include<bits/stdc++.h>
using namespace std;

void housing(int *arr, int n, int k){
    int i = 0;
    int j = 0;
    int curr_sum = 0;

    for(int j = 0; j < n; j++){
        curr_sum += arr[j];
        //writing edge cases below:
        if(curr_sum < k and arr[j + 1] > 0){
            continue;
        }

        if(curr_sum < k and arr[j + 1] < 0 and arr[i] < 0){
            curr_sum -= arr[i];
            i++;
        }

        if(curr_sum < k and arr[j + 1] < 0 and arr[i] > 0){
            continue;
        }

        if(curr_sum > k and i < j and arr[i] > 0){
            curr_sum -= arr[i];
        }

        if(curr_sum > k and i < j and arr[i] < 0){
            continue;
        }

        if(curr_sum == k){
            cout << i << " - " << j << endl;
        }
    }

}

int main(){
    // int plots[] = {1, 3, -2, 1, 4, 1, 3, 2, 1, -1};
    // int plots[] = {-1, -2, 8};
    int plots[] = {-1, -2, 4, -3, 7, 0};
    int n = sizeof(plots) / sizeof(int);
    int k = 8;

    housing(plots, n, k);
    return 0;
}