#include <bits/stdc++.h>


std::vector<int> get(int n) {
    std::set<int>s;
    while (n % 2 == 0) {
        s.insert(2);
        n/=2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            s.insert(i);
            n/= i;
        }
    }
    if (n > 2) {
        s.insert(n);
    }


    return std::vector<int>(s.begin(), s.end());
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int>primes = get(n);

}
