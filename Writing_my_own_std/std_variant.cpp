#include <iostream>
#include <assert.h>
#include <variant>

namespace Impl {

    template <typename... T>
    struct helper;

    template <typename T>
    struct helper<T> {
        constexpr static int value = -1e4;
    };

    template <typename T, typename U, typename... Ts>
    struct helper<T, U, Ts...> {
        constexpr static int value = 1 + helper<T, Ts...>::value;
    };

    template <typename T, typename... Ts>
    struct helper<T, T, Ts...> {
        constexpr static int value = 0;
    };

    template <typename T, typename... Ts>
    union recursive_union {
        T t_; // the current value
        union recursive_union<Ts...> rest_;

        template <typename U>
        recursive_union(std::integral_constant<int, 0>, U&& u):
                t_{std::forward<U>(u)} {}

        template <typename U, int I>
        recursive_union(std::integral_constant<int, I>, U&& u):
                rest_(std::integral_constant<int, I - 1>{}, std::forward<U>(u)){
            assert(I >= -10);
        }

        ~recursive_union() {

        }

        template <int I>
        auto& get() {
            if constexpr (I == 0) {
                return t_;
            } else {
                return rest_.template get<I - 1>();
            }
        }
    };

    // for when there are no types left
    template <typename T>
    union recursive_union<T> {
        T t_; // the current value

        template <typename U>
        recursive_union(std::integral_constant<int, 0>, U&& u):
                t_{std::forward<U>(u)} {}

        ~recursive_union() {

        }

        template <int I>
        auto& get() {
            return t_;
        }
    };



}

namespace MySpace {

    template <typename... Alts>
    class variant {
    private:
        Impl::recursive_union<Alts...>storage_;
        int index_ = -1;
    public:
        template <typename T>
        variant(T&& t_):index_(Impl::helper<T, Alts...>::value),
                        storage_(std::integral_constant<int, Impl::helper<T, Alts...>::value>{}, std::forward<T>(t_)){
            assert(index_ >= 0);
        }

        ~variant() {

        }

        template <int I>
        auto& get() {
            return storage_.template get<I>();
        }

        template <typename T>
        auto& get() {

            return storage_.template get<Impl::helper<T, Alts...>::value>();
        }

        int index() const noexcept {
            return index_;
        }


    };
}


int main() {
    //std::variant.
    // the point with std::any is that we know the type at compile time.
    // the main function methods are:
    // typename T get<T>()
    // int I get<I>()
    // the main usage mostly is with visit
    // the main trick is a thing called a recursive union
    MySpace::variant<int, long long, short>v(20);
    std::cout << v.index() << '\n';
    MySpace::variant<int, long long, short>v2(1LL);
    std::cout << v2.index() << '\n';
    MySpace::variant<int, long long, short, std::string>v3(std::string("HELLO"));
    std::cout << v3.index() << '\n';
    std::cout << v3.get<3>() << '\n';
    std::cout << v3.get<std::string>() << '\n';
    // MySpace::variant<int>v4(1LL);

    // std::variant<int, short>v(std::string("Hello"));

    return 0;
}
