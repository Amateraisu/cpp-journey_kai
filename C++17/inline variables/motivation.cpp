#include <iostream>


struct myClass {
    static int x;
};
int myClass::x{5}; // if this is included in a header file, error because multiple initialisation of static variable

// const is allowed
struct myClass2 {
    const static int x{5};
};

struct myClass3 {
    static int get() {
        static int x = 5; // please prefer to write static here for the value of x to persist instead of reinitialising it all the time
        return x;
    }
};

struct myClass4 {
    static int get() {
        int x = 5;
        return x;
    }
};
int main() {

    // Write C++ code here
    std::cout << "Hello world!";

    return 0;
}