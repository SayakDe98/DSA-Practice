#include<iostream>
#include<deque>//doubly ended queue
#include<vector>
using namespace std;

void maxSubArrayK(vector<int> a, int k){
    //deque will store only useful elements 
    //for 1,2,3 we will first pop_front 1, since 1 < 2,
    //then we pop_front 2, since 2 < 3
    
    //now lets suppose a new scenario:
    //1,3,2

    //remove not useful elements
    //example: 1,2,3,0,8
    //let's suppose we reach window 3,0,8 
    //we see 8 > 0 and 8 > 3 so we pop elements from the back
    //we pop 0 first then 3

    //example: 1,2,13,0,8,9
    //let's suppose we reach 9 in that case 13 is greater than 0,8,9 but windown length is 3 so we have to remove 13 in that case as well

    //conclusion for removing element from window:
    //-> element is outside window
    //-> we get a larger element

    //Algorithm

    deque<int> Q(k);
    //1st step: Process only the first k elements in the array

    for (size_t i = 0; i < k; i++)
    {
        //instead of storing the elements lets store the indicies to check whether the element is outside the window or not
        if(!Q.empty() && a[i] > a[Q.back()]) {
            Q.pop_back();
        }

        Q.push_back(i);
    }
    
    //2nd step: Process the remaining elements of the array

    for (auto i = 0; i < a.size(); i++)
    {
        cout << a[Q.front()] << " ";
        //Remove element from left (contraction when an index lies outside the current window)
        while (!Q.empty() and Q.front() <= i - k)
        {
            Q.pop_front();
        }
        while (!Q.empty() && a[i] >= a[Q.back()])
        {
            Q.pop_front();
        }
        
        //always
        Q.push_back(i);
    }
    
}

int main(){
    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 5};
    int k = 3;

    maxSubArrayK(arr, k);

    return 0;
}