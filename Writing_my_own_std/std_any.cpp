#include <iostream>
#include <coroutine>
#include <assert.h>
#include <memory>


// for coroutines, what we need is to define a promise type, and the type of the coroutine handle.
// std::any
// std::variant
// std::threadpool



#include <iostream>
#include <memory>
#include <utility>

namespace MySpace {

    class any {
    public:
        // Constructor accepting any type
        any() {

        }

        template <typename T>
        any(T&& t_) {
            ptr_ = std::make_unique<child<std::decay_t<T>>>(std::forward<T>(t_));
        }

        // In-place constructor for constructing the contained object directly
        template <typename T, typename... Args>
        any(std::in_place_type_t<T>, Args&&... args) {
            ptr_ = std::make_unique<child<T>>(std::forward<Args>(args)...);
        }

        // copy constructor
        any(any& other) {
            ptr_ = other.ptr_->clone();
        }

        // constructor for when
        template <typename T, typename... Args>
        void emplace(Args&&... args) {
            ptr_ = std::make_unique<child<T>>(std::forward<Args>(args)...);
        }

        bool has_value() const noexcept {
            return !(ptr_==nullptr);
        }

        std::type_info const& type() {
            return ptr_->type();
        }

    private:
        struct base {
            virtual ~base() = default;
            base() = default;
            virtual std::unique_ptr<base> clone() = 0;
            virtual std::type_info const& type() = 0;
        };

        template <typename T>
        struct child : public base {
            template <typename U>
            child(U&& t) : t_(std::forward<U>(t)) {}

            std::unique_ptr<base> clone() override {
                return std::make_unique<child<T>>(t_);
            }

            std::type_info const& type() override {
                return typeid(T);
            }

            T t_; // the actual data we have.
        };

        std::unique_ptr<base> ptr_;

        template <typename T, typename... Args>
        friend any make_any(Args&&... args);
    };


    // API to create an any type
    template <typename T, typename... Args>
    any make_any(Args&&... args) {
        return any(std::in_place_type<T>, std::forward<Args>(args)...);
    }

} // namespace MySpace

int main() {
    MySpace::any v(20);
    MySpace::any v3{std::in_place_type<long long>, 20};
    MySpace::any v2;
    if (!v2.has_value()) {
        std::cout << "v2 has no value!\n";
    }
    assert(v.type() == typeid(int));
    assert(v3.type() == typeid(long long));

    MySpace::any v4;
    v4.emplace<std::string>(std::string("Hello world!\n"));


    auto any_str = MySpace::make_any<std::string>("Hello, World!");

    return 0;
}
