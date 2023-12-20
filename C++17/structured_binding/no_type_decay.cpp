// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

struct myStruct {
    int id;
    std::string val;
};

myStruct g() {
    return {42, "Kai"};
}

int main() {
    myStruct s = g();
    auto& [u, v] = s;
    s.id = 29;
    std::cout << "value of u is " << u << '\n';
    if (u > 30) {
        std::cout << v << '\n';
    }

    // Write C++ code here
    std::cout << "Hello world!";

    return 0;
}
