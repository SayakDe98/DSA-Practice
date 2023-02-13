#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isRedundant(string str) {
    stack<char> s;
    for(auto ch: str) {
        if(ch != ')') {
            s.push(ch);//if we don't get ) we keep on pushing elements in stack
        } else {
            // we will only have one type of bracket which is '(' and ')'
            bool operator_found = false;

            while (!s.empty() and s.top() != '(')
            {
                char top = s.top();
                if(top == '+' or top == '-' or top == '*' or top == '/') {
                    operator_found = true;
                }
                s.pop();//keep poping things inside brackets
            }
            s.pop();//pops the opening bracket
            
            if(operator_found == false) {
                return true;//if we don't get operator then paranthesis is redundant
            }
        }
    }
        return false;//if we get operator then paranthesis is not redundant
}

int main() {
    // string s = "((a+b))";//redundant string
    string s = "(a+(b)/c)";//redundant string
    // string s = "(a+b*(c-d))";//non redundant string

    isRedundant(s) && cout << "Redundant Paranthesis" << endl;
    !isRedundant(s) && cout << "Non Redundant Paranthesis" << endl;
    return 0;
}