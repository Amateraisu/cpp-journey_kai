// study unique ptr then go and study templates.
#include <bits/stdc++.h>

//  the basis of unqiue ptr is to demonstrate RAII properties. 
// so.... 
template <typename T>
struct Unique_ptr {
    Unique_ptr():ptr{nullptr}{}
    ~Unique_ptr() {
        delete ptr;
        ptr = nullptr;
    }
    Unique_ptr(T* other):ptr{other}{};
    Unique_ptr(const Unique_ptr<T>& other) = delete;
    Unique_ptr(Unique_ptr<T>&& other) {
        ptr = other.ptr;
        delete other.ptr;
        other.ptr = nullptr;
    }
    Unique_ptr& operator = (const Unique_ptr<T>& other) = delete;

    Unique_ptr& operator = (Unique_ptr<T>&& other) {
        if (this != other) {
            ptr = other.ptr;
            delete other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
private:
    T* ptr;

};

int main() {
    std::unique_ptr<int>base;
    std::unique_ptr<int>ptr{new int(5)};
    std::unique_ptr<int>ptr2(new int(10));
    ptr2 = std::move(ptr);
    std::cout << *ptr2 << '\n';
    Unique_ptr<int>ptr_mine(new int(11));

}