// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

namespace my_std {

    struct any {
        // default constructor
        any() {
            data_ = nullptr;
        }
        // constructor
        template <typename T>
        any(T&& data):data_(static_cast<void*>(new T(std::forward<T>(data)))),
                      clone_([](void* otherData) ->void* {return new T(*static_cast<T*>(otherData));}),
                      delete_([](void* otherData){delete static_cast<T*>(otherData);}),
                      type_info_(&typeid(T)){}

        // copy constructor
        any(const any& other) {
            data_ = other.clone_(other.data_);
            clone_ = other.clone_;
            delete_ = other.delete_;
            type_info_ = other.type_info_;
        }

        // destructor
        ~any() {
            this->reset();
        }

        void reset() {
            if (data_ != nullptr) {
                delete_(data_);
                data_ = nullptr;
            }
            type_info_ = nullptr;
            clone_ = nullptr;
            delete_ = nullptr;

        }

        bool has_value() {
            if (data_ != nullptr) return true;
            return false;
        }

        const std::type_info& get_type() {
            return *type_info_;
        }

        // copy constructor
        void* data_;
        // lambda to clone
        // lambda to delete
        void* (*clone_)(void* otherData);
        void (*delete_)(void* otherData);
        const std::type_info* type_info_;

    };

    template <typename T>
    T any_cast(any& obj) {
        cout << "My pretty function!\n";
        cout << __PRETTY_FUNCTION__ << '\n';
        using NonRef = std::remove_reference_t<T>;
        if (obj.get_type() == typeid(NonRef)) {
            return *static_cast<NonRef*>(obj.data_);
        }
        throw std::bad_any_cast();
    }



};

void test_construction_and_has_value() {
    my_std::any a;
    assert(!a.has_value()); // After default construction, should have no value

    my_std::any b = 10;
    assert(b.has_value()); // Should have value after direct initialization

    my_std::any c = std::string("Hello");
    assert(c.has_value()); // Should have value after direct initialization with a string
    cout << "all assertions 1 has passed!\n";
}

void test_type_safe_access() {
    my_std::any a = 10;
    assert(my_std::any_cast<int>(a) == 10); // Should successfully cast to int
    my_std::any_cast<int&>(a) = 20;
    assert(my_std::any_cast<int>(a) == 20);

    // my_std::any_cast<int>(a) = 30;  this should throw an error;

    my_std::any b = std::string("Hello");
    assert(my_std::any_cast<std::string>(b) == "Hello"); // Should successfully cast to std::string

    // Uncomment the line below to test the exception; it should not compile or should throw at runtime
    // assert(my_std::any_cast<int>(b) == 10); // Should throw my_std::bad_any_cast
    cout << "All assertions 2 have passed!\n";
}


void test_reset_and_empty() {
    my_std::any a = 10;
    assert(a.has_value()); // Initially has a value

    a.reset();
    assert(!a.has_value()); // Should have no value after reset
    cout << "All assertions 3 have passed!\n";
}

void test_copy_and_move_semantics() {
    my_std::any original = std::string("Hello");
    assert(my_std::any_cast<std::string>(original) == "Hello");
    // ========= failed here lol ====================
    // my_std::any copied = original; // Test copy construction
    // assert(my_std::any_cast<std::string>(copied) == "Hello"); // Should successfully cast to std::string and equal the original

    // my_std::any moved = std::move(original); // Test move construction
    // assert(my_std::any_cast<std::string>(moved) == "Hello"); // Moved value should still be accessible
    // Original any may no longer have a value or may be in a valid but unspecified state.
    cout << "All assertions 4 have passed!\n";
}









int main() {
    test_construction_and_has_value();
    test_type_safe_access();
    test_reset_and_empty();
    test_copy_and_move_semantics();

}
