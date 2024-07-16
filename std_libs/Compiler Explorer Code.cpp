#include <iostream>
#include <assert.h>

namespace Impl {
    template <typename... T>
    struct helper;
    
    template <typename T, typename... Ts>
    struct helper<T, T, Ts...>{
        constexpr static int value = 0;
    };

    template <typename T, typename U, typename... Ts>
    struct helper<T, U, Ts...>{
        constexpr static int value = 1 + helper<T, Ts...>::value;
    };

    template <typename T>
    struct helper<T> {
        constexpr static int value = -1e5;
    };

    template <typename T, typename... Alternatives>
    union recursive_union{
        T t_;
        recursive_union<Alternatives...>rest;

        template <typename U>
        recursive_union(std::integral_constant<int, 0>, U&& u): t_(std::forward<U>(u)){}

        template <int I, typename U>
        recursive_union(std::integral_constant<int, I>, U&& u): rest(std::integral_constant<int, I - 1>{}, std::forward<U>(u)){}

        ~recursive_union() {}

        template <std::size_t I>
        auto& get() {
            if constexpr (I == 0) {
                return t_;
            } else {
                return rest.template get<I - 1>();
            }
        }

    };


    // base case
    template <typename T>
    union recursive_union<T> {
        T t_;
        int index_;
        template <typename U>
        recursive_union(std::integral_constant<int, 0>, U&& u): t_{std::forward<decltype(u)>(u)}{}

        ~recursive_union() {}

        template <std::size_t I>
        auto& get() {
            return t_;
        }

    };




}


namespace mySpace {

    template <typename... Alternatives>
    class variant {
        private:
        int index_;
        Impl::recursive_union<Alternatives...>storage_;
        public:
        template <typename T>
        variant(T&& t): index_(Impl::helper<T, Alternatives...>::value),
        storage_(std::integral_constant<int, Impl::helper<T, Alternatives...>::value>{}, t){
            assert(index_ >= 0);
        }

        template <int I>
        auto& get() {
            return storage_.template get<I>();
        }



    };
}


int main() {
    std::cout << "I love C++!\n";
    mySpace::variant<int, short, long long>var(1LL);
    mySpace::variant<int, short, long long, std::string>v2(std::string("I hate scrolling tiktok"));
    std::cout << v2.get<3>() << '\n';
    mySpace::variant<double, float, long, int, size_t>v3(32);
    static_assert(sizeof(decltype(v3)) == 16);

    return 0;
}