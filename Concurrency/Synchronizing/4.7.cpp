#include <string>
#include <future>
#include <iostream>

struct X {
    void foo(int, std::string const&);

    std::string bar(std::string const&);
};


X x;
X baz(X&);



auto f1 = std::async(&X::foo, &x, 25, "Hello\n");
// the first arg is a callable.
auto f2 = std::async(&X::bar, x, "Hello world!\n"); // note that it is a copy here


struct Y {
    double operator()(double);
};

Y y;

auto f3 = std::async(Y(), 3.141); // move onstructed
auto f4 = std::async(std::ref(y), 3.5);
auto f5 = std::async(y, 3.9);
void some_function();
auto f6 = std::async(some_function);







void test(std::future<void>& f) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}
int main() {
    std::cout << "I am starting\n";
    test(f1);


}
