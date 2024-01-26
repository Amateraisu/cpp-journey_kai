#include <bits/stdc++.h>


template <typename T>
struct my_is_const;

template <typename T>
struct my_is_const {
    static constexpr bool value = false;
};

template <typename T>
struct my_is_const <const T>{
    static constexpr bool value = true;
};

int main() {
    const int x = 10;
    std::cout << std::is_const<decltype(x)>::value << '\n';
    std::cout << my_is_const<decltype(x)>::value << '\n';
}