#include <bits/stdc++.h>

void func(std::byte* b) {
    std::byte data[1024];
    std::cout << data - b << '\n';
    func(b);
}

// or just use ulimit -s
// it is around 8MB of stack memory

int main() {
    std::byte b;
    func(&b);
}