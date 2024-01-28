#include <bits/stdc++.h>



struct any {
    template <typename T>
    any(T&& value):typeInfo{typeid(T)}, ptr{new T{std::forward<T>(value)}} {}
    const std::type_info& typeInfo;
    void* ptr;
};


template <typename T>
T& std_my_any_cast(any& value) {
    if (typeid(T) != value.typeInfo) {
        throw std::bad_any_cast();
    }

    return static_cast<T>(value);
}

// actual definition //
// the trick is to use lambdas//

struct actual_any {
    void* data_;
    const std::type_info& (*getType)();
    void* (*clone)(void* otherData);
    void (*destroy)(void* data);


    template<typename T>
    explicit actual_any(T&& value):data_{new T{std::forward<T>(value)}}, getType{
            []()->const std::type_info& { return typeid(T);}}, clone{[](void* otherData)->void*{return new T{*static_cast<T*>(otherData)};}},
            destroy{[](void* data_)mutable ->void{delete static_cast<T*>(data_);}}{}

    };


int main() {
    actual_any a(50);
    actual_any b = a; // fails
}