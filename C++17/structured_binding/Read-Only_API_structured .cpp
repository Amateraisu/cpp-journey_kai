#include <bits/stdc++.h>

class customer {
    std::string first;
    std::string last;
    long val;
public:
    customer(std::string f, std::string l, long v): first{std::move(f)}, last{std::move(l)}, val{v} {}
    std::string getFirst() const {
        return first;
    }
    std::string getLast() const {
        return last;
    }
    long getVal() const {
        return val;
    }
};

template<>
struct std::tuple_size<customer> {
    static constexpr int value = 3;
};

template<>
struct std::tuple_element<2, customer> {
    using type = long;
};


