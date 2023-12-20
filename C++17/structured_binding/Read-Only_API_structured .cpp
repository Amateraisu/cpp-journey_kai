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

template <std::size_t index>
struct std::tuple_element<index, customer> {
    using type = std::string;
};

template <std::size_t index>
auto get(const customer& c);

template<>
auto get<0>(const customer& c) {
    return c.getFirst();
}

template<>
auto get<1>(const customer& c) {
    return c.getLast();
}

template<>
auto get<2>(const customer& c) {
    return c.getVal();
}

template <std::size_t index>
auto get(const customer& c) {
    static_assert(index < 3);
    if constexpr (index == 2) {
        return c.getVal();
    }
    if constexpr (index == 1) {
        return c.getLast();
    }
    return c.getFirst();
}
// if u want write access, just return references.
