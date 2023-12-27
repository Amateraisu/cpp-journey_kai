//
// Created by admin on 27/12/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int myInt = 1;
    int* ptr = &myInt;
    char* ptr2 = reinterpret_cast<char*>(ptr);
    if (*ptr2 == 1) {
        cout << "this is a little endian\n";
    } else {
        cout << "This is a big endian!\n";
    }
}
