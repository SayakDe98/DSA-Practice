#include<iostream>
using namespace std;

void housing(int *arr, int n, int k){
    int i = 0;
    int j = 0;
    int curr_sum = 0;

    while(j < n){
        //expand to right
        curr_sum += arr[j];
        j++;

        //remove elements from the left till curr_sum > k and i < j
        while(curr_sum > k and i < j){
            curr_sum = curr_sum - arr[i];
            i++;
        }

        //check if any given point
        if(curr_sum == k){
            //print that window
            cout << i << " - " << j - 1 << endl;
        }
    }
}

int main(){
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(int);
    int k = 8;

    housing(plots, n, k);
    return 0;
}