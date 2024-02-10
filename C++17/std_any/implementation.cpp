#include <iostream>
#include <bits/stdc++.h>

// maybe I can start with a naive implmeentation



//struct cus_any {
//    template <typename T>
//    explicit cus_any(T&& obj):data_{new T{std::forward<T>(obj)}}, info_{typeid(T)}{}
//    // but what is T here? we dont remember the type of it and we need to find a way to remember it
////    cus_any(cus_any& obj):info_{obj_info}, data_{new T{}}
//    void* data_;
//    const std::type_info& info_;
//};
//
//// if the type info doesnt match , just throw an error
//template <typename T>
//T& cust_any_cast(cus_any& obj) {
//    if (typeid(T) == obj.info_) {
//        return *static_cast<T*>(obj.data_);
//    }
//    throw std::bad_any_cast();
//}

// but this one , how do we uhm, copy?
// so we need to:
// 1. remember the type
// 2. have a copy constructor
// 3. have a destructor


struct cust_any {
    void* data_;
    void* (*clone_)(void* otherData);
    void (*del)(void* data);
    const std::type_info& (*info_)();

    template <typename T>
    explicit cust_any(T&& obj):data_{new T{std::forward<T>(obj)}}, clone_([](void* data) -> void* {return new T{*static_cast<T*>(data)};}), del([](void* data){delete data;}){}

    cust_any(const cust_any& other):data_{other.clone_(other.data_)}, clone_{other.clone_}, del{other.del}, info_{other.info_}{}

};



int main() {
    std::any a = 10;
    std::any b = a;
    cust_any c{10};
    cust_any d = c;
    // but, this does not work cus_any d = c;
    // there is no copy constructors....
//    cus_any d = c;
//    std::cout << cust_any_cast<int>(d) << '\n';





}







int main() {
     any a(50);
     // but this naive implementation cannot handle copy constructors and will result in a double delete.
     any b = a; // this is doomed.
    return 0;
}