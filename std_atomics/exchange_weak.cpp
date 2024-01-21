#include <bits/stdc++.h>
#include <atomic>
// even if the current value is the expected value, it can still fail to do the exchange

int main() {
    std::atomic<int>x{10};
    int expected = 10;

    bool can = x.compare_exchange_weak(expected, 20);
    if (can) {
        std::cout << "Yes it is successful\n";
    } else {
        std::cout << "Nope it is not successful\n";
    }

}
