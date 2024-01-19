#include <bits/stdc++.h>
using namespace std;


struct p {
    float key;

//    auto operator <=> (const p& other) const = default;
    // this here will be partial ordering
    std::partial_ordering operator <=> (const p& other) const {
        if (other.key == other.key) return std::partial_ordering::equivalent;
        if (other.key < other.key) return std::partial_ordering::less;
        return std::partial_ordering::greater;
    }
};

struct p2 {
    double key;
};

int main() {
    p Kai{5};
    p Kai2{std::nanf("")};
    p2 Kai3{std::nan("")};
}
