#include <bits/stdc++.h>
using namespace std;

int main() {
    void* mem = malloc(sizeof(int) * 10);
    int* ptr = new (mem) int(5);
    cout << *ptr << '\n';
    char* ptr2 = reinterpret_cast<char*>(ptr);
    if (*ptr2) {
        cout << "Little endian!\n";
    } else {
        cout << "big endian!\n";
    }
}
