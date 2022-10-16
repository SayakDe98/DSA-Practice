#include<vector>
#include<iostream>

using namespace std;

int main(){
    char c[100] = {'1', 'a', 'b', 'z'};//character array for strings
    for(auto ch : c){
        cout << ch;
    }
    cout << endl;

    string s = "hello world";//directly assigning

    cout << s << endl;

    string s1("HELLO WORLD");//calling the string constructor

    cout << s1 << endl;

    string s2;

    getline(cin, s2);//user input

    cout << s2 << endl;

    string s3;

    getline(cin, s3);

    for(char x: s3){
        cout << x << ",";//printing each character in new line
    }

    cout << endl;
    vector<string> s4;
    string temp;

    int n = 5;
    while(n--){
        getline(cin, temp);
        s4.push_back(temp);
    }

    for(string y: s4){
        cout << y << ",";
    }

    return 0;
}
