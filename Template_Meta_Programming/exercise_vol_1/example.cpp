#include <iostream>
#include <type_traits>

template <typename T>
struct MyTemplate {};

// Template specialization for MyTemplate<int>
template <>
struct MyTemplate<int> {};

int main() {
    // Check if MyTemplate<int> is the same type as MyTemplate<double>
    if (std::is_same_v<MyTemplate<int>, MyTemplate<double>>) {
        std::cout << "MyTemplate<int> and MyTemplate<double> are the same types.\n";
    } else {
        std::cout << "MyTemplate<int> and MyTemplate<double> are different types.\n";
    }

    // Check if MyTemplate<int> is the same type as MyTemplate<int>
    if (std::is_same_v<MyTemplate<int>, MyTemplate<int>>) {
        std::cout << "MyTemplate<int> and MyTemplate<int> are the same types.\n";
    } else {
        std::cout << "MyTemplate<int> and MyTemplate<int> are different types.\n";
    }

    return 0;
}
