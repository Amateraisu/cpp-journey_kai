#include "Alignment.h"
#include <bits/stdc++.h>
#pragma pack(1)

struct Kai {
    int x;
    double y;
};

struct Kai3 {
    double y;
    int x;
};

struct Kai2 {
    int x;
    int y;
};
int main() {


    std::cout << alignof(std::max_align_t) << '\n';
    std::cout << sizeof(Kai) << '\n';
    std::cout << sizeof(Kai2) << '\n';
    std::cout << sizeof(Kai3) << '\n';
    std::cout << "SIZE WITHOUT PADDING: " << sizeof(nKai) << '\n';

    return 0;
}