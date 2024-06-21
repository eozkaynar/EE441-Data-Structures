// Welcome to Favtutor
//#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int main() {
    //char arr[46];

    // Input using the getline function.
    //cin.getline(arr, 100);
    string arr = "+ - 35 4.2";
    char separator = ' ';
    int i = 0;

    // Temporary string used to split the string.
    string s;
    while (arr[i] != '\0') {
        if (arr[i] != separator) {
            // Append the char to the temp string.
            s += arr[i];
        } else {
            cout << s << endl;
            s.clear();
        }
        i++;

    }

    // Output the last stored word.
    cout << s << endl;
}
