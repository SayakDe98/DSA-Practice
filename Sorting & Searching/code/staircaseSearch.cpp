#include<bits/stdc++.h>
using namespace std;

pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
   int i = m - 1;
   int j = 0;

   while(j < n and i >= 0){
    if(v[i][j] == k){
        break;
    } else if(v[i][j] < k) {
        j++;
    } else {
        i--;
    }
   }
   pair<int,int> p ={i, j};

   return p;      
}

int main(){
    // vector<int> arr{};
    //alternatives:
    // vector<int>arr1 = {};
    // int arr[] = {};

    vector<vector<int>> arr;
    int M, N;
    cout << "Enter the number of rows: " << endl;
    cin >> M;
    cout << "Enter the number of columns: " << endl;
    cin >> N;

    //take the input for the 2d matrix:
    for (size_t i = 0; i < M; i++)
    {
        /* code */
        for (size_t j = 0; j < N; j++)
        {
            /* code */
            cin >> arr[i][j]; 
        }
    }
    
    int k;

    cout << "Enter a number to search: " << endl;
    cin >> k;
 
    auto s = search(M, N, arr, k);

    cout <<  s.first << "," << s.second << endl;  

    return 0;
}