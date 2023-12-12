#include <bits/stdc++.h>


int main() {
    std::any a = 5;
    std::vector<std::any>v{5, 3.5, "Hello world!"};
    std::cout << v.size() << '\n';
    std::cout << std::any_cast<int>(v[0]) << '\n';
    std::cout << v[2].type().name() << '\n';
//    std::cout << std::any_cast<float>(v[0]); // bad any cast
}
