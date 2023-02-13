#include<iostream>
#include<algorithm>
using namespace std;

bool canPlaceBirds(int B, int N, int* nests, int seperation) {
    int birds = 1;//initally there are 1 birds
    int location = nests[0];//last location

    for (size_t i = 1; i < N - 1; i++)
    {
        /* code */
        int current_location = nests[i];

        if(current_location - location >= seperation) {
            birds++;
            location = current_location;

            if(birds == B) {
                return true;
            }
        } 
    }
    return false;
    
}

int main() {
    int B = 3;
    int nests[] = {1, 2, 4, 8, 9};
    int N = sizeof(nests) / sizeof(int);
    //sorting(array might be unsorted)
    sort(nests, nests + N);

    //binary search
    int s = 0;
    int e = nests[N - 1] - nests[0];
    int ans = -1;
    while(s <= e) {//O(logn)
        int mid = (s + e) / 2;

        bool canPlace = canPlaceBirds(B, N, nests, mid);//O(n)

        if(canPlace) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}