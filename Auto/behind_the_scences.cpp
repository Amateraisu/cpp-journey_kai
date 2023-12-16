#include <bits/stdc++.h>

void func(const auto& param);
// can deduce constness
// cant deduce reference
int main() {

    int x = 1;
    int& y = x;
    y = 2;
    std::cout << x << '\n';
    func(y);

    return 0;
}
