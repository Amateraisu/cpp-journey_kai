#include <bits/stdc++.h>




template <typename Iter, typename callable>
void forEach(Iter start, Iter end, callable C) {
    auto it = start;
    while (it != end) {
        C(*it);
        ++it;
    }
}

void call(int i) {
    std::cout << i << '\n';
}

int main() {
    std::vector<int> Primes = {2, 3, 5, 7, 11};
    forEach(Primes.begin(), Primes.end(), call);
}
