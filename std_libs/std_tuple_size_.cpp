#include <tuple>
#include <bits/stdc++.h>

// Example usage of std::tuple_size
template <typename T>
void printTupleSize(const T& tuple) {
    constexpr std::size_t size = std::tuple_size<T>::value;
    std::cout << "Tuple size: " << size << std::endl;
}

int main() {
    std::tuple<int, double, char> myTuple;
    printTupleSize(myTuple);

    return 0;
}
