#include<bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> input,int k){
    int i = 0;
    int j = 0;
    int max = INT_MIN;
    vector<int> ans;
    int n = input.size();
    int max_index;
    while(j <= n){
        if((j - i) < k){
            if(max < input[j]){
                max = input[j];
                max_index = j;
            }
            // cout << "i" << i << endl;
            // cout << "j" << j << endl;
            j++;
        }
        else if((j - i) == k){
            ans.push_back(max);
            cout << "inp j"<<input[j] <<"max"<< max << endl;
            i++;
            if(max_index < i){
                max = INT_MIN;
            }
            // cout << "i" << i << endl;
            // cout << "j" << j << endl;
        }
    }
        return ans;
}

int main(){
    int k;
    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 6};

    cout << "Enter the window length: " << endl;

    cin >> k;
    
    auto ans = maxInWindow(arr, k);

    for (size_t i = 0; i < ans.size(); i++)
    {
        /* code */
        cout << ans[i] << ", ";
    }
        

    return 0;
}