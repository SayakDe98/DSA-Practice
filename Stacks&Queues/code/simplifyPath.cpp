#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


string simplifyPath(string path){
    //1. Step - tokenisation and filtering
    istringstream iss(path);//input string stream

    vector<string> tokens;

    string token;

    while(getline(iss, token, '/')) {//filtered out . tokens and redundant forward slashes
        if(token == "." or token == "") {//avoided null tokens and single dots
            continue;
        }
        tokens.push_back(token);
    }

    //2. Handle ".."
    vector<string> stack;//use vector as a stack
    
    if(path[0] == '/') {
        //denotes our path is absolute path
        stack.push_back("");
    }

    for (string token: tokens)
    {
        if(token == "..") {
            //two cases: absolute path or relative path
            if(stack.size() == 0 or stack[stack.size() - 1] == "..") {
                stack.push_back("..");
            } else if(stack[stack.size() - 1] != "") {//only for absolute path
                stack.pop_back();
            }
        } else {
            stack.push_back(token);
        }
    }
    
    //combine all elements in stack to get the number
    if(stack.size() == 1 and stack[0] == "") {
        return "/";
    }

    //combine all elements in stack to get the answer
    ostringstream oss;
    int i = 0;
    for(auto token: stack) {
        if(i != 0) {
            oss << "/";
        }
        i++;
        oss << token;
    }

    return oss.str();
}

int main() {
    string path = "/../x/y/../z/././w/a///../../c/./";

    cout << simplifyPath(path) << endl;

    return 0;
}

//First find tokens: x,y,z,w,a,c
//Remove useless tokens