#include <bits/stdc++.h>


auto foo(int x, int y) -> int {
    return x + y;
}

template <typename T>
class customFunc;


template <typename Ret, typename ... args>
class customFunc<Ret(args...)> {
public:
    // the constructor should be taking in a function ptr
    customFunc(Ret (*f)(args...)):callable{std::make_unique<callableImple<decltype(f)>>(f)} { // now i have a constructor which takes in a function

    }
    Ret operator() (args... arguements) {
        return callable->call(arguements...);
    }

private:
    struct function_interface {
        function_interface() = default;
        virtual Ret call(args...) = 0;
        virtual ~function_interface() = default;
    };

    template <typename Callable>
    struct callableImple: public function_interface {
        callableImple(Callable callable_):callable1{std::move(callable_)} {}
        Ret call(args... arg) {
            return callable1(arg...);
        }
        Callable callable1;
    };

    std::unique_ptr<function_interface> callable;

};




int main() {
    // stateful vs non-stateful lambdas. but the thing is they cannot be assigned to each other for statefuls.
    // implementing callable, is what std::functions are
    std::function<int(int, int)>f = [](int x, int y) -> int {
        return x + y;
    };
    f = foo;
    int value = f(4, 10);
    std::cout << value << '\n'; // prints 14;

    customFunc<int(int, int)> f2{foo};
    int testVal = f2(4, 6);
    std::cout << testVal << '\n'; // should print out 10!
    assert(f2(4, 6) == f(4, 6));
    return 0; // now we actually need to do something with the callables.
}


