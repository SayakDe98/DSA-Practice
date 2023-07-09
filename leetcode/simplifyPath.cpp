Given a string path, which is an absolute path(starting with a slash '/') to a file or directory in a Unix - style file system, convert it to the simplified canonical path.

                                                                                                                                    In a Unix
                                                                                                                                    - style file system,
    a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes(i.e.'//') are treated as a single slash '/'.For this problem, any other format of periods such as '...' are treated as file / directory names.

                                                                                                                                                                                                                                                                              The canonical path should have the following format :

    The path starts with a single slash '/'.Any two directories are separated by a single slash '/'.The path does not end with a trailing '/'.The path only contains the directories on the path from the root directory to the target file
                                                                                                                                                                                                                  or directory(i.e., no period '.' or double period '..') Return the simplified canonical path.

                                                                                                                                                                                                                     Example 1 :

    Input : path = "/home/" Output : "/home" Explanation : Note that there is no trailing slash after the last directory name.Example 2 :

    Input : path = "/../" Output : "/" Explanation : Going one level up from the root directory is a no - op,
            as the root level is the highest level you can go.Example 3 :

    Input : path = "/home//foo/" Output : "/home/foo" Explanation : In the canonical path,
            multiple consecutive slashes are replaced by a single one.

                Constraints :

                1 <= path.length
                <= 3000 path consists of English letters,
            digits, period '.', slash '/' or '_'.path is a valid absolute Unix path.

#include<iostream>
#include<stack>
using namespace std;

class Solution
{
    public:
        string simplifyPath(string path)
        {
            stack<string> s;
            string res;
            for(int i = 0; i < path.length(); i++) {
                string temp;
                if(path[i] == '/')
                    continue;
                
                //add all the characters till we reach the end /
                while(i < path.length() and path[i] != '/') {
                    temp += path[i];
                    i++;
                }

                //ignore .
                if(temp == ".")
                    continue;
                else if(temp == "..") {
                    if(!s.empty()) {
                        s.pop();//remove top element if stack ain't empty and we have a ..
                    }
                }
                else 
                    s.push(temp);//push the directory file name to stack
            }
            //adding all stack elements to res
            while(!s.empty()) {
                res = "/" + s.top() + res;
                s.pop();
            }
            //if no directory present return /
            if(!res.length()) 
                return "/";
            return res;
         }
};

int main() {
    string path = "/../";
    Solution s;
    cout << s.simplifyPath(path) << endl;
    return 0;
}