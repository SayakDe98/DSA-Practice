#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &array, int s, int e){
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    vector<int> temp;

    while(i <= mid and j <= e){
        if(array[i] < array[j]){//if first half of sorted array has smaller value than second half
            temp.push_back(array[i]);
            i++;
        } else{//if first half of sorted array has bigger or equal value than second half
            temp.push_back(array[j]);
            j++;
        }
    }

    //copy remaining eles from 1st array
    while(i <= mid){
        temp.push_back(array[i++]);
    }
    //or copy remaining eles from 2nd array
    while(j <= e){
        temp.push_back(array[j++]);
    }

    //copy back elements from temp to original array
    int k = 0;
    for(int index = s; index <= e; index++){
        array[index] = temp[k++];
    }
    return;
}

//sorting method
void mergesort(vector<int> &array, int s, int e){
    //base case(find out smallestpossible array which won't require sorting)
    if(s >= e){
        return;//we return because we assume an array with no or 1 element means it is sorted
    }

    int mid = (s + e) / 2;//get mid position

    mergesort(array, s, mid);//merge sort for 1st half of array
    mergesort(array, mid + 1, e);//merge sort for 2nd half of array

    return merge(array, s, e);//we will merge the sorted array and return it to main function
}

int main(){
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;

    mergesort(arr, s, e);

    for(int x: arr){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}