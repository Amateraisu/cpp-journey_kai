#include <iostream>

struct dat {
    int x;
    int y;
};

struct moredat : public dat {
    int z;
};

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    moredat d{{1, 2}, 3};
    std::cout << d.z << '\n';

    return 0;
}
