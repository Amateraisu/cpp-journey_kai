#include <bits/stdc++.h>

class myClass {
    template <typename T>
    constexpr auto operator () (T val) const {
        return val * val;
    }
};

int main() {
    auto c = [](int x) constexpr {
        return x;
    };
    constexpr auto d = [](int x) {
        return x;
    };

    // the below is the same as the class above
    // this means that the operator () can be invoked during compile time
    // but the functor a itself maynot be initialised during compile time. so its better to use constepxr infront
    auto a = [](int x) constexpr {
        return x * x;
    };

    constexpr auto aBetter = [](int x) constexpr {
        return x * x;
    };






}
