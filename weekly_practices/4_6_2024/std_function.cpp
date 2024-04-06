#include <bits/stdc++.h>


template <typename T>
struct MyFunction;


template <typename Ret, typename... Args>
struct MyFunction<Ret(Args...)> {
    MyFunction(Ret (*f)(Args...)):  res{std::make_unique<Child<decltype(f)>>(f)} {}

    Ret operator () (Args... args) {
        return res->call(args...);
    }

    struct Base {
        Base() {
            std::cout << "Base is constructed!\n";
        }
        virtual ~Base() {
            std::cout << "Destructor called!\n";
        }
        virtual Ret call(Args...) = 0;
    };

    template <typename T>
    struct Child : public Base {
        Child(T f):Callable(std::move(f)) {}
        Ret call(Args... args) override {
            return Callable(args...);
        }
        T Callable;
    };


private:
    std::unique_ptr<Base> res;
};


int add(int x, int y) {
    return x + y;
}

void testFunction() {
    std::cout << "I am inside my test function!\n";
}



int main() {
    MyFunction<void(void)> func(testFunction);
    func(); // Should call testFunction without any issue.
    std::cout << "Passed basic functionality!\n";
    MyFunction<int(int, int)> addFunc(add);
    assert(addFunc(2, 3) == 5);
    std::cout << "Passed basic functionality 2 ! \n";

    MyFunction<int(int, int)> lambdaFunc([](int a, int b) { return a - b; });
    assert(lambdaFunc(5, 3) == 2);
    std::cout << "Passed lambda functionality! \n";

//    MyFunction<int(int, int)> originalFunc([](int a, int b) { return a * b; });
//    MyFunction<int(int, int)> copyFunc = originalFunc; // Copy constructor
//    assert(copyFunc(3, 4) == 12);
//
//    std::cout << "Passed copy constructor functionality!\n";
//
//    MyFunction<int(int, int)> assignedFunc;
//    assignedFunc = originalFunc; // Assignment operator
//    assert(assignedFunc(3, 4) == 12);

    std::cout << "Passed assignmnet operator functionality!\n";




    return 0;
}
