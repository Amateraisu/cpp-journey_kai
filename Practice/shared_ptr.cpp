#include <bits/stdc++.h>

template <typename T>
struct my_shared_ptr {
    // helper function to increment
    void increment() {
        if (cnt_ptr == nullptr) cnt_ptr = new int(0);
        ++(*cnt_ptr);
    }
    void decrement() {
        if (cnt_ptr == nullptr) return;
        if (*cnt_ptr > 0) --(*cnt_ptr);
        if (*cnt_ptr == 0) delete ptr;
    }
    my_shared_ptr():cnt_ptr{nullptr}, ptr{nullptr}{}
    my_shared_ptr(T* ptr_):ptr{ptr_}, cnt_ptr{new int(0)} {}
    my_shared_ptr(my_shared_ptr<T>& other) {
        cnt_ptr = other.cnt_ptr;
        ptr = other.ptr;
        increment();
        if (other->cnt_ptr == nullptr) {other.cnt_ptr = cnt_ptr;}
    }
    my_shared_ptr& operator = (T& other) {
        if (this != &other) {
            decrement();
            cnt_ptr = other.cnt_ptr;
            ptr = other.ptr;
            increment();
        }

        return *this;
    }



private:
    int* cnt_ptr;
    T* ptr;
};


int main() {
    std::shared_ptr<int>ptr = std::make_shared<int>(5);
    std::shared_ptr<int>ptr2 = ptr;
    std::cout << "used count " << ptr2.use_count() << '\n';
    std::cout << "ORIGINAL COUNT SHOULD BE THE SAME " << ptr.use_count() << '\n';
    my_shared_ptr<int>kai_ptr(new int(5));
}
