#include <iostream>
#include <bits/stdc++.h>

int main() {
    // traditional  1
    auto f = [](auto&& self, int i) {
        if (i == 0) return 1;

        return i * self(self, i - 1);
    };

    // traditional 2
    std::function<int(int)> f20 = [&](int i) {
        if (i == 0) return 1;
        return i * f20(i - 1);
    };

    auto f23 = [](this auto&& self, int i) {
        if (i == 0) return 1;

        return i * self(i - 1);
    };



    return 0;
}
