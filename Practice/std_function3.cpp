#include <bits/stdc++.h>


template <typename T>
struct my_std_function;

template <typename ... args, typename ret>
struct my_std_function<ret(args...)> {
    my_std_function(ret (*ptr)(args...)):f(std::make_unique<child<decltype(ptr)>>(ptr)){}
    struct base {
        base() = default;
        virtual ret call(args... args1) = 0;
        virtual ~base() = default;
    };
    template <typename callable>
    struct child: public base {
        child(callable calla):callable_{std::move(calla)}{}
        ret call(args... arguements) override {
            return callable_(arguements...);
        }

        callable callable_;
    };

    ret operator () (args... arguement) {

        return f->call(arguement...);
    }


    std::unique_ptr<base>f; // this is what we are actually going to use to call
};


int foo(int x, int y) {return x + y;}

int main() {
    std::function<int(int, int)>f = foo;
    my_std_function<int(int ,int)>f2 = foo;
}
