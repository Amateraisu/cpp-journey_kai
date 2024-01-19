#include <bits/stdc++.h>


struct p {
    int key;
    std::strong_ordering operator <=> (p& other) {
        if (key < other.key) return std::strong_ordering::less;
        if (key > other.key) return std::strong_ordering::greater;

        return std::strong_ordering::equal;
    }

};

int main() {
    p Kai{5};
    p Kai2{10};
    if (Kai < Kai2) {
        std::cout << "Strong ordering works!\n";
    } else {
        std::cout << "wot is gg on\n";
    }
}