#include <bits/stdc++.h>
#include <string>
template <typename T>
std::string s(T arg) {
    if constexpr (std::is_same_v<T, std::string>) {
        return arg;
    } else if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(arg);
    } else {
        return std::string(arg);
    }
}
