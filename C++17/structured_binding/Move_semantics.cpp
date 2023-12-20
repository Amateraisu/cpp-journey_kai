#include <bits/stdc++.h>
struct myStruct {
    int id;
    std::string val;
};

myStruct g() {
    return {42, "Kai"};
}

int main() {
    myStruct s = {42, "Kai"};
    // auto& [v, n] = std::move(s); // WILL NOT COMPILE!
    auto&& [v, n] = std::move(s); // OK
    std::cout << v << ' ' << s.id << '\n';
    std::cout << "Original before " << s.val << '\n';
    std::cout << "what about sthe string? " << s.val << '\n';
    std::string name = std::move(n);
    std::cout << "Name is " << name << " now the n is: " << n << '\n';
    std::cout << "How about the original now? " << s.val << '\n';

    return 0;
}
