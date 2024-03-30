#include <iostream>
#include <coroutine>

CoroTask coro(const int& max) {
    std::cout << "CORO " << max << " started!\n";
    for (int i = 0; i < max; ++i) {
        std::cout << "CORO " << i << "/" << max << '\n';
        std::suspend_always; // suspend
    }
}

// [[nodiscard]]

int main() {
    auto coroTask = coro(3);
    std::cout << "coro(3) started\n"; // OOPS, is the value of max still valid?
    // if it is a container, use std::views::all(vector name) as the parameter
    // else can use std::cref or std::ref.
    while (coroTask.resume()) {
        std::cout << "coro() suspended\n";
    }
    std::cout << "Coro() done\n";
}