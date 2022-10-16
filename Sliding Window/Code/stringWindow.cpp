#include<bits/stdc++.h>
using namespace std;

string find_window(string s1, string s2){
    int FP[256] = {0};//create a frequency map for pattern s2 and call it fp and there can be max 256 unqiue characters and initiazlied with 0
    int FS[256] = {0};//create a frequency map for string s1 and call it fp and there can be max 256 unqiue characters and initiazlied with 0
    int window[256] = {0};

    for(int i = 0; i < s2.length(); i++){
        FP[s2[i]]++;

    }

    //Sliding window algo
    int count = 0;
    int start = 0;//left contraction
    int start_idx = -1;//start window of best window
    int min_so_far = INT_MAX;
    int window_size;

    for(int i = 0; i < s1.length(); i++){
        //expand window by including current character
        char ch = s1[i];
        // FS[s1[i]]++;
        FS[ch]++;

        //count how many characters matched till now(string s1 and pattern s2)
        if(FP[ch] != 0 and FS[ch] <= FP[ch]){
            count += 1;
        }

        //if all characters of pattern are found in current window then start contracting
        if(count == s2.length()){
            //start contracting from left to remove unwanted characters(unwanted chracter is chracter which isn't present in pattern or its frequency is higher than req.)
            while(FP[s1[start]] == 0 or FS[s1[start]] > FP[s1[start]]){
                FP[s1[start]]--;
                start++;
            }

            window_size = i - start + 1;
            if(window_size < min_so_far){
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }
    if(start_idx == -1){
        return "No window found!";
    }

    return s1.substr(start_idx, min_so_far);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << find_window(s1, s2) << endl;

    return 0;
}