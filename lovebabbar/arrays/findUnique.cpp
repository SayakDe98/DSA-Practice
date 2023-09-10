// https: // www.codingninjas.com/studio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=0
//we just need to do XOR then similar elements get cut

#include <iostream>
using namespace std;
int findUnique(int *arr, int size)
{

    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int main() {
    int arr[7] = { 2, 3, 1, 6, 3, 6, 2 };
    cout << findUnique(arr, 7);
}