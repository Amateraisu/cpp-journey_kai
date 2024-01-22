#include <bits/stdc++.h>
using namespace std;

std::vector<int> get(int n) {
    vector<int>ret;
    vector<int>nums(n + 1, 0);
    vector<int>v(n + 1, 1);
    for (int i = 2; i * i <= n; ++i) {
        if (v[i]) {
            for (int j = i * i; j <= n; j += i) {
                v[i] = 0;
            }

        }
    }
    for (int i = 2; i <= n; ++i) {
        if (v[i]) ret.push_back(i);
    }


    return ret;
}

int main() {
    int n;
    std::cin >> n;
    // find all prime numbers bet this range
    vector<int>primes = get(n);
}
