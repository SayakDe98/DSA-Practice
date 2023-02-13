#include<iostream>
#include<vector>
using namespace std;

int rotated_search(vector<int> a, int key) {
    int n = a.size();

    //Logic:
    int s = 0;
    int e = a.size() - 1;
    while(s <= e) {
        int mid = (s + e) / 2;
        //case 1: when element is at mid:
        if(a[mid] == key) {
            return mid;
        }
        //the array is not properly sorted so we need below 2 cases:
        //case 2: when element at start is less than element at mid
        if(a[s] <= a[mid]) {
            //left part:
            if(key >= a[s] and key <= a[mid]) {
                e = mid - 1;
            } else {//right part:
                s = mid + 1;
            }
        } 
        //case 3: when element at start is more than element at mid
        else {
            //right part:
            if(key >= a[mid] and key <= a[e]) {
                s = mid + 1;
            } else {//left part:
                e = mid - 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a{4, 5, 6, 7, 0, 1, 2};
    
    int key;
    cin >> key;
    
    cout << rotated_search(a, key) << endl;

    return 0;
}