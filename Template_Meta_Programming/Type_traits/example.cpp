#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct cust_type_trait {

};

template<>
struct cust_type_trait<char> {
    using val = int;
};

template <typename T>
auto accum(T const* begin, T const* end) {
    using t = typename cust_type_trait<T>::val;

    t total{0};
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}






int main() {
    // static_assert(iis_integral<int>::val == true);
    // static_assert(iis_integral<char>::val == true);
    char c[] = "ab";
    assert(accum(c, c + 2) == 195);

    return 0;
}
