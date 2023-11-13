#include <iostream>
#include <bits/stdc++.h>

int main() {
//    auto f = [](int i) {
//        if (i == 0) return 1;
//
//        return i * f(i - 1); // 'f' declared with auto
//        // cannot appear in its own initialiser
//    };

    std::function<int(int)> f = [&](int i) {
        if (i == 0) return 1;
        return i * f(i - 1);
    };
    // since std::function is flexible, it will prevent compiler inline optimizations to prevent function call overheads
    // dynamically allocated memory for captured values
    //

    std::cout << f(5) << '\n';

    return 0;
}