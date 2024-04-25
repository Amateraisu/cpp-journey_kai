#include <cassert>
#include <functional>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

template <typename T>
struct my_std_function;

template <typename ...Args, typename Ret>
struct my_std_function<Ret(Args...)> {
    my_std_function(Ret(*f)(Args...)):ptr_(std::make_unique<child<decltype(f)>>(f)){}

    Ret operator() (Args... args) {
        return ptr_->call(args...);
    }
    struct Base {
        Base() = default;
        virtual ~Base() = default;
        virtual Ret call(Args...) = 0;
    };

    template <typename T>
    struct child : Base {
        child(Ret(*f)(Args... args)) {
            callable_ = std::move(f);
        }
        ~child() = default;
        Ret call(Args... args) override {
            return callable_(args...);
        }

        T callable_;
    };


    std::unique_ptr<Base>ptr_;
};



void testFunctionInvocation() {
    my_std_function<int(int)> f([](int x) { return x * x; });
    assert(f(5) == 25);
}

void testFunctionPointer() {
    int (*func)(int) = [](int x) -> int { return x + 1; };
    my_std_function<int(int)> f(func);
    assert(f(1) == 2);
}

void testFunctor() {
    struct Functor {
        int operator()(int x) { return x * 10; }
    };
    my_std_function<int(int)> f(Functor{});
    assert(f(3) == 30);
}

void testCopyConstructor() {
    my_std_function<int(int)> original([](int x) { return x * 2; });
    my_std_function<int(int)> copy = original;
    assert(original(10) == 20);
    assert(copy(10) == 20);
}

void testMoveConstructor() {
    my_std_function<int(int)> original([](int x) { return x * 3; });
    my_std_function<int(int)> moved(std::move(original));
    assert(moved(3) == 9);
    // Original should be in a valid but unspecified state
    // Depending on implementation details, you might want to assert specific behavior
}

void testAssignment() {
    my_std_function<int(int)> f;
    f = [](int x) { return x * 4; };
    assert(f(5) == 20);
}

void testExceptionSafety() {
    my_std_function<void()> f([]() { throw std::runtime_error("Expected exception"); });
    try {
        f();
        assert(false); // Should not reach here
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Expected exception");
    } catch (...) {
        assert(false); // Should catch the specific exception
    }
}

void testEmptyState() {
    my_std_function<void()> f;
    assert(!f); // Depending on how operator bool is implemented
}

int main() {
    testFunctionInvocation();
    testFunctionPointer();
    testFunctor();
    testCopyConstructor();
    testMoveConstructor();
    testAssignment();
    testExceptionSafety();
    testEmptyState();

    std::cout << "All tests passed." << std::endl;
    return 0;
}

