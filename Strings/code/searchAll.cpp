//Search all occurances of a word in a string
#include<bits/stdc++.h>

using namespace std;

vector <int> stringSearch(string big, string small){
    vector <int> result = {};

    int index;
    
    for(int i = 0; i < big.length(); i ++){
        index = big.find(small,i);
        if(index != -1){
            result.push_back(index);
            i = index;
        } else {
            break;
        }
    }

    return result;
}

int main(){
    string big, small;

    cout << "Enter the string from which we are going to find the small string:" << endl;
    getline(cin, big);

    cout << "Enter the string which we are going to search from the big string:" << endl;
    getline(cin, small);

    auto result = stringSearch(big, small);

    cout << "Answer:" << endl;

    for(auto a: result){
        cout << a << endl;
    }

    return 0;
}