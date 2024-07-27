#include <iostream>
#include <functional>
#include <memory>



namespace MySpace {

    template <typename T>
    class function;

    template <typename ReturnType, typename... Args>
    class function<ReturnType(Args...)> {
    private:
        struct base {
            base() = default;
            virtual ~base() = default;
            virtual ReturnType call(Args... args) = 0;
        };

        template<typename T>
        struct child: public base {
            child(T t):t_{std::move(t)} {
            }
            ReturnType call(Args... args) {
                return t_(args...);
            }
            T t_;
        };
        std::unique_ptr<base>ptr_;

    public:

        function(ReturnType(*f)(Args...)):ptr_{std::make_unique<child<decltype(f)>>(f)}{
        }

        template <typename T>
        function(T t):ptr_{std::make_unique<child<T>>(t)}{

        }

        ReturnType operator () (Args... args) {
            return ptr_->call(args...);
        }
    };




}
struct A {

    bool operator () (int a) {
        std::cout << "operator () overload is called!\n";
        return true;
    }

    static bool dummy(int b) {
        std::cout << "static fnction is called!\n";
        std::cout << "b is " << b << '\n';
        return true;
    }
};

bool get(int a) {
    std::cout << "In get " << a << '\n';
    return true;
}


int main() {
    // a form of type erasure, basically we abstract away all details except the function signature and its return type
    // works with structs ,static memeber functions
    A a;
    std::function<bool(int)>f = a;
    f(25);
    f = &A::dummy;
    f(30);
    // works with lambdas
    f = [](int c ) -> bool {
        std::cout << "lambda passed in " << c << '\n';

        return true;
    };
    f(40);
    MySpace::function<bool(int)>myF = get;
    myF(25);
    myF = a;
    myF(30);
    myF = &A::dummy;
    myF(40);





    return 0;
}
