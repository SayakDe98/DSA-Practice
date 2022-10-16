#include<bits/stdc++.h>
#include<string>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    string hours = to_string(minutes / 60);
    
    double diff = ((minutes / 60.00) - (minutes / 60)) * 60 ;

    cout << diff << endl;

    string mins;

    if(diff == 0){
        mins = "00";
    } else if(diff < 10){
        mins = "0" + to_string(int(diff));
    } else{
        mins = to_string(int(diff));
    }

    return hours + ":" + mins;
}

int main(){
    int mins;

    cout << "Enter time in minutes" << endl;

    cin >> mins;

    string time = convert_to_digital_time(mins);

    cout << time << endl;

    return 0;
}