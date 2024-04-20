#include <bits/stdc++.h>

struct BigData {
    int array[100];
};


int main() {
    std::cout << "int is always lock free for basic types typically " << std::atomic<int>::is_always_lock_free << '\n'; // constexpr static member variable
    std::cout << "Check if it is lock free " << std::atomic<BigData>::is_always_lock_free << '\n';
    std::cout << ATOMIC_BOOL_LOCK_FREE << '\n' ; // a macro
}
