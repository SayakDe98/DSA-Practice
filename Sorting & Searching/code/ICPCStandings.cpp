// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<pair<string,int>> teams;

//     vector<vector<int>> v;

    

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    int n = teams.size();
    int sum = 0;
    for(int  i = 0; i < n; i++){
        if(i != (teams[i].second - 1)) {
            sum += abs(teams[i].second - 1 - i);  
        }
    }
       return sum;
}

int main() {
    vector<pair<string,int>> teams={{"WinOrBooze", 1},  {"BallOfDuty", 2}, {"WhoKnows", 2}, {"BholeChature", 1}, {"DCECoders", 5}, {"StrangeCase", 7} ,{"WhoKnows", 7}};

    // vector<vector<int>> v;
    cout << badness(teams);
    

    return 0;
}