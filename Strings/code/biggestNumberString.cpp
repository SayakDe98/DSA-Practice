#include<bits/stdc++.h>
#include<string>
using namespace  std;

string concatenate(vector<int> &numbers){
    vector<string> s;
    for(int i: numbers){
        s.push_back(to_string(i));//convert to string
    }

    sort(s.begin(), s.end(), [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });//sort lexicographically
    
    string res;

    for(auto z: s){
        res += z;//store sorted array in res string
    }

    while(res[0] == '0' && res.length() > 1){//if first character is 0 and there are characters greater than equal to 0
        // 1. vectorname.erase(position)
        // 2. vectorname.erase(startingposition, endingposition)
        res.erase(0, 1);
    }
    return res;
}

int main(){
    char ch[10000];

    vector <int> numbers;
    cout << "Enter the numbers :" << endl;

    cin.getline(ch, 1000);

    char *s = strtok(ch, ",");//string tokenisation

    while(s != NULL){
        numbers.push_back(atoi(s));

        s = strtok(NULL, ",");
    }
    
    cout << concatenate(numbers);

    return 0;
}