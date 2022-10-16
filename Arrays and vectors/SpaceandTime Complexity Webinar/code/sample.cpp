#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
//ctime header file for clock

using namespace std;

int main()
{
    int n;

    cout << "Enter a number upto which we want to run a loop:" << endl;

    cin >> n;

    vector<int> arr(n,0);//initialized vector

    for(int i = 0 ; i < n ;i++)//iteration in reverse order
    {
        arr[i] = n - i;
    }

    //Sort the array
    auto start_time = clock();
    sort(arr.begin() , arr.end());
    auto end_time = clock();

    cout<<"For N elements, sorting time: "<<end_time - start_time<<endl;
}