#include <bits/stdc++.h>
class base {
public:
    base() {
        std::cout << "BASE is created\n";
    }
    virtual ~base() {
        std::cout << "BASE class destructed\n";
    }

};

class d1 : public base {
public:
    d1() {
        std::cout << "d1 is created!\n";
    }
};

class d2: public base {
public:
    d2() {
        std::cout << "d2 is created!\n";
    }
};

//tldr it is a method to find the correct downcast for a ptr at runtime

int main() {
    d1 child;
    base* ptr = &child;
    ptr = dynamic_cast<d1*>(ptr);
    if (ptr == nullptr) {
        std::cout <<"incorrect cast!\n";
    } else {
        std::cout <<"it is the correct cast!\n";
    }
    return 0;
}
