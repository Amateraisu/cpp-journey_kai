#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct sharedptr {
    sharedptr():count(new int(0)), res(nullptr) {}
    sharedptr(T* other) {
        res = other;
        count = new int(0);
        increment();
    }
    sharedptr(sharedptr<T>& other) {
        if (other.res == nullptr) return;
        res = other.res;
        count = other.count;
        increment();
    }
    sharedptr(sharedptr<T>&& other) {
        if (other.res == nullptr) return;
        res = other.res;
        count = other.count;
        other.res = nullptr;
        other.count = nullptr;
    }

    sharedptr<T>& operator = (sharedptr<T>& other) {
        if (this == &other) return *this;
        res = other.res;
        count = other.count;
        increment();
        return *this;
    }

    ~sharedptr() {
        decrement();
    }

    void reset(T* other = nullptr) {
        if (other != nullptr) {
            decrement();
            res = other;
            increment();
        } else {
            decrement();
            res = nullptr;
            count = nullptr;
        }


    }
    int get_count() {
        if (count == nullptr) return 0;
        return (*count);
    }
    T& operator * () {
        return *res;
    }

private:

    void increment() {
        if (count == nullptr) count = new int(0);
        (*count)++;
    }
    void decrement() {
        if (count == nullptr) return;
        (*count)--;
        if (*count == 0) {
            delete res;
            delete count;
            res = nullptr;
            count = nullptr;
        }
    }
    int* count;
    T* res;

};



int main() {
    sharedptr<int>ptr1(new int(20));
    sharedptr<int>ptr2 = ptr1;
//     sharedptr<int>ptr2(new int(10));
//     sharedptr<int>ptr3(ptr2);

//     ptr3 = ptr2;
//     sharedptr<int>ptr4(std::move(ptr1));
    cout << ptr2.get_count() << '\n';
    ptr1.reset();
    cout << ptr2.get_count() << '\n';
    cout << ptr1.get_count() << '\n';
    ptr1.reset(new int(5));
    std::cout << *ptr1 << '\n';
// //    ptr1->func();
// //
// //    ptr1.get();
    cout << ptr1.get_count()<< '\n';
}
