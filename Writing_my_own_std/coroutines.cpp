#include <coroutine>
#include <exception>
#include <iostream>
#include <string>

// C++ 23 provides a generator <ReturnType>
// C++ 20 provides a coroutine handle 

namespace MySpace {

    template <typename T>
    class CoroTask {
    public:
        // dont copy
        CoroTask(CoroTask const&) = delete;
        CoroTask& operator = (CoroTask const&) = delete;
        struct promise_type {
            T return_result{};
            int yield_storage = 0;
            CoroTask get_return_object() {
                return CoroTask{CoroHdl::from_promise(*this)};
            }
            std::suspend_always initial_suspend() {
                return std::suspend_always{};
            }
            std::suspend_always final_suspend() noexcept {
                return std::suspend_always{};
            }
            void unhandled_exception() {
                std::terminate();
            }
            // void return_void() {
            //     return;
            // }
            std::suspend_always yield_value(int a) {
                yield_storage = a;
                return std::suspend_always{};
            }

            void return_value(T const& value) {
                return_result = value;
            }
        };
        using CoroHdl = std::coroutine_handle<promise_type>;

        CoroHdl hdl_;
    public:
        CoroTask(CoroHdl h): hdl_{h}{}
        ~CoroTask() {
            if (hdl_) hdl_.destroy();
        }

        bool resume() {
            if (!hdl_ || hdl_.done()) return false;
            hdl_.resume();
            return !hdl_.done();
        }
        int getValue() const {
            return hdl_.promise().yield_storage;
        }

        T getResult() const {
            return hdl_.promise().return_result;
        }
    };

}

MySpace::CoroTask<std::string> generator(int a) {

    for (int i = 0; i < a; ++i) {
        std::cout << "Print " << i << '\n';
        co_yield i;
    }

    co_return std::string("hello world!\n");
}

int main() {
    auto coro = generator(10);
    while (coro.resume()) {
        std::cout << "Yielded_value is " << coro.getValue() << '\n';
    }
    std::cout << coro.getResult() << '\n';



    return 0;
}