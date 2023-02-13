#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBalanced(string input) {
    stack<char> s;

    for(auto ch: input) {

        switch(ch) {
            case '(':
            case '{':
            case '[': s.push(ch);
                      break;
            
            case ')': if(!s.empty() and s.top() == '(') {
                        s.pop();
                        break;
                    } else 
                        return false;

            case '}': if(!s.empty() and s.top() == '{') {
                        s.pop();
                        break;
                    } else 
                        return false;
            case ']': if(!s.empty() and s.top() == '[') {
                        s.pop();
                        break;
                    } else
                        return false;
            default: continue;
        }
    }
    
    if(s.empty()) return true;
    return false;//if stack ain't empty
}

int main() {
    string s = "((a+b+c)+[d])";//Correct matching
    // string s = "({a+b+c)+[d])";//Incorrect matching

    isBalanced(s) && cout << "Paranthesis are matched properly" << endl;

    !isBalanced(s) && cout << "Paranthesis aren't matched properly" << endl;

    return 0;
}