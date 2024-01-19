#include <bits/stdc++.h>


template <typename T>
struct custom_function;

template <typename Ret, typename ... Args>
struct custom_function<Ret(Args...)> {
    custom_function(Ret (*f)(Args...)):ptr{std::make_unique<actual_callable<decltype(f)>>(f)} {}

    // type erasure implementation here

    struct callable_interface {
        callable_interface() = default;
        virtual Ret call (Args... args) = 0;
        virtual ~callable_interface() = default;
    };

    template <typename U>
    struct actual_callable: public callable_interface {
        actual_callable(U calla):callable{std::move(calla)}{}
        Ret call(Args... args) {
            return callable(args...);
        }

        U callable;


    };

    Ret operator () (Args... args) {
        return ptr->call(args...);
    }
    std::unique_ptr<callable_interface>ptr;



};









int foo(int x , int y) {
    return x + y;
}
int main() {
    int xd;
    auto c = [](){};
    // stateless lambdas
    std::function<int(int, int)> f = foo;
    int res = f(2, 5);
    std::cout << res << '\n';
    custom_function<int(int, int)> f2{foo};
}
