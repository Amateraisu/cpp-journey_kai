#include <bits/stdc++.h>
using namespace std;

int main() {
    // big_ little endian
    int num = 1;
    int* ptr = &num;
    char* ptr2 = reinterpret_cast<char*>(ptr);
    if (*ptr2) {
        cout << "This machine is little endian!\n";
    } else {
        cout << "This machine is big endian!\n";
    }

    return 0;
}

