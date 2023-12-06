#include <bits/stdc++.h>

int main() {
    auto func = std::function<void(int)>{};
    func = [](int v) {
        std::cout << v <<
        '\n';
    };
    func(12);
    int x = 42;
    func = [x](int v) {
        std::cout << "another " << v + x << '\n';
    };
    func(10);


    return 0;
}
