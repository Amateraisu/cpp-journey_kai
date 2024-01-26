#include <bits/stdc++.h>

template <typename T>
void foo(T&& x) {
    puts(__PRETTY_FUNCTION__);
}
int main() {
    std::any a = 5;
    int s = std::any_cast<int>(a);
    std::cout << s << '\n';

    std::any s2 = std::string{"Hello world!\n"};
    std::cout << std::any_cast<const std::string&>(s2);
    std::cout << "Next line\n";
    // modifying
    std::any_cast<std::string&>(s2) = "world\n";
    std::cout << std::any_cast<std::string&>(s2);

    if (auto p = std::any_cast<std::string>(&s2); p != nullptr) {
        std::cout << "If initialisations!\n";
    }  else {
        std::cout << "p is currely a nullptr\n";
    }
    if (a.has_value()) a.reset();
    a = 10;
    std::any b = 20;
    swap(a, b);
    std::cout << std::any_cast<int&>(b) << '\n';
    b.emplace<std::string>(std::string{"hello world!\n"});
    std::cout << std::any_cast<std::string&>(b);

}