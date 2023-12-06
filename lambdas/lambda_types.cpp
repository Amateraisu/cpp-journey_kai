#include <bits/stdc++.h>
using namespace std;
int main() {
    // able to pass since C++ 20
    auto x = [](){}; // an empty lambda;
    decltype(x) y;
    auto z = x;
    static_assert(std::is_same_v<decltype(x), decltype(y)>);
}
