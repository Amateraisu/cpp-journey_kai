#include <bits/stdc++.h>
#include <atomic>

int main() {
    std::atomic<int>x{10};
    int expected = 10;
    bool have = x.compare_exchange_strong(expected, 20);
    if (have) {
        std::cout << "yes it is expected\n";
    } else {
        // if it is not an expected, it sets x to the expected value;
        std::cout << "Nope it is not expected\n";
    }
}
