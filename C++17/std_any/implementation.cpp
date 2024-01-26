// naive implementation of std::any 
#include <bits/stdc++.h>
// struct any {
//   template <typename T>
//   explicit any(T&& val):type_{typeid(T)}, data_{new T{std::forward<T>(val)}}{}

//   const std::type_info& type_;
//   void* data_; 
// };

// template <typename T>
// T& any_cast(any& val) {
//     if (typeid(T) == val.type_) {
//       return static_cast<T*>(val);
//     }

//     throw std::bad_any_cast();
//   }
// the trick is to use lambdas 

struct any {
    void* data_;
    const std::type_info& (*getType_)();
    void* (*clone_)(void* otherData);
    void (*destroy_) (void* data);

    template <typename T>
    explicit any(T&& value):data_(new T{std::forward<T>(value)}), getType_{[]()->std::type_info const& {return typeid(T);}}, clone_([](void* otherData) -> void* {return new T(*static_cast<T*>(otherData));}), destroy_([](void* data_){ delete static_cast<T*>(data_);}){}

    any(any const& other)
            : data_(other.clone_(other.data_))
            , getType_(other.getType_)
            , clone_(other.clone_)
            , destroy_(other.destroy_)
    {
    }

    ~any()
    {
        destroy_(data_);
    }

};






int main() {
    // any a(50);
    // // but this naive implementation cannot handle copy constructors and will result in a double delete.
    // any b = a; // this is doomed.
    return 0;
}