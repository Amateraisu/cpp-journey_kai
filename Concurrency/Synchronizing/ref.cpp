#include <cassert>
#include <utility> // For std::move
#include <bits/stdc++.h>

template <typename T>
struct MyRef {
    MyRef(T& obj): ptr_(obj) {}

    MyRef& operator = (const MyRef<T>& other) {
        if (this != other) {
            ptr_ = other.ptr_;
        }
        return *this;
    }

    operator T& () const {
        return *ptr_;
    }


private:
    T& ptr_;

};

template<typename T>
void accept_reference(T&);

template <typename T>
void accept_copy(T);

int main() {
    static_assert(std::is_copy_constructible<MyRef<int>>::value, "MyRef should be copy constructible");
    static_assert(std::is_copy_assignable<MyRef<int>>::value, "MyRef should be copy assignable");

//
    static_assert(std::is_invocable_r<void, decltype(accept_reference<int>), MyRef<int>&>::value,
                  "MyRef<int>& should be convertible to int&");
    static_assert(std::is_invocable_r<void, decltype(accept_reference<const int>), const MyRef<int>&>::value,
                  "const MyRef<int>& should be convertible to const int&");
    int a = 10;
    MyRef<int> ref_a(a);
    a = 20;
    auto f = std::ref(a);
    std::cout << "All tests have passed!\n";

}

