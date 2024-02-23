#include <bits/stdc++.h>
#include <typeinfo>




template <typename T>
struct my_func;



template <typename... args, typename ret>
struct my_func<ret(args...)> {
    my_func(ret (*f)(args...)): ptr{std::make_unique<child<decltype(f)>>(f)} {}



    ret operator () (args... arg) {
        return ptr->call(arg...);
    }
private:
    struct base {
        base() = default;
        virtual ~base() = default;
        virtual ret call(args... Args) = 0;
    };


    template <typename callable>
    struct child : base {
        child(callable calla):actual_call{std::move(calla)}{}
        virtual ~child() {}
        ret call(args... Args) override {
            return actual_call(Args...);
        }

        callable actual_call;
    };

    std::unique_ptr<base>ptr;
} ;



int foo(int x) { return x;}


int main() {
    std::function<int(int)> f = foo;
    std::cout << f(10) << '\n';
    my_func<int(int)> f2 = foo;
    assert(f2(10) == f(10));
    std::cout << "all assertions passed!\n";
}