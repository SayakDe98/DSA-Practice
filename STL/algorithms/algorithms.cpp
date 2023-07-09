#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "Finding 5: " << binary_search(v.begin(), v.end(), 5) << endl;//for binary search elements must be sorted. 5 isn't present so we get 0(false)

    cout << "Finding 6: " << binary_search(v.begin(), v.end(), 6) << endl;

    vector<int>::iterator it(v.begin() + 2);
    cout << (*it) << endl;

    cout << "Lower bound: " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;//finds the position of 6 
    
    cout << "Upper bound: " << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;//upper and lower bounds return iterator

    // upper_bound() is a standard library function in C++ defined in the header . It returns an iterator pointing to the first element in the range [first, last] that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.
    // upper_bound() is a standard library function in C++ defined in the header . It returns an iterator pointing to the first element in the range [first, last] that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.
    int a = 3;
    int b = 5;
    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    swap(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    string s = "abcd";
    reverse(s.begin(), s.end());

    cout << s << endl;

    rotate(v.begin(), v.begin() + 1 ,v.end());//pass the starting of the rotation, the middle element, the end element. We are rotate by 1 element
    cout << "After rotation by 1 element: " << endl;
    for(int i: v) {
        cout << i << endl;
    }

    sort(v.begin(), v.end());//This sort is based on intro sort which is combination of quick sort, heap sort and insertion sort.
    cout << "After sorting the vector: " << endl;

    for(int i: v) {
        cout << i << endl;
    }

    return 0;
}