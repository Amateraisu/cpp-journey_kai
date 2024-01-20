#include <bits/stdc++.h>


int main() {
    int x = 1;
    int* ptr = &x;
    char* ptr2 = (reinterpret_cast<char*>(ptr));
    if (*ptr2) {
        std::cout << "Hello I am a little endian!\n";
    } else {
        std:: cout << "Hello I am a big endian\n";
    }
}
