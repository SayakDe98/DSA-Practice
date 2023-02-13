#include<bits/stdc++.h>
using namespace std;

//o(nlogn) solution
pair<int,int> subarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    vector<int> b(a);//copies vector a into vector b
    
    sort(a.begin(), a.end());

    int n = a.size();
    int i = 0;

    while(i < n and a[i] == b[i]) {
            i++;
    }

    int j = a.size() - 1;

    while(j >= 0 and a[j] == b[j]) {
            j--;
    }
    
    if(i == a.size()) {
        return { -1, -1 };
    }
    return { i, j };
}

int main() {
    vector<int> a = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};

    pair<int,int> ans = subarraySorting(a);

    cout << ans.first << "," << ans.second << endl;
    
    return 0;
}