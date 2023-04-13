#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        double ans;
        for(int i = 0; i < nums1.size(); i++) {
            nums3.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            nums3.push_back(nums2[i]);
        }
        sort(nums3.begin(), nums3.end());
        int length = nums3.size();
        if(length % 2 == 1) {
            ans = nums3[(length - 1)  / 2];
        } else if(length  % 2 == 0) {
            int total = nums3[(length - 1)  / 2] + nums3[((length - 1)  / 2) + 1];
            ans = total / 2.0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a{ 1, 3 };
    vector<int> b{ 2, 4 };

    cout << s.findMedianSortedArrays(a, b);
    return 0;
}