#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2) {
    //Sort any one array only a1 or a2:
    sort(a2.begin(), a2.end());

    int p1, p2;
    int diff = INT_MAX;

    //Iterate over one array and look for closest elements in the second array
    for (size_t x: a1)
    {
        /* code */
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();//this fucntion returns an iterator and if we subtract the base index a2.begin() gives you the index.lb is index
        //example: lb of 30 is 30 and lb of 31 is 35 since 30 >= 30 and 35 >= 31
        
        //left
        if(lb >= 1 and x - a2[lb - 1] < diff) {
            diff = x - a2[lb - 1];
            p2 = x;
            p1 = a2[lb - 1];
        }
        //greater / right
        if(lb != a2.size() and a2[lb] - x < diff) { //a2[lb] must be bigger than x
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }
    }
    cout << "Min Pair " << p1 << " and " << p2 << endl;
    return;
}

int main() {

    vector<int> a1 = { -1, 5, 10, 20, 3};
    vector<int> a2{ 26, 134, 135, 15, 17};

    min_pair(a1, a2);
    return 0;
}