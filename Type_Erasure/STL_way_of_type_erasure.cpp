#include <bits/stdc++.h>

class book {
public:
    book() {
        std::cout << "book is created!\n";
    }
    void call() const {
        std::cout <<"book is talking! what?!\n";
    }
};
// we want to be able to pass functors as arguments, so this is the "STL" way to do so.

class shelf {
public:
    std::vector<book>storage{};
    shelf() {
        std::cout <<"shelf is being created!\n";
    }
    template <typename someFunc>
    void forEachBook(someFunc f) {
        for (const book& b: storage) {
            f(b);
        }
    }
};

int main() {
    shelf s;
    s.forEachBook([](const book& b) {
        b.call();
    });

}
