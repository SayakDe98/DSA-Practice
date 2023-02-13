// First Non-Repeating Character
// Given a stream of characters (lowercase alphabets), find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at each index. If for a current index there is no such character return '-1' for that particular index.

// Input Format:

// A String S of length N passed as a parameter to the given function.

// Output Format:

// Return a vector of characters of length N where V[i] character represents first non-repeating character from S[0] to S[i].

// Constraints:

// 1<=N<=100

// Expected time complexity:

// O(N) where N is the total number of input characters in one testcase. (Use the property of queue)



// Sample Testcase :

// Input:

// aabcbcd

// Output:

// a -1 b b c -1 d

// Explanation:

// At index 0, 'a' is the only character we have and hence non repeating.

// At index 1, we have 2 characters till now and they are same, hence no non-repeating character.

// At index 2, 'b' is the only non repeating character till now.

// At index 3, 'b' and 'c' are non repeating characters, but 'b' is the FIRST non repeating character till now.

// At index 4, 'c' is the only non repeating character till now.

// At index 5, there is no non repeating character till now.

// At index 6, 'd' is the only and first non repeating character.
#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<char> q;
    int freq[27] = { 0 };//a-z initialized to 0
    char ch;
    cin >> ch;

    while(ch != '.') {//. is used for termination
        //letter
        q.push(ch);//push letter inside the queue
        freq[ch - 'a']++;//increment the frequency of that particular letter

        //query =>  remove all characters from front of queue till we get character with frequency 1
        while(!q.empty()) {
            int index = q.front() - 'a';//to get the index of character at the front of the queue
            if(freq[index] > 1) {//not useful so pop since it is not at the front of queue since there is frequency greater than 1
                q.pop();
            } else {
                cout << q.front();
                break;
            }
        }
        if(q.empty()) {
            cout << "-1";//for empty queue we return -1
        }
        cin >> ch;
    }

    return 0;
}