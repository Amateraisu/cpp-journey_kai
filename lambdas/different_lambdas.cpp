#include <bits/stdc++.h>
using namespace std;
int main() {
    // able to pass since C++ 20
    auto x = [](){}; // an empty lambda;
    auto z = x;
    z = x; // error, cannot be assigned to each other
    static_assert(std::is_same_v<decltype(x), decltype(z)>);
    cout << "no errors!\n";
}
