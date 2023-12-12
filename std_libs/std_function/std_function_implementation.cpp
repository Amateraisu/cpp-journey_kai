#include <bits/stdc++.h>
template<typename T>
class func;

template <typename Ret, typename ... Params>
class func<Ret(Params...)> {
public:
    func(Ret (*f)(Params...)):callable{std::make_unique<callable_impl<decltype(f)>>(f)} {}
    Ret operator () (Params ... args) {
        return callable->call(args...);
    }

private:
    struct callable_interface {
        virtual ~callable_interface();
        virtual Ret call(Params...) = 0;
    };
    template <typename T>
    struct callable_impl : callable_interface {
        T c;
        callable_impl(T f):c{std::move(f)}{}
        Ret call(Params... args) {
            return c(args...);
        }
    };
    std::unique_ptr<callable_interface>callable;
};



int f(int x, int y) {
    return x + y;
}


int main() {
    func<int (int, int)>ptr{f};

}



