#include <bits/stdc++.h>
#include <typeinfo>


struct my_any{
    template<typename T>
    explicit my_any(T&& val):
            info{typeid(T)},
            clone{[](void* otherData) ->void* {return new T{*static_cast<T*>(otherData)};}},
            del{[](void* data) -> void{ delete static_cast<T*>(data); data = nullptr;}},
            data{new T{val}}{}

    // they are all lambdas here
    void* (*clone)(void* otherData);
    void  (*del)(void* data);
    void* data;
    const std::type_info& info;
    const std::type_info& get_type() {
        return info;
    }
};


int main() {
    std::any a = 5;

    std::cout << std::any_cast<int>(a) << '\n';

    my_any a2{5};
    my_any a3 = a2;
    assert(a3.get_type() == typeid(int));


}