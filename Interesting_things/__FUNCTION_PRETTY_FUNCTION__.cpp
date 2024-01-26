#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
// variadic templates 
template <typename T>
const bool is_void_v = false;


// alias templates 
template<typename T> using myvec = std::vector<T>;


template <typename T>
void foo(T x) {
    puts(__PRETTY_FUNCTION__);
}

int main() {
    std::cout << __FUNCTION__ << '\n';
    return 0;
}