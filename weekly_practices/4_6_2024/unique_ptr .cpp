#include <cassert>
#include <utility> // For std::move
#include <bits/stdc++.h>

template <typename T, typename T2>
struct MyUniquePtr;

template <typename T, typename T2 = std::function<void(T*)>>
struct MyUniquePtr {
    MyUniquePtr(T* ptr = nullptr):ptr_(ptr){}
    MyUniquePtr(MyUniquePtr<T>& other) = delete;
    MyUniquePtr operator = (MyUniquePtr const& other) = delete;
    MyUniquePtr(MyUniquePtr<T>&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    void operator = (MyUniquePtr<T>&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    T& operator * () {
        return *ptr_;
    }

    T* get() {return ptr_;}

    void reset(T* ptr) {

        delete ptr_;
        ptr_ = ptr;
    }

    T* operator -> () {
        return ptr_;
    }

    ~MyUniquePtr() {
        if (ptr_ != nullptr) ptr_ =nullptr;
        delete ptr_;
        ptr_ = nullptr;
    }

private:
    T* ptr_;
};



void testMyUniquePtr() {
    // Test 1: Basic Ownership and Dereference
    static_assert(!std::is_copy_constructible<MyUniquePtr<int>>::value, "MyUniquePtr should not be copy constructible.");
    static_assert(!std::is_copy_assignable<MyUniquePtr<int>>::value, "MyUniquePtr should not be copy assignable.");
    {
        auto ptr = MyUniquePtr<int>(new int(10));
        assert(*ptr == 10);
    } // ptr goes out of scope here, should delete the managed object

    // Test 2: Move Semantics and Ownership Transfer
    {
        auto ptr1 = MyUniquePtr<int>(new int(20));
        auto ptr2 = std::move(ptr1); // Transfer ownership from ptr1 to ptr2
        assert(ptr1.get() == nullptr); // After move, ptr1 should not own the object
        assert(*ptr2 == 20); // ptr2 now owns the object
    } // ptr2 goes out of scope here, should delete the managed object

    // Test 3: Reset and Resource Release
    {
        auto ptr = MyUniquePtr<int>(new int(30));
        ptr.reset(new int(40)); // Replace managed object with a new one
        assert(*ptr == 40); // Verify the managed object is the new one
    } // The original int(30) should be deleted upon reset, and int(40) deleted here

    // Test 4: Custom Deleter (if applicable)
//    bool deleted = false;
//    {
//        auto deleter = [&deleted](int* ptr) { delete ptr; ptr= nullptr; deleted = true; }; // it takes in a callable
//        auto ptr = MyUniquePtr<int, decltype(deleter)>(new int(50), deleter);
//    }
//    assert(deleted == true); // Verify the custom deleter was called

    // Test 5: Arrow Operator and Object Access
    struct TestStruct {
        int value() { return 55; }
    };
    {
        auto ptr = MyUniquePtr<TestStruct>(new TestStruct());
        assert(ptr->value() == 55); // Verify access to member functions
    } // TestStruct object should be deleted here.
}

int main() {
    testMyUniquePtr();
    std::cout << "All assert statements passed!\n";
    return 0;
}

