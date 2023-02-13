#include<iostream>
using namespace std;

void generateBrackets(string output, int n, int countOfOpen, int countOfClose, int i) {
    //base case
    if(i == 2 * n) {//if we reach end of array
        cout << output << endl;
        return;
    }

    //recursive cases:
    if(countOfOpen < n) {
        generateBrackets(output + '(', n, countOfOpen + 1, countOfClose, i + 1);
    }

    if(countOfOpen > countOfClose) {
        generateBrackets(output + ')', n, countOfOpen, countOfClose + 1, i + 1);
    }
}

int main() {
    string output;//empty string is output
    int n;
    cin >> n;
    generateBrackets(output, n, 0,0,0);

    return 0;
}