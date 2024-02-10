#include <iostream>
#include <bits/stdc++.h>



int foo(int x) {
    return x;
}

template <typename T>
struct my_function;

template <typename Ret, typename ... Args>
struct my_function<Ret(Args...)> {
    my_function(Ret(*f)(Args...)):ptr{std::make_unique<child<decltype(f)>>(f)}{}
    struct base {
        base() = default;
        virtual ~base() = default;
        virtual Ret call(Args...) = 0;
    };
    template <typename T>
    struct child: public base {
        child(T f):callable{std::move(f)}{}
        ~child() = default;
        Ret call(Args... args) override {
            return callable(args...);
        }

        T callable;
    };
    Ret operator () (Args... args) {
        return ptr->call(args...);
    }



    std::unique_ptr<base>ptr;
};



int main() {
//    auto r = [](auto&& this, int x) {
//        if (x == 0) return 1;
//        return x * self(self, x - 1);
//    };
//    std::cout << r(r, 10) << '\n';
    int(*f)(int) = foo;
    f(5);
    std::function<int(int)>f2 = foo;
    f2(10);
    int(*f3)(int) = +[](int x) {return x;}; // it implicitely converts itself into a function pointer. // explicit
    auto* f5 = +[](int x) {return x;};
    my_function<int(int)> f6{foo};
    std::cout << f6(10) << '\n';



}