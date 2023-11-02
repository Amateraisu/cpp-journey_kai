#include <bits/stdc++.h>

template<typename Derived>
struct Incrementable {
    Derived& operator ++ () {
        Derived& self = static_cast<Derived&>(*this);
        self.set(self.get() + 1);
        std::cout << "PREFIX CALLED\n";
        return *this;
    }

    Derived operator ++ (int) {
        auto& self = static_cast<Derived&>(*this);
        Derived tmp = self;
        self.set(self.get() + 1);
        std::cout << "POSTFIX CALLED\n";
        return tmp;
    }
};


struct Counter: public Incrementable<Counter> {
    int value;
    Counter():value(0) {}
    auto get() ->int {
        return value;
    }
    auto set(int val)->void {
        value = val;
    }
};

int main() {
    Counter c;
    c++;
    std::cout << c.get() << '\n';

    return 0;
}