#include <bits/stdc++.h>


namespace std {
    struct suspend_always {
        constexpr bool await_ready() const noexcept{ return false;}
        constexpr void await_suspend(std::coroutine_handle<>) const noexcept {}
        constexpr void await_resume() const noexcept {}
    };

    struct suspend_never {
        constexpr bool await_ready() const noexcept{return true;}
        constexpr void await_suspend(std::coroutine_handle<>) const noexcept {}
        constexpr void await_resume() const noexcept {}
    };
}

int main() {
    std::cout <<"HELLOWORLD!\n";


    return 0;

}
