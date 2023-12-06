#include <iostream>

int main() {

    // this is a generic lambda
    auto x = []<typename T>(T val) {
        std::cout << val << '\n';
    };
    x(2);
}
