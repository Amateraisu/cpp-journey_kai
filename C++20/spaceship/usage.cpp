#include <bits/stdc++.h>

struct typeA {
    int val1;
    int val2;
    std::strong_ordering operator <=> (const typeA& rhs) const { // or weak ordering or partial ordering
        return val1 <=> rhs.val1;
    }
    auto operator == (const typeA& rhs) const {
        return std::is_eq(*this <=> rhs);
    }
};

struct typeB {
    int val1;
    int val2;

};
// there is an implicit conversion to the weakest type
// if there is multiple cmp results it will not compile. for autos.
// multiple comparisons, will be weak_ordering
// for promotions implicitely involving float, it will be partial_ordering


int main() {
    typeA t1 = {1, 2};
    typeA t2 = {0, 1};
    std::cout << (int)(t1 == t2);
    std::cout << t1.val1;
}