// #include<bits/stdc++.h>
// using namespace std;

// const int MAX_CHARS = 256;
 
//  //Algorithm : https://www.geeksforgeeks.org/smallest-window-contains-characters-string/#:~:text=Solution%3A%20Above%20problem%20states%20that,the%20characters%20is%20%E2%80%9Cabcbcd%E2%80%9D.
 
// // Function to find smallest window containing
// // all distinct characters
// string smallestWindow(string str)
// {
//     int n = str.length();
//     if(n==0){
//         return "";
//     }
 
//     // Count all distinct characters.
//     int dist_count = 0;
//     bool visited[MAX_CHARS] = { false };
    
//     for (int i = 0; i < n; i++) {
//         if (visited[str[i]] == false) {
//             visited[str[i]] = true;
//             dist_count++;
//         }
//     }
 
//     // We basically maintain a window of characters
//     // that contains all characters of given string.
//     int start = 0, start_index = -1, min_len = INT_MAX;
 
//     int count = 0;
//     int curr_count[MAX_CHARS] = { 0 };
//     for (int j = 0; j < n; j++) {
//         // Count occurrence of characters of string
//         curr_count[str[j]]++;
 
//         // If any distinct character matched,
//         // then increment count
//         if (curr_count[str[j]] == 1)
//             count++;
 
//         // if all the characters are matched
//         if (count == dist_count) {
//             // Try to minimize the window i.e., check if
//             // any character is occurring more no. of times
//             // than its occurrence in pattern, if yes
//             // then remove it from starting and also remove
//             // the useless characters.
//             while (curr_count[str[start]] > 1) {
//                 if (curr_count[str[start]] > 1)
//                     curr_count[str[start]]--;
//                 start++;
//             }
 
//             // Update window size
//             int len_window = j - start + 1;
//             if (min_len > len_window) {
//                 min_len = len_window;
//                 start_index = start;
//             }
//         }
//     }
 
//     // Return substring starting from start_index
//     // and length min_len
//     return str.substr(start_index, min_len);
// }

// int main(){
//     string s;

//     cin >> s;

//     cout << smallestWindow(s) << endl;

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;


string smallestWindow(string str){
    //Complete this method
    const int MAX_CHARS = 256;//there can be maximum 256 unique characters
    int n = str.length();

    int distinct_count = 0;//initialize a variable with 0 to store distinct characters
    int count = 0;
    bool visited[MAX_CHARS] = {false};//initializing all characters visited with false

    for (size_t i = 0; i < n; i++)//run a loop to count distinct characters
    {
        /* code */
        if(visited[str[i]] == false){
            visited[str[i]] = true;//if this is the first time we visited this character then we make visited true
            distinct_count++;
        }
    }

    int curr_count[MAX_CHARS] = {0};
    int start = 0, start_index = -1 , min_length_window = INT_MAX;

    for (size_t j = 0; j < n; j++)
    {
        /* code */

        if(curr_count[str[j]] == 1){
            count++;//if we get distinct character
        }
        
        if(distinct_count == count){//if we get all distinct cahracters
            while(curr_count[str[j]] > 1){
                if(curr_count[str[j]] > 1){
                    curr_count[str[j]]--;
                }
                start++;
            }

            int length_of_window = j - start + 1;

            if(min_length_window > length_of_window){
                min_length_window = length_of_window;
                start_index = start;
            }
        }
    }
        return str.substr(start, min_length_window);
}


int main(){
    string s;

    cout << "Enter a string: " << endl;
    
    cin >> s;

    cout << smallestWindow(s) << endl;    
    
    return 0;
}





























