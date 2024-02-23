#include <bits/stdc++.h>

template <typename T>
struct MyUniquePtr{
    MyUniquePtr(T* ptr = nullptr):ptr_{ptr}{} // parameterised constructor
    ~MyUniquePtr() {
        delete ptr_;
        ptr_ = nullptr;
    }
    MyUniquePtr(MyUniquePtr<T>&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    MyUniquePtr& operator = (MyUniquePtr<T>&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    T& operator * () {
        return *ptr_;
    }

    T* get() {
        return ptr_;
    }

    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    T* release() {
        auto t = ptr_;
        ptr_ = nullptr;
        return t;


    }




private:
    T* ptr_;
};






int main() {

//    MyUniquePtr<int> ptr(new int(10));
//    assert(*ptr == 10); // Check value
//    assert(ptr.get() != nullptr); // Check pointer is not null
//    MyUniquePtr<int> ptr1(new int(10));
//    MyUniquePtr<int> ptr2 = std::move(ptr1); // Move constructor
//
//    assert(ptr1.get() == nullptr); // ptr1 should be null after move
//    assert(*ptr2 == 10); // ptr2 now owns the resource
//
//    MyUniquePtr<int> ptr3(new int(20));
//    ptr3 = std::move(ptr2); // Move assignment
//
//    assert(ptr2.get() == nullptr); // ptr2 should be null after move
//    assert(*ptr3 == 10); // ptr3 now owns the resource
//    auto rawPtr = new int(10);
//    {
//        MyUniquePtr<int> ptr(rawPtr);
//    } // ptr goes out of scope here, and should delete the managed object

    // No direct way to assert the object has been deleted in standard C++,
    // but you can use tools like Valgrind or custom deleters to verify.

//    bool deleted = false;
//    {
//        MyUniquePtr<int, std::function<void(int*)>> ptr(new int(10), [&deleted](int* p) {
//            delete p;
//            deleted = true;
//        });
//
//        assert(*ptr == 10);
//    }
//    assert(deleted == true); // Verify custom deleter was called

    MyUniquePtr<int> ptr2(new int(10));
    assert(*ptr2 == 10); // Dereference operator
    assert(ptr2.get() != nullptr); // get method
    int* rawPtr2 = ptr2.release(); // release method

    assert(ptr2.get() == nullptr); // ptr should no longer own the object
    assert(*rawPtr2 == 10); // rawPtr now owns the object
    delete rawPtr2; // Clean up

    ptr2.reset(new int(20)); // reset method
    assert(*ptr2 == 20);
    MyUniquePtr<int> ptr3; // Default constructor
    assert(ptr3.get() == nullptr); // Should be initialized to nullptr

    ptr3.reset(new int(30)); // Assign a new resource
    assert(*ptr3 == 30);

    ptr3.reset(); // Reset without a new resource
    assert(ptr3.get() == nullptr); // Should be back to nullptr
}
