#include<bits/stdc++.h>
using namespace std;

// //brute force approach: O(n ^ 2)
// vector<int> stockSpan(vector<int> v) {
// //Write your code here. Do not modify the function or parameters.
//     vector<int> res = {1};

//     for(int i = 1; i < v.size(); i++) {
//         int count = 1;
//         for(int j = i - 1; j >= 0 and v[i] > v[j]; j--) {
//             count++;
//         }
//         res.push_back(count);
//     }
//     return res;
// }




// int main() {
//     vector<int> v = {100, 80, 60, 70, 60, 75, 85};

//     for(int i = 0; i < stockSpan(v).size(); i++) {
//         cout << stockSpan(v)[i] << ",";
//     }

//     return 0;
// }

vector<int> stockSpan(vector<int> prices, int n, int span[]) {
    stack<int> s;
    s.push(0);

    span[0] = 1;

    //loop for rest of the days:
    for(int i = 1; i <= n - 1; i++) {
        int currentPrice = prices[i];

        //topmost element that is higher than current prices
        while(!s.empty() and prices[s])
    }
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    int n = prices.size();
    int span[100000] = {0};

    stockSpan(prices, n, span);
    for(int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    return 0;
}