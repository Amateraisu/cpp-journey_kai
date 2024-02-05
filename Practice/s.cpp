#include <bits/stdc++.h>
#include <cerrno>

// revision on lambdas 

struct myClass {
    myClass():myNum{0}{}
    void operator () () {
        std::cout << "myNum is " << this->myNum << '\n';
    }
private:
    const int myNum;
};

// 
int foo(int x) {

    std::cout << "this number " << x << " is passed to foo!\n";
    return 0;
}


// functors are basically type erasure in another method. 

template <typename T>
struct custom_functor;

template <typename ret, typename ... args>
struct custom_functor<ret(args...)> {
    custom_functor(ret (*f)(args...)):ptr{std::make_unique<child<decltype(f)>>(f)}{}
    struct base {
        base() = default;
        virtual ret call(args&&... arg) = 0;
        virtual ~base() = default;
    };
    template <typename T>
    struct child: public base {
        child(T arguement):obj{std::move(arguement)}{}
        ret call(args&&... arg) override {
            return obj(std::forward<args>(arg)...);
        }
        T obj;
    };
    ret operator() (args... arg) {
        return ptr->call(arg...);
    }

private:
    std::unique_ptr<base>ptr;
};



int main() {
    // lambdas are basically functors, and functors are objects overloaded with ()

    auto c = [myNum = 0]() mutable {
        std::cout << "myNum is " << myNum << '\n';
        ++myNum;
    };
    c();
    c();
    std::function<int(int)>f = foo;
    custom_functor<int(int)> f2 = foo;

    return 0;

}