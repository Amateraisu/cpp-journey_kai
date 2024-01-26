#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
// variadic templates
template <typename T>
const bool is_void_v = false;


// alias templates
template<typename T> using myvec = std::vector<T>;




int main() {
    myvec<float> floats;
    static_assert(is_same_v<myvec<float>, std::vector<float>>);
    std::cout << "It is the same type!\n";
    return 0;
}

