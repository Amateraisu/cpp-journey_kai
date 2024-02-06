#include <iostream>
#include <bits/stdc++.h>


// naive implementation




struct custom_any {
    template <typename T>
    custom_any(T&& obj):t{typeid(T)},obj{new T(std::forward<T>(obj))}{}
    const std::type_info& t;
    void* obj;
};

template <typename T>
T& custom_any_cast(custom_any& obj) {
    if (typeid(T) == obj.t) {
        return *static_cast<T*>(obj.obj);
    }
    throw std::bad_any_cast{};
};


namespace actual_cast {
    // well the key here is that we can actually use lambdas or functiion ptrs to keep track
    struct custom_any {
        template <typename T>
        custom_any(T&& obj):data_{new T{std::forward<T>(obj)}}, getType{[](){return typeid(T);}}, clone_{[](void* obj){return *static_cast<T*>(obj);}}{}
    private:
        void* data_;
        std::type_info const& (*getType)();
        void (*clone_)(void* obj);
    };





}




int main() {
    std::cout << "Hello, World!" << std::endl;
    std::any b = "hello world!\n";
    std::any a = 5;
    a = b;
    std::cout << std::any_cast<const char*>(a) << '\n';
    custom_any c = 5;
    // copy constructors will not work because it will only create a shared pointer to the same object.
    // but how do I find out the type of the new copy constructor ? because I cant go from typeid to type ....
    std::cout << custom_any_cast<int>(c) << '\n';
    return 0;
}
