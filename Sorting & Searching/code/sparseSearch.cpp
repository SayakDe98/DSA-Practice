#include<bits/stdc++.h>
using namespace std;

int sparse_search(string a[], int n, string key){
    int s = 0;
    int e = n - 1;

    while(s <= e) {//regular binary search logic
        int mid = (s + e) / 2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;

        if(a[mid] == "") {
            //update our mid to point to a nearest non empty string
            while(1) {
                if(mid_left < s and mid_right > e) {
                    return -1;
                } else if(mid_right <= e and a[mid_right] != "") {
                    mid = mid_right;
                    break;
                } else if(mid_left >= s and a[mid_left] != "") {
                    mid = mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        } if(a[mid] == key) {
            return mid;//we got the key
        } else if(a[mid] > key) {
            cout << "a[mid] > key" << endl;
            e = mid - 1;//looking in the left part
        } else {
            cout << "a[mid] < key" << endl;
            s = mid + 1;//looking in right part
        }
    }
    return -1;
}

int main(){
    string arr[] = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", "e"};
    int n = sizeof(arr) / sizeof(string);
    string f;
    cin >> f;
    cout << "hi" << endl;
    cout << sparse_search(arr, n, f) << endl;

    return 0;
}